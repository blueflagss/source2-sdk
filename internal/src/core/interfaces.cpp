#include "includes.hpp"

void interfaces::impl::init( )
{
    m_global_vars   = pattern::search( HASH( "client.dll" ), XOR( "48 8B 05 ? ? ? ? 48 8B D8 80 78 3D 00 75 1D 80 78 3C 00 75" ) ).resolve_rip( 3, 7 ).deref( ).get< c_global_vars_base * >( );
    m_render        = pattern::search( HASH( "rendersystemdx11.dll" ), XOR( "66 0F 7F 05 ? ? ? ? 66 0F 7F 0D ? ? ? ? 48 89 35 ? ? ? ?" ) ).resolve_rip( 4, 8 ).deref( 2 ).get< c_render_system * >( );
    m_physics_query = pattern::search( HASH( "client.dll" ), XOR( "48 8B 0D ? ? ? ? 48 8D 45 D0 48 89 44 24 ? 4C 8D 4C 24" ) ).resolve_rip( 3, 7 ).deref( ).get< c_physics_query * >( );
    m_csgo_input    = pattern::search( HASH( "client.dll" ), XOR( "48 8B 0D ? ? ? ? 48 8B 01 FF 50 18 8B DF 66 0F 1F 44 00 ? 48 8B 0D" ) ).resolve_rip( 3, 7 ).deref( ).get< c_csgo_input * >( );
    m_swap_chain    = m_render->m_swap_chain;
    m_schema_system = create_interface< c_schema_system * >( HASH( "schemasystem.dll" ), HASH( "SchemaSystem_001" ) );
    m_client        = create_interface< c_client * >( HASH( "client.dll" ), HASH( "Source2Client002" ) );
    m_engine_client = create_interface< c_engine_client * >( HASH( "engine2.dll" ), HASH( "Source2EngineToClient001" ) );
    m_mem_alloc     = *g_winapi.get_module_export< c_mem_alloc ** >( HASH( "tier0.dll" ), HASH( "g_pMemAlloc" ) );
}

template< typename T = void * >
T interfaces::impl::create_interface( const hash32_t &module_name, const hash32_t &interface_name )
{
    using interface_callback_fn = void *( __cdecl * )( );

    struct interface_reg_t {
        interface_callback_fn m_callback;
        const char *m_name;
        interface_reg_t *m_next;
    };

    auto create_interface_fn = g_winapi.get_module_export< __int64( __fastcall * )( const char *, DWORD * ) >( module_name, HASH( "CreateInterface" ) );

    if ( !create_interface_fn )
        return nullptr;

    auto interface_list = pattern( reinterpret_cast< std::uint8_t * >( create_interface_fn ) ).resolve_rip( 3,
                                              7 ).deref( ).get< interface_reg_t * >( );

    if ( interface_list )
    {
        for ( auto it = interface_list; it; it = it->m_next ) {
            if ( HASH( it->m_name ) != interface_name )
                continue;

            auto callback = reinterpret_cast< T >( it->m_callback( ) );

            spdlog::info( "Found interface {} at [{}]", it->m_name, reinterpret_cast< void * >( callback ));

            return callback;
        }
    }

    return nullptr;
}