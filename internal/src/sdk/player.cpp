#include "includes.hpp"

bool c_base_player_pawn::alive( )
{
    return this && this->health( ) > 0;
}