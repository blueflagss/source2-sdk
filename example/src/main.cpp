#include "includes.hpp"

extern "C" {
__declspec( dllexport ) DWORD NvOptimusEnablement = 0x00000001;
__declspec( dllexport ) int AmdPowerXpressRequestHighPerformance = 1;
}

std::shared_ptr< renderer::win32_window > application;
std::unique_ptr< renderer::d3d11_renderer > dx11;

renderer::sync_manager updated_draw;
renderer::sync_manager updated_buf;

bool close_requested = false;

size_t segoe_font;
renderer::performance_counter performance;

LRESULT WINAPI WndProc( HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam )
{
    static bool in_size_move = false;

    switch ( msg ) {
        case WM_PAINT:
            if ( in_size_move )
                dx11->render();
            else {
                PAINTSTRUCT ps;
                std::ignore = BeginPaint( hWnd, &ps );
                EndPaint( hWnd, &ps );
            }
        case WM_DISPLAYCHANGE:
            dx11->on_display_change();
            break;
        case WM_CLOSE:
            close_requested = true;
            return 0;
        case WM_SIZE:
            if ( !in_size_move )
                dx11->on_window_size_change( { LOWORD( lParam ), HIWORD( lParam ) } );
            break;
        case WM_MOVE:
            dx11->on_window_moved();
            break;
        case WM_ENTERSIZEMOVE:
            in_size_move = true;
            break;
        case WM_EXITSIZEMOVE:
            in_size_move = false;
            dx11->on_window_size_change( application->get_size() );
            break;
        case WM_DESTROY:
            PostQuitMessage( 0 );
            break;
        default:
            break;
    }

    return DefWindowProcA( hWnd, msg, wParam, lParam );
}
void draw_thread( )
{
    const auto id = dx11->register_buffer( );

    while ( !close_requested ) {
        updated_draw.wait( );

        auto buf = dx11->get_working_buffer( id );
        buf->push_projection( { } );


        // render.
        buf->push_font( segoe_font );
        buf->draw_text< std::string >( { 10, 10 }, "Penis", { 255, 255, 255, 255 } );
        buf->pop_font( );

        buf->pop_projection( );
        dx11->swap_buffers( id );
        updated_buf.notify( );
    }
}

int main( )
{
    application = std::make_shared< renderer::win32_window >( "XUI example window", glm::i32vec2{ 960, 500 }, WndProc );

    if ( !application->create( ) )
    {
        MessageBoxA( nullptr, "Failed to create application window.", "Error", MB_ICONERROR | MB_OK );
        return 1;
    }

    dx11 = std::make_unique< renderer::d3d11_renderer >( application );

    if ( !dx11->initialize( )  ) {
        MessageBoxA( nullptr, "Failed to initialize D3D11 renderer.", "Error", MB_ICONERROR | MB_OK );
        return 1;
    }

    dx11->set_clear_color( { 0, 0, 0 } );

    char csidl_fonts[ MAX_PATH ];
    memset( csidl_fonts, 0, MAX_PATH );
    SHGetFolderPathA( nullptr, CSIDL_FONTS, nullptr, 0, csidl_fonts );

    segoe_font = dx11->register_font( std::string( csidl_fonts ) + '\\' + "seguiemj.ttf", 32, FW_THIN, true );
    std::thread draw( draw_thread );

    application->set_visibility( true );

    MSG msg { };
    while ( !close_requested && msg.message != WM_QUIT ) {
        while ( PeekMessage( &msg, nullptr, 0U, 0U, PM_REMOVE ) ) {
            TranslateMessage( &msg );
            DispatchMessage( &msg );
        }

        if ( msg.message == WM_NULL && !IsWindow( application->get_hwnd() ) ) {
            close_requested = true;
            break;
        }

        dx11->render( );
        performance.tick( );

        updated_draw.notify( );
        updated_buf.wait( );
    }

    draw.join( );

    dx11->release( );
    dx11.reset( );

    application->destroy( );

    return 0;
}