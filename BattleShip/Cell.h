/***********************************************************************
 * Module:  Cell.h
 * Author:  nilov_pg
 * Modified: 16 июля 2020 г. 12:24:04
 * Purpose: Declaration of the class Cell
 ***********************************************************************/

#if !defined(__BattleShip_Cell_h)
#define __BattleShip_Cell_h

#include <ECellType.h>

class Cell
{
public:
   int getX(void);
   void setX(int newX);
   int getY(void);
   void setY(int newY);
   ECellType getECellType(void);
   void setECellType(ECellType newECellType);
   Cell(int x, int y, ECellType eCellType);
   ~Cell();

protected:
private:
   int x;
   int y;
   ECellType eCellType;


};

#endif