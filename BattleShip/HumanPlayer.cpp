/***********************************************************************
 * Module:  HumanPlayer.cpp
 * Author:  nilov_pg
 * Modified: 20 июля 2020 г. 11:49:50
 * Purpose: Implementation of the class HumanPlayer
 ***********************************************************************/

#include "IUserManipulator.h"
#include "HumanPlayer.h"

////////////////////////////////////////////////////////////////////////
// Name:       HumanPlayer::MakeShot(int& x, int& y)
// Purpose:    Implementation of HumanPlayer::MakeShot()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void HumanPlayer::MakeShot(int& x, int& y)
{
    this->iUserManipulator->MakeStep(&x, &y);
}

////////////////////////////////////////////////////////////////////////
// Name:       HumanPlayer::HumanPlayer()
// Purpose:    Implementation of HumanPlayer::HumanPlayer()
// Return:     
////////////////////////////////////////////////////////////////////////

HumanPlayer::HumanPlayer(IUserManipulator &iUserManipulator)
{
    this->iUserManipulator = &iUserManipulator;
}

////////////////////////////////////////////////////////////////////////
// Name:       HumanPlayer::~HumanPlayer()
// Purpose:    Implementation of HumanPlayer::~HumanPlayer()
// Return:     
////////////////////////////////////////////////////////////////////////

HumanPlayer::~HumanPlayer()
{
    // TODO : implement
}

void HumanPlayer::SetResult(Cell cell)
{
    return;
}
