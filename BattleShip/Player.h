/***********************************************************************
 * Module:  Player.h
 * Author:  nilov_pg
 * Modified: 20 июля 2020 г. 11:18:44
 * Purpose: Declaration of the class Player
 ***********************************************************************/

#if !defined(__BattleShip_Player_h)
#define __BattleShip_Player_h

class IPlayer;
class Field;
class Ship;

#include <ECellType.h>
#include <IPlayer.h>
#include <Field.h>

class Player
{
public:
   ECellType MakeShot(int x, int y);
   ECellType Attack(Player& enemyPlayer);
   bool IsDead(void);
   void ShowSelf(void);
   Player(IPlayer& iPlayer, Field& field);
   ~Player();

protected:
private:
   void Initialization(void);

   IPlayer* iPlayer;
   Field* field;
   Ship** ships;


};

#endif
