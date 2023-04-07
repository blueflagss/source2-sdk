#include "includes.hpp"

void menu::impl::setup_styles( )
{
    ImGuiStyle *style = &ImGui::GetStyle();
    ImVec4 *colors = style->Colors;

    colors[ ImGuiCol_Text ] = ImVec4( 1.00f, 1.00f, 1.00f, 1.00f );
    colors[ ImGuiCol_TextDisabled ] = ImVec4( 0.50f, 0.50f, 0.50f, 1.00f );
    colors[ ImGuiCol_WindowBg ] = ImVec4( 0.06f, 0.06f, 0.06f, 0.94f );
    colors[ ImGuiCol_ChildBg ] = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
    colors[ ImGuiCol_PopupBg ] = ImVec4( 0.08f, 0.08f, 0.08f, 0.94f );
    colors[ ImGuiCol_Border ] = ImVec4( 0.43f, 0.43f, 0.50f, 0.50f );
    colors[ ImGuiCol_BorderShadow ] = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
    colors[ ImGuiCol_FrameBg ] = ImVec4( 0.16f, 0.29f, 0.48f, 0.54f );
    colors[ ImGuiCol_FrameBgHovered ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.40f );
    colors[ ImGuiCol_FrameBgActive ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.67f );
    colors[ ImGuiCol_TitleBg ] = ImVec4( 0.04f, 0.04f, 0.04f, 1.00f );
    colors[ ImGuiCol_TitleBgActive ] = ImVec4( 0.16f, 0.29f, 0.48f, 1.00f );
    colors[ ImGuiCol_TitleBgCollapsed ] = ImVec4( 0.00f, 0.00f, 0.00f, 0.51f );
    colors[ ImGuiCol_MenuBarBg ] = ImVec4( 0.14f, 0.14f, 0.14f, 1.00f );
    colors[ ImGuiCol_ScrollbarBg ] = ImVec4( 0.02f, 0.02f, 0.02f, 0.53f );
    colors[ ImGuiCol_ScrollbarGrab ] = ImVec4( 0.31f, 0.31f, 0.31f, 1.00f );
    colors[ ImGuiCol_ScrollbarGrabHovered ] = ImVec4( 0.41f, 0.41f, 0.41f, 1.00f );
    colors[ ImGuiCol_ScrollbarGrabActive ] = ImVec4( 0.51f, 0.51f, 0.51f, 1.00f );
    colors[ ImGuiCol_CheckMark ] = ImVec4( 0.26f, 0.59f, 0.98f, 1.00f );
    colors[ ImGuiCol_SliderGrab ] = ImVec4( 0.24f, 0.52f, 0.88f, 1.00f );
    colors[ ImGuiCol_SliderGrabActive ] = ImVec4( 0.26f, 0.59f, 0.98f, 1.00f );
    colors[ ImGuiCol_Button ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.40f );
    colors[ ImGuiCol_ButtonHovered ] = ImVec4( 0.26f, 0.59f, 0.98f, 1.00f );
    colors[ ImGuiCol_ButtonActive ] = ImVec4( 0.06f, 0.53f, 0.98f, 1.00f );
    colors[ ImGuiCol_Header ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.31f );
    colors[ ImGuiCol_HeaderHovered ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.80f );
    colors[ ImGuiCol_HeaderActive ] = ImVec4( 0.26f, 0.59f, 0.98f, 1.00f );
    colors[ ImGuiCol_Separator ] = colors[ ImGuiCol_Border ];
    colors[ ImGuiCol_SeparatorHovered ] = ImVec4( 0.10f, 0.40f, 0.75f, 0.78f );
    colors[ ImGuiCol_SeparatorActive ] = ImVec4( 0.10f, 0.40f, 0.75f, 1.00f );
    colors[ ImGuiCol_ResizeGrip ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.20f );
    colors[ ImGuiCol_ResizeGripHovered ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.67f );
    colors[ ImGuiCol_ResizeGripActive ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.95f );
    colors[ ImGuiCol_Tab ] = ImLerp( colors[ ImGuiCol_Header ], colors[ ImGuiCol_TitleBgActive ], 0.80f );
    colors[ ImGuiCol_TabHovered ] = colors[ ImGuiCol_HeaderHovered ];
    colors[ ImGuiCol_TabActive ] = ImLerp( colors[ ImGuiCol_HeaderActive ], colors[ ImGuiCol_TitleBgActive ], 0.60f );
    colors[ ImGuiCol_TabUnfocused ] = ImLerp( colors[ ImGuiCol_Tab ], colors[ ImGuiCol_TitleBg ], 0.80f );
    colors[ ImGuiCol_TabUnfocusedActive ] = ImLerp( colors[ ImGuiCol_TabActive ], colors[ ImGuiCol_TitleBg ], 0.40f );
    colors[ ImGuiCol_PlotLines ] = ImVec4( 0.61f, 0.61f, 0.61f, 1.00f );
    colors[ ImGuiCol_PlotLinesHovered ] = ImVec4( 1.00f, 0.43f, 0.35f, 1.00f );
    colors[ ImGuiCol_PlotHistogram ] = ImVec4( 0.90f, 0.70f, 0.00f, 1.00f );
    colors[ ImGuiCol_PlotHistogramHovered ] = ImVec4( 1.00f, 0.60f, 0.00f, 1.00f );
    colors[ ImGuiCol_TableHeaderBg ] = ImVec4( 0.19f, 0.19f, 0.20f, 1.00f );
    colors[ ImGuiCol_TableBorderStrong ] = ImVec4( 0.31f, 0.31f, 0.35f, 1.00f );// Prefer using Alpha=1.0 here
    colors[ ImGuiCol_TableBorderLight ] = ImVec4( 0.23f, 0.23f, 0.25f, 1.00f ); // Prefer using Alpha=1.0 here
    colors[ ImGuiCol_TableRowBg ] = ImVec4( 0.00f, 0.00f, 0.00f, 0.00f );
    colors[ ImGuiCol_TableRowBgAlt ] = ImVec4( 1.00f, 1.00f, 1.00f, 0.06f );
    colors[ ImGuiCol_TextSelectedBg ] = ImVec4( 0.26f, 0.59f, 0.98f, 0.35f );
    colors[ ImGuiCol_DragDropTarget ] = ImVec4( 1.00f, 1.00f, 0.00f, 0.90f );
    colors[ ImGuiCol_NavHighlight ] = ImVec4( 0.26f, 0.59f, 0.98f, 1.00f );
    colors[ ImGuiCol_NavWindowingHighlight ] = ImVec4( 1.00f, 1.00f, 1.00f, 0.70f );
    colors[ ImGuiCol_NavWindowingDimBg ] = ImVec4( 0.80f, 0.80f, 0.80f, 0.20f );
    colors[ ImGuiCol_ModalWindowDimBg ] = ImVec4( 0.80f, 0.80f, 0.80f, 0.35f );

    style->ChildRounding = 4.0f;
    style->FrameBorderSize = 1.0f;
    style->FrameRounding = 3.0f;
    style->WindowRounding = 4.0f;
}

