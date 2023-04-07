#include "includes.hpp"

void __fastcall hooks::create_move::hook( void *ecx, int sequence_number, unsigned __int8 a3 )
{
    m_hook.call_original< decltype( &hook ) >( )( ecx, sequence_number, a3 );

    auto cmd = globals::cmd = g_interfaces.m_csgo_input->get_user_cmd( sequence_number );

    g_movement.run( cmd );

    if ( cmd )
    {
        if ( globals::local )
        {
            auto engine_angles = g_interfaces.m_csgo_input->get_view_angles( );

            spdlog::info( "engine angles: {}, {}, {}", engine_angles.x, engine_angles.y, engine_angles.z );
        }

    }
}

void hooks::create_move::init( )
{
    auto status = m_hook.create_hook( utils::get_method< void* >( g_interfaces.m_csgo_input, 5 ),
            reinterpret_cast< void * >( &hook ) );

    assert_hook( status );
}