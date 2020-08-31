/***********************************************************************
 * Module:  IPlayer.h
 * Author:  nilov_pg
 * Modified: 17 июля 2020 г. 14:33:59
 * Purpose: Declaration of the class IPlayer
 ***********************************************************************/

#include <Cell.h>

#if !defined(__BattleShip_IPlayer_h)
#define __BattleShip_IPlayer_h

class Ship;

class IPlayer
{
public:
   virtual void SetResult(Cell cell) = 0;
   virtual void MakeShot(int& x, int& y)=0;

protected:
private:

};

#endif
