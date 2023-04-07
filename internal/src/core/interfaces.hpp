#ifndef CS2_PROJECT_INTERFACES_HPP
#define CS2_PROJECT_INTERFACES_HPP

class c_render_system {
public:
    PAD( 0x178 );
    IDXGISwapChain* m_swap_chain;
};

namespace interfaces
{
    class impl {
    public:
        void init( );

        template< typename T >
        T create_interface( const hash32_t &module_name, const hash32_t &interface_name );

        // others.
        HWND m_window = nullptr;
        ID3D11RenderTargetView *m_render_target_view = nullptr;
        ID3D11Device *m_device = nullptr;
        ID3D11DeviceContext *m_device_context = nullptr;
        IDXGISwapChain *m_swap_chain = nullptr;

        // interfaces.
        c_global_vars_base *m_global_vars = nullptr;
        c_client *m_client = nullptr;
        c_schema_system *m_schema_system = nullptr;
        c_render_system *m_render = nullptr;
        c_engine_client *m_engine_client = nullptr;
        c_csgo_input *m_csgo_input = nullptr;
        c_mem_alloc *m_mem_alloc = nullptr;
        c_physics_query *m_physics_query = nullptr;
    };
}// namespace interfaces

inline interfaces::impl g_interfaces{ };

#endif//CS2_PROJECT_INTERFACES_HPP
