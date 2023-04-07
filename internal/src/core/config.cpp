#include "includes.hpp"

void config::impl::init( )
{
    char file_path[ MAX_PATH ];

    if ( SUCCEEDED( SHGetFolderPathA( NULL, CSIDL_APPDATA, NULL, 0, file_path ) ) ) {
        m_config_path = std::string( file_path ) + XOR( "\\roentgenium\\" );

        if ( !std::filesystem::exists( m_config_path ) )
            std::filesystem::create_directory( m_config_path );
    }
}

void config::impl::save( const std::string &name )
{
    nlohmann::json j;

    std::ofstream file{ m_config_path + name };

    for ( size_t i = 0; i < NUM_CONFIG_ITEMS; i++ ) {
        uintptr_t option_address = reinterpret_cast< uintptr_t >( &g_vars ) + ( i * sizeof( config_bool ) );

        switch ( *reinterpret_cast< int * >( option_address ) ) {
            case config_type_bool: {
                config_bool *option = reinterpret_cast< config_bool * >( option_address );

                j[ option->name ] = option->value;
            } break;
            case config_type_int: {
                config_int *option = reinterpret_cast< config_int * >( option_address );

                j[ option->name ] = option->value;
            } break;
            case config_type_float: {
                config_float *option = reinterpret_cast< config_float * >( option_address );

                j[ option->name ] = option->value;
            } break;
            case config_type_double: {
                config_double *option = reinterpret_cast< config_double * >( option_address );

                j[ option->name ] = option->value;
            } break;
            case config_type_string: {
                config_string *option = reinterpret_cast< config_string * >( option_address );

                j[ option->name ] = option->value.c_str( );
            } break;
//            case config_type_ImVec4: {
//                config_ImVec4 *option = reinterpret_cast< config_ImVec4 * >( option_address );
//
//                j[ option->name ][ 0 ] = option->value.x;
//                j[ option->name ][ 1 ] = option->value.y;
//                j[ option->name ][ 2 ] = option->value.z;
//                j[ option->name ][ 3 ] = option->value.w;
//            } break;
            default: {
                spdlog::info( "Found config value with unknown type\n" );
            } break;
        }
    }

    file << std::setw( 4 ) << j << std::endl;
    file.close( );
}

void config::impl::load( const std::string &name )
{
    std::ifstream file{ m_config_path + name };

    if ( !file.is_open( ) )
        return;

    nlohmann::json j;

    file >> j;

    for ( size_t i = 0; i < NUM_CONFIG_ITEMS; i++ ) {
        uintptr_t option_address = reinterpret_cast< uintptr_t >( &g_vars ) + ( i * sizeof( config_bool ) );

        switch ( *reinterpret_cast< int * >( option_address ) ) {
            case config_type_bool: {
                config_bool *option = reinterpret_cast< config_bool * >( option_address );

                option->value = j[ option->name ];
            } break;
            case config_type_int: {
                config_int *option = reinterpret_cast< config_int * >( option_address );

                option->value = j[ option->name ];
            } break;
            case config_type_float: {
                config_float *option = reinterpret_cast< config_float * >( option_address );

                option->value = j[ option->name ];
            } break;
            case config_type_double: {
                config_double *option = reinterpret_cast< config_double * >( option_address );

                option->value = j[ option->name ];
            } break;
            case config_type_string: {
                config_string *option = reinterpret_cast< config_string * >( option_address );

                option->value = j[ option->name ];
            } break;
//            case config_type_ImVec4: {
//                config_ImVec4 *option = reinterpret_cast< config_ImVec4 * >( option_address );
//
//                option->value.x = j[ option->name ][ 0 ];
//                option->value.y = j[ option->name ][ 1 ];
//                option->value.z = j[ option->name ][ 2 ];
//                option->value.w = j[ option->name ][ 3 ];
//            } break;
            default: {
                spdlog::info( "Found config value with unknown type\n" );
            } break;
        }
    }

    file.close( );
}