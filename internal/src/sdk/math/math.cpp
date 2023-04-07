#include "includes.hpp"

void math::impl::init( )
{
    // initialize math exports.
}

bool math::world_to_screen( math::vec3_t &origin, math::vec3_t &out )
{
    static auto screen_transform = pattern::search( HASH( "client.dll" ),
                                                    XOR( "E8 ? ? ? ? F3 0F 10 45 ? 8B D0" ) ).resolve_rip( 1, 5 ).get< bool( __fastcall * )( math::vec3_t &, math::vec3_t & ) >( );

    if ( !screen_transform )
        return false;

    auto ret = !( screen_transform( origin, out ) );

    out.x = ( ( out.x + 1.0f ) * 0.5f ) * g_render.m_screen_size.x;
    out.y = ( float ) g_render.m_screen_size.y - ( ( ( out.y + 1.0f ) * 0.5f ) * g_render.m_screen_size.y );

    return ret;
}