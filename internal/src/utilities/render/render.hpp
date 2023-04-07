#ifndef ROENTGENIUM_RENDERER_HPP
#define ROENTGENIUM_RENDERER_HPP

namespace render
{
    class font {
    public:
        size_t m_visual_big = 0;
    };

    class impl {
    public:
        glm::vec2 m_screen_size;

        // Buffer utilities.
        std::unique_ptr< renderer::d3d11_renderer > m_renderer;
        renderer::performance_counter m_performance;
        int m_buffer_id;

        void init( IDXGISwapChain* swap_chain );
    };
} // namespace render

inline render::font g_fonts{ };
inline render::impl g_render{ };

#endif//ROENTGENIUM_RENDERER_HPP