void menu::impl::init( )
{
    ImGui::CreateContext( );
    ImGuiIO &io = ImGui::GetIO( ); ( void ) io;

    // Setup Dear ImGui style
    setup_styles( );

    // Setup Platform/Renderer backends
    ImGui_ImplWin32_Init( g_interfaces.m_window );
    ImGui_ImplDX11_Init( g_interfaces.m_device, g_interfaces.m_device_context );
}

void menu::impl::render( )
{
    const char* window_title = XOR( "Roentgenium" );

    if ( ImGui::IsKeyPressed( ImGuiKey_Insert ) )
        m_open = !m_open;

    ImGui::PushFont( g_render.menu_main.m_handle );

    if ( m_open )
    {
        if ( ImGui::BeginMainMenuBar( ) )
        {
            ImGui::Text( window_title );
            ImGui::EndMainMenuBar( );
        }

        ImGui::SetNextWindowSize( m_size, ImGuiCond_FirstUseEver );

        if ( ImGui::Begin( window_title, &m_open, ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoTitleBar ) )
        {
            if ( ImGui::BeginTabBar( XOR( "main_window##tabs" ) ) )
            {
                if ( ImGui::BeginTabItem( XOR( "Legit" ) ) )
                {
                    ImGui::EndTabItem( );
                }

                if ( ImGui::BeginTabItem( XOR( "ESP" ) ) )
                {
                    ImGui::EndTabItem( );
                }

                if ( ImGui::BeginTabItem( XOR( "Skins" ) ) )
                {
                    ImGui::EndTabItem( );
                }

                if ( ImGui::BeginTabItem( XOR( "Movement" ) ) )
                {
                    ImGui::EndTabItem( );
                }

                if ( ImGui::BeginTabItem( XOR( "Styles" ) ) )
                {
                    ImGui::EndTabItem( );
                }

                if ( ImGui::BeginTabItem( XOR( "Config" ) ) )
                {
                    if ( ImGui::BeginChild( XOR( "##config_main" ) ) )
                    {
                        ImGui::Checkbox( XOR( "Test" ), &g_vars.bunnyhoops.value );

                        if ( ImGui::Button( XOR( "Save" ) ) )
                            g_config.save( "penis.json" );

                        if ( ImGui::Button( XOR( "Load" ) ) )
                            g_config.load( "penis.json" );

                        ImGui::EndChild( );
                    }

                    ImGui::EndTabItem( );
                }

                ImGui::EndTabBar( );
            }

            ImGui::End( );
        }
    }

    ImGui::PopFont( );
    ImGui::Render( );
}