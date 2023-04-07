#ifndef CS2_PROJECT_RENDER_HPP
#define CS2_PROJECT_RENDER_HPP

namespace render
{
    struct dim_t {
        float w;
        float h;
    };

    enum string_flags_t {
        align_left = 0,
        align_right,
        align_center
    };

    enum font_flag_t : int {
        none = 0,
        monohinting = 1,
        monochrome = 2
    };

    class font {
    public:
        ImFont *m_handle;
        dim_t m_size;
    public:
        __forceinline font( ) : m_handle { }, m_size { } { };

        // ctor.
        __forceinline font( const std::string &name, const float size, const int rasterizer_flags = 0, const ImWchar *glyph_ranges = nullptr )
        {
            ImFontConfig cfg { };

            if ( rasterizer_flags & monohinting )
                cfg.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_MonoHinting;

            if ( rasterizer_flags & monochrome )
                cfg.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_Monochrome;

            m_handle = ImGui::GetIO( ).Fonts->AddFontFromFileTTF( name.data(), size, &cfg, glyph_ranges );
        }

        // ctor.
        __forceinline font( uint8_t *data, size_t font_size, const float size, const int rasterizer_flags = 0, const ImWchar *glyph_ranges = nullptr )
        {
            ImFontConfig cfg { };

            if ( rasterizer_flags & monohinting )
                cfg.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_MonoHinting;

            if ( rasterizer_flags & monochrome )
                cfg.FontBuilderFlags |= ImGuiFreeTypeBuilderFlags_Monochrome;

            m_handle = ImGui::GetIO( ).Fonts->AddFontFromMemoryTTF( data, font_size, size, &cfg, glyph_ranges );
        }

        // ctor.
        __forceinline font( ImFont *font )
        {
            m_handle = font;
            m_size = size( "A" );
        }

        __forceinline void invalidate( )
        {
            m_handle = nullptr;
            m_size = { };
        }

        void string( float x, float y, math::color color, const std::string &text, string_flags_t flags = align_left, bool shadow = false );
        render::dim_t size( const std::string &text );
    };

    class impl {
    public:
        math::vec2_t m_screen_size { };

        // fonts.
        font visuals_small, visuals_large;
        font menu_main;

        void init( );
        void rect_filled( int x, int y, int w, int h, math::color color );
        void rect_outlined( int x, int y, int w, int h, math::color color );
    };
}// namespace render

inline render::impl g_render{};

#endif//CS2_PROJECT_RENDER_HPP
