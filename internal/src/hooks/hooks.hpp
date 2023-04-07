#ifndef CS2_PROJECT_HOOKS_HPP
#define CS2_PROJECT_HOOKS_HPP

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_ERROR

namespace hooks
{
    class impl {
    public:
        void init( );
        void shutdown( );
    };
}// namespace hooks

inline hooks::impl g_hooks{ };

#endif//CS2_PROJECT_HOOKS_HPP
