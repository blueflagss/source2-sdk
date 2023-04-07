#ifndef CS2_PROJECT_UTL_STRING_HPP
#define CS2_PROJECT_UTL_STRING_HPP

class CUtlString {
public:
    const char *Get( )
    {
        return reinterpret_cast< const char * >( m_Memory.m_pMemory );
    }

    CUtlMemory< std::uint8_t > m_Memory;
    int m_nActualLength;
};

#endif//CS2_PROJECT_UTL_STRING_HPP
