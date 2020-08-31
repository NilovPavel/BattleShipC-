/***********************************************************************
 * Module:  UserConsole.cpp
 * Author:  nilov_pg
 * Modified: 10 июля 2020 г. 10:45:36
 * Purpose: Implementation of the class UserConsole
 ***********************************************************************/

#include "UserConsole.h"

////////////////////////////////////////////////////////////////////////
// Name:       UserConsole::MakeStep(int x, int y)
// Purpose:    Implementation of UserConsole::MakeStep()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void UserConsole::MakeStep(int *x, int *y)
{
    cout << "Set X:" << endl;
    cin >> *x;
    cout << "Set Y:" << endl;
    cin >> *y;
}
