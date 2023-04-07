#ifndef ROENTGENIUM_VARIABLES_HPP
#define ROENTGENIUM_VARIABLES_HPP

namespace config
{
#pragma( pack, 1 )
    class variables {
    public:
        struct
        {
            OPTION( bool, bounding_box, true );
            OPTION( bool, name, true );
        } visuals;
    };
}

inline config::variables g_vars { };

static_assert( ( sizeof( config::variables ) % sizeof( config_bool ) ) == 0, "Config class isn't aligned properly" );
#define NUM_CONFIG_ITEMS ( sizeof( config::variables ) / sizeof( config_bool ) )

#endif//ROENTGENIUM_VARIABLES_HPP
