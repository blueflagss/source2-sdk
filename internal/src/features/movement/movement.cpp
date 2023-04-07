#include "includes.hpp"

void movement::impl::run( c_user_cmd *cmd )
{
    if ( !cmd || !globals::local || !globals::local->alive( ) )
        return;

    if ( globals::local->move_type( ) == movetype_ladder || globals::local->move_type( ) == movetype_noclip )
        return;

    if ( !( globals::local->flags( ) & fl_onground ) )
        cmd->m_buttons &= ~in_jump;
}