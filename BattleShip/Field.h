/***********************************************************************
 * Module:  Field.h
 * Author:  nilov_pg
 * Modified: 17 июля 2020 г. 15:28:58
 * Purpose: Declaration of the class Field
 ***********************************************************************/

#if !defined(__BattleShip_Field_h)
#define __BattleShip_Field_h

class Cell;

#include <ECellType.h>

class Field
{
public:
   ECellType GetCellType(int x, int y);
   void SetCellType(int x, int y, ECellType eCellType);
   Field(int height, int width);
   ~Field();
   int getHeight(void);
   int getWidth(void);

protected:
private:
   void Initialization(void);

   int height;
   int width;
   
   Cell** cells;


};

#endif