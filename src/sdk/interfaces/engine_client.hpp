#ifndef CS2_PROJECT_ENGINE_CLIENT_HPP
#define CS2_PROJECT_ENGINE_CLIENT_HPP

class c_engine_client {
public:
    bool is_connected()
    {
        using is_connected_t = bool( __thiscall * )( void * );
        return utils::get_method< is_connected_t >( this, 31 )( this );
    }

    bool is_in_game()
    {
        using is_in_game_t = bool( __thiscall * )( void * );
        return utils::get_method< is_in_game_t >( this, 30 )( this );
    }

    void get_screen_size( int &w, int &h )
    {
        using get_screen_size_t = void( __thiscall * )( void *, int &, int & );
        utils::get_method< get_screen_size_t >( this, 48 )( this, w, h );
    }

    math::vec2_t get_screen_size()
    {
        int w, h;

        get_screen_size( w, h );

        return {
                static_cast< float >( w ),
                static_cast< float >( h ) };
    }
};


#endif//CS2_PROJECT_ENGINE_CLIENT_HPP
