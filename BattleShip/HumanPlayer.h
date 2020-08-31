/***********************************************************************
 * Module:  HumanPlayer.h
 * Author:  nilov_pg
 * Modified: 20 ���� 2020 �. 11:49:50
 * Purpose: Declaration of the class HumanPlayer
 ***********************************************************************/

#if !defined(__BattleShip_HumanPlayer_h)
#define __BattleShip_HumanPlayer_h

class IUserManipulator;

#include <IPlayer.h>

class HumanPlayer : public IPlayer
{
public:
   void MakeShot(int& x, int& y);
   HumanPlayer(IUserManipulator &iUserManipulator);
   ~HumanPlayer();

   IUserManipulator* iUserManipulator;

protected:
private:


   // IPlayer interface
public:
   void SetResult(Cell cell);
};

#endif
