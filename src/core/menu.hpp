#ifndef CS2_PROJECT_MENU_HPP
#define CS2_PROJECT_MENU_HPP

namespace menu
{
    class impl {
    public:
        bool m_open = false;
        ImVec2 m_size = { 598, 373 };

        void init( );
        void setup_styles( );
        void render( );
    };
}// namespace menu

inline menu::impl g_menu{ };

#endif//CS2_PROJECT_MENU_HPP
