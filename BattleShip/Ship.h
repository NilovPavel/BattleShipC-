/***********************************************************************
 * Module:  Ship.h
 * Author:  nilov_pg
 * Modified: 17 ���� 2020 �. 17:33:03
 * Purpose: Declaration of the class Ship
 ***********************************************************************/
#include <ctime>
#include <iostream>

using namespace std;

#if !defined(__BattleShip_Ship_h)
#define __BattleShip_Ship_h

class Field;
class Cell;

#include <ECellType.h>
#include <Field.h>

class Ship
{
public:
   ECellType Attack(int x, int y);
   bool CanUseCell(int x, int y);
   bool Check(Ship& ship);
   void Regeneration(void);
   void ShowMe(void);
   Ship(Field& field, int size);
   Ship(Cell firstCell, bool direction, int size, Field &field);
   ~Ship();
   bool getIsDead(void);
   void KillSelf(void);

protected:
private:
   void Initialization(void);
   void MakeBorder(void);
   void MakeDecks(void);
   ECellType Strike(int deckCount);

   int x;
   int y;
   bool direction;
   bool isDead;
   int size;
   int borderSize;
   
   Field* field;
   Cell** decks;
   Cell** border;


};

#endif
