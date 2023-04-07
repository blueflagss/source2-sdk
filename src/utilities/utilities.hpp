#ifndef CS2_PROJECT_UTILITIES_HPP
#define CS2_PROJECT_UTILITIES_HPP

namespace utils
{
    template < typename T >
    inline T get_method( void *thisptr, uintptr_t idx )
    {
        return reinterpret_cast< T >(( *static_cast< uintptr_t ** >( thisptr ) )[ idx ] );
    }
}// namespace utilities

#endif//CS2_PROJECT_UTILITIES_HPP
