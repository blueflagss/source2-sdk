#ifndef CS2_PROJECT_CSGOINPUT_HPP
#define CS2_PROJECT_CSGOINPUT_HPP

class c_csgo_input {
public:
    inline c_user_cmd *get_user_cmd( int a1 )
    {
        auto sequence_number = *reinterpret_cast< unsigned int* >( 0x4360 * a1 + reinterpret_cast< uintptr_t >( this ) + 0x41E0 );
        auto cmd_split_screen = reinterpret_cast< uintptr_t >( this ) + 0x70 * ( 154 * a1 + sequence_number % 150 );

        return reinterpret_cast< c_user_cmd* >( static_cast< uintptr_t >( cmd_split_screen ) + 0x10 );
    }

    inline bool set_view_angles( const math::vec3_t& angles )
    {
        static auto set_splitscreen_view_angles = pattern::search( HASH( "client.dll" ),
                                                                   XOR( "E8 ? ? ? ? 48 8B 0D ? ? ? ? 41 B1 01 48 8B 05" ) ).resolve_rip( 1, 5 ).get< __int64 ( __fastcall * ) ( void *, int, const math::vec3_t& ) >( );

        return set_splitscreen_view_angles( this, NULL, angles );
    }

    inline math::vec3_t& get_view_angles( )
    {
        static auto get_splitscreen_view_angles = pattern::search( HASH( "client.dll" ),
                                                                   XOR( "48 63 C2 48 69 D0 ? ? ? ? 48 8D 81" ) ).get< __int64 ( __fastcall * ) ( void *, int ) >( );

        return *reinterpret_cast< math::vec3_t* >( get_splitscreen_view_angles( this, NULL ) );
    }
};

#endif//CS2_PROJECT_CSGOINPUT_HPP
