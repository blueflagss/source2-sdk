#ifndef CS2_PROJECT_MEM_ALLOC_HPP
#define CS2_PROJECT_MEM_ALLOC_HPP

class c_mem_alloc {
public:
    inline void* alloc( size_t size )
    {
        return utils::get_method< void* ( __thiscall* )( void*, size_t ) >( this, 2 )( this, size );
    }

    inline void* realloc( void* mem, size_t size )
    {
        return utils::get_method< void* ( __thiscall* )( void*, void* mem, size_t ) >( this, 4 )( this, mem, size );
    }

    inline void free( void* mem )
    {
        utils::get_method< void( __thiscall* )( void*, void* ) >( this, 6 )( this, mem );
    }
};

#endif//CS2_PROJECT_MEM_ALLOC_HPP
