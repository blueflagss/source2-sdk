#include "includes.hpp"

void render::impl::init( IDXGISwapChain* swap_chain )
{
    m_screen_size = g_interfaces.m_engine_client->get_screen_size( );
    m_renderer = std::make_unique< renderer::d3d11_renderer >( swap_chain );

    if ( !m_renderer->initialize( ) ) {
        spdlog::error( "Failed to initialize D3D11 renderer." );
        return;
    }

    m_buffer_id = m_renderer->register_buffer( );

    char font_path[ MAX_PATH ] = { };

    if ( SUCCEEDED( SHGetFolderPathA( nullptr, CSIDL_FONTS, nullptr, 0, font_path ) ) )
    {
        g_fonts.m_visual_big = m_renderer->register_font( std::string( font_path ) + '\\' + "segoeui.ttf", 8, FW_NORMAL, true );
    }
}