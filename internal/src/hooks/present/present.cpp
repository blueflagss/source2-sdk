#include "includes.hpp"

extern "C" {
    __declspec( dllexport ) DWORD NvOptimusEnablement = 0x00000001;
    __declspec( dllexport ) int AmdPowerXpressRequestHighPerformance = 1;
}

HRESULT __stdcall hooks::present::hook( IDXGISwapChain *swap_chain, unsigned int sync_interval, unsigned int flags )
{
    static bool init = false;

    if ( !init )
    {
        g_render.init( swap_chain );
        init = true;
    }

    auto buf = g_render.m_renderer->get_working_buffer( g_render.m_buffer_id );

    buf->push_projection( { } );

    g_visuals.run( );

    buf->pop_projection( );

    g_render.m_renderer->swap_buffers( g_render.m_buffer_id );
    g_render.m_renderer->render( );
    g_render.m_performance.tick( );

//    g_interfaces.m_device_context->OMSetRenderTargets( 1, &g_interfaces.m_render_target_view, nullptr );

    return m_hook.call_original< decltype( &hook ) >( )( swap_chain, sync_interval, flags );
}

void hooks::present::init()
{
    auto status = m_hook.create_hook( utils::get_method< void * >( g_interfaces.m_swap_chain, 8 ),
                                      reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}