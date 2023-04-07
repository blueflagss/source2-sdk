#include "includes.hpp"

LRESULT __stdcall hooks::wndproc::hook( HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam )
{
    return CallWindowProcA( m_hook_original, hwnd, msg, wparam, lparam );
}

void hooks::wndproc::init( )
{
    m_hook_original = reinterpret_cast< WNDPROC >( SetWindowLongPtrA( g_interfaces.m_window, GWLP_WNDPROC,
                                                                      reinterpret_cast< LONG_PTR >( hook ) ) );
}

void hooks::wndproc::shutdown( )
{
    SetWindowLongPtrA( g_interfaces.m_window, GWLP_WNDPROC, reinterpret_cast< LONG_PTR >( m_hook_original ) );
}