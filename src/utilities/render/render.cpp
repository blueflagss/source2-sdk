#include "includes.hpp"

void render::impl::init( )
{
    m_screen_size = g_interfaces.m_engine_client->get_screen_size( );

    // init fonts.
    visuals_small = font( font_04b03_data, sizeof( font_04b03_data ), 8.0f, monochrome | monohinting );
    menu_main     = font( XOR( "C:\\Windows\\Fonts\\seguisb.ttf" ), 14.5f );
    visuals_large = font( XOR( "C:\\Windows\\Fonts\\segoeui.ttf" ), 14.0f );
}

void render::impl::rect_outlined( int x, int y, int w, int h, math::color color )
{
    ImGui::GetBackgroundDrawList( )->AddRect(
            ImVec2( ImFloor( x ), ImFloor( y ) ),
            ImVec2( ImFloor( x ) + ImFloor( w ), ImFloor( y ) + ImFloor( h ) ),
            ImColor{ color.r, color.g, color.b, color.a } );
}

void render::impl::rect_filled( int x, int y, int w, int h, math::color color )
{
    ImGui::GetBackgroundDrawList( )->AddRectFilled(
            ImVec2( ImFloor( x ), ImFloor( y ) ),
            ImVec2( ImFloor( x ) + ImFloor( w ), ImFloor( y ) + ImFloor( h ) ),
            ImColor{ color.r, color.g, color.b, color.a } );
}

render::dim_t render::font::size( const std::string& text )
{
    dim_t ret;

    ImGui::PushFont( this->m_handle );
    ImVec2 size = ImGui::CalcTextSize( text.data( ) );
    ImGui::PopFont( );

    ret = { size.x, size.y };

    return ret;
}

void render::font::string( float x, float y, math::color color, const std::string& text, string_flags_t flags, bool shadow )
{
    dim_t text_size = size( text );

    ImGui::PushFont( this->m_handle );

    if ( flags & render::align_right )
        x -= text_size.w;
    if ( flags & render::align_center )
        x -= text_size.w / 2;

    if ( shadow )
        ImGui::GetBackgroundDrawList( )->AddText( { ImFloor( x + 1 ), ImFloor( y + 1 ) }, ImColor { 0, 0, 0, color.a }, text.data( ) );

    ImGui::GetBackgroundDrawList( )->AddText( { ImFloor( x ), floor( y ) }, ImColor { color.r, color.g, color.b, color.a }, text.data( ) );
    ImGui::PopFont( );
}