#ifndef CS2_PROJECT_PLAYER_HPP
#define CS2_PROJECT_PLAYER_HPP

class c_game_scene_node {
public:
    SCHEMA_VAR( math::vec3_t, abs_origin, "CGameSceneNode", "m_vecAbsOrigin" )
};

class c_base_player_pawn_base {
public:
    SCHEMA_VAR( flags_t, flags, "C_BaseEntity", "m_fFlags" )
    SCHEMA_VAR( movetype_t, move_type, "C_BaseEntity", "m_MoveType" )
    SCHEMA_VAR( c_game_scene_node *, game_scene_node, "C_BaseEntity", "m_pGameSceneNode" )
};

class c_base_player_pawn : public c_base_player_pawn_base {
public:
    SCHEMA_VAR( int32_t, health, "C_BaseEntity", "m_iHealth" )
    SCHEMA_VAR( int32_t, max_health, "C_BaseEntity", "m_iMaxHealth" )
    SCHEMA_VAR( uint8_t, team, "C_BaseEntity", "m_iTeamNum" )
    SCHEMA_VAR( c_collision_property *, collision, "C_BaseEntity", "m_pCollision" )

    bool alive( );
};

class c_base_player {
public:
    template < typename T >
    inline static T get_controller_from_index( int index )
    {
        static auto get_controller_from_index = pattern::search( HASH( "client.dll" ),
                                                                 XOR( "E8 ? ? ? ? 48 8B C8 48 8B F8 E8 ? ? ? ? 48 8B D8 39" ) ).resolve_rip( 1, 5 ).get< c_base_player *( __fastcall * ) ( int ) >( );

        return reinterpret_cast< T >( get_controller_from_index( index ) );
    }

    template < typename T >
    inline static T get_pawn_from_controller( void *controller )
    {
        static auto get_pawn_from_controller = pattern::search( HASH( "client.dll" ),
                                                                XOR( "E8 ?? ?? ?? ?? 48 8B D0 48 85 C0 75 21" ) ).resolve_rip( 1, 5 ).get< void *( __fastcall * ) ( void * ) >( );

        return reinterpret_cast< T >( get_pawn_from_controller( controller ) );
    }

    template < typename T >
    inline static T get_local_player( int index )
    {
        static auto get_local_player = pattern::search( HASH( "client.dll" ),
                                                        XOR( "E8 ? ? ? ? 4D 8B 45 00" ) ).resolve_rip( 1, 5 ).get< void *( __fastcall * ) ( int ) >( );

        return reinterpret_cast< T >( get_local_player( index ) );
    }
};

class c_base_player_controller : public c_base_player {
public:
    SCHEMA_VAR( bool, is_local_controller, "CBasePlayerController", "m_bIsLocalPlayerController" )

    inline const char *player_name( )
    {
        static auto player_name_offset = g_schema.get_schema_offset( HASH( "CBasePlayerController" ), HASH( "m_iszPlayerName" ) );
        return reinterpret_cast< const char * >( reinterpret_cast< uintptr_t >( this ) + player_name_offset );
    }
};

#endif//CS2_PROJECT_PLAYER_HPP
