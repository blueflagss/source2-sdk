#ifndef CS2_PROJECT_CONFIG_HPP
#define CS2_PROJECT_CONFIG_HPP

#define MAX_STRUCT_FIELD_SIZE 64
#define CONFIG_TYPE_IMPL( type )                                          \
    class config_##type {                                                 \
    public:                                                               \
        int value_type;                                                   \
        const char *name;                                                 \
        __declspec( align( MAX_STRUCT_FIELD_SIZE ) ) type value;          \
    };                                                                    \
                                                                          \
    constexpr int config_type_##type = __LINE__;                          \
    static_assert( sizeof( config_##type ) == sizeof( config_bool ), #type " option size doesn't match uniform option size" ) \

using namespace std;

CONFIG_TYPE_IMPL( bool );
CONFIG_TYPE_IMPL( int );
CONFIG_TYPE_IMPL( float );
CONFIG_TYPE_IMPL( double );
CONFIG_TYPE_IMPL( string );
CONFIG_TYPE_IMPL( ImVec4 );

#define OPTION( type, name, value ) \
    config_##type name = config_##type { config_type_##type, #name, value }

#pragma( pack, 1 )

class variables {
public:
    OPTION( bool, bunnyhoops, true );
    OPTION( bool, aimboat, false );
    OPTION( ImVec4, penis, ImVec4( 1.0f, 1.0f, 1.0f, 1.0f ) );
};

static_assert( ( sizeof( variables ) % sizeof( config_bool ) ) == 0, "Config class isn't aligned properly" );
#define NUM_CONFIG_ITEMS ( sizeof( variables ) / sizeof( config_bool ) )

inline variables g_vars { };

namespace config
{
    class impl {
    public:
        std::string m_config_path;

        void init( );
        void save( const std::string &name );
        void load( const std::string &name );
    };
}// namespace config

inline config::impl g_config;

#endif//CS2_PROJECT_CONFIG_HPP
