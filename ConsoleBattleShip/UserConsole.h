/***********************************************************************
 * Module:  UserConsole.h
 * Author:  nilov_pg
 * Modified: 10 ���� 2020 �. 10:45:36
 * Purpose: Declaration of the class UserConsole
 ***********************************************************************/

#if !defined(__BattleShip_UserConsole_h)
#define __BattleShip_UserConsole_h

#include <IUserManipulator.h>
#include <iostream>

using namespace std;

class UserConsole : public IUserManipulator
{
public:
   void MakeStep(int *x, int *y);

protected:
private:

};

#endif
