#include "includes.hpp"

void __stdcall cheat_thread( )
{
    const auto start = std::chrono::high_resolution_clock::now( );

    g_console.init( );
    g_interfaces.init( );
    //g_config.init( );
    g_schema.init( );
    g_hooks.init( );

    const auto end = std::chrono::high_resolution_clock::now( );
    const auto duration = std::chrono::duration_cast< std::chrono::milliseconds >( end - start ).count( );

    spdlog::info( "Initialized in {}ms.", duration );
}

int __stdcall DllMain( HMODULE mod, unsigned long reason, void *instance )
{
    if ( reason == DLL_PROCESS_ATTACH )
    {
        const auto h = CreateThread( nullptr, 0, LPTHREAD_START_ROUTINE( cheat_thread ), mod, 0, nullptr );

        if ( !h )
            return 0;

        CloseHandle( h );
    }

    return 1;
}