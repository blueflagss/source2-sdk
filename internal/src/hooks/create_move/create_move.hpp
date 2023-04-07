#ifndef CS2_PROJECT_CREATE_MOVE_HPP
#define CS2_PROJECT_CREATE_MOVE_HPP

namespace hooks
{
    namespace create_move
    {
        inline hook::detour m_hook;

        void __fastcall hook( void* ecx, int sequence_number, unsigned __int8 a3 );

        void init( );
    }// namespace create_move
}// namespace hooks

#endif//CS2_PROJECT_CREATE_MOVE_HPP
