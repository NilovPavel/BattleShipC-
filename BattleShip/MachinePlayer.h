/***********************************************************************
 * Module:  MachinePlayer.h
 * Author:  nilov_pg
 * Modified: 20 ���� 2020 �. 11:49:43
 * Purpose: Declaration of the class MachinePlayer
 ***********************************************************************/

#if !defined(__BattleShip_MachinePlayer_h)
#define __BattleShip_MachinePlayer_h

#include <Field.h>
#include <IPlayer.h>
#include <ECellType.h>

class MachinePlayer : public IPlayer
{
public:
   void SetResult(Cell cell);
   void MakeShot(int& x, int& y);

   MachinePlayer(int &sizesArray, int arraySize, int enemyFieldHeight, int enemyFieldWidth);
   ~MachinePlayer();

protected:
private:
    int enemyFieldWidth;
    int enemyFieldHeight;
    int *shipSizesArray;
    int arraySize;
    Field *enemyField;
    Ship **enemyShips;

    void Initialization(void);
    void CalcNextCoordinats(int& x, int& y);
    bool CanTakeCell(int x, int y);
    int GetWoundCells(Cell &firstWoundCell, Cell &lastWoundCell);
    int GetCellIndexZeroWound();
    int GetCellIndexOneWound(Cell *firstWoundCell);
    int GetCellIndexMultyplyWound(Cell *firstWoundCell, Cell *lastWoundCell);
    void MakeDeadShip();
};

#endif
