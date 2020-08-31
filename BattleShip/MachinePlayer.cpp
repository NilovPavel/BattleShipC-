/***********************************************************************
 * Module:  MachinePlayer.cpp
 * Author:  nilov_pg
 * Modified: 20 ���� 2020 �. 11:49:43
 * Purpose: Implementation of the class MachinePlayer
 ***********************************************************************/

#include "MachinePlayer.h"
#include "Ship.h"

////////////////////////////////////////////////////////////////////////
// Name:       MachinePlayer::MakeShot(int& x, int& y)
// Purpose:    Implementation of MachinePlayer::MakeShot()
// Parameters:
// - x
// - y
// Return:     void
////////////////////////////////////////////////////////////////////////

void MachinePlayer::SetResult(Cell cell)
{
    //Ui *userInterFace = new Cui(*this->enemyField, *this->enemyField);

    this->enemyField->SetCellType(cell.getX(), cell.getY(), cell.getECellType());

    //userInterFace->Update();

    if(cell.getECellType() == ECellType::dead)
    {
        this->enemyField->SetCellType(cell.getX(), cell.getY(), ECellType::wound);

        //userInterFace->Update();

        this->MakeDeadShip();
    }

    //userInterFace->Update();
}

void MachinePlayer::MakeShot(int& x, int& y)
{
    this->CalcNextCoordinats(x, y);
}

int MachinePlayer::GetWoundCells(Cell &firstWoundCell, Cell &lastWoundCell)
{
    int woundCellCount = 0;

    for(int cellCountY = 0; cellCountY < this->enemyField->getHeight(); cellCountY++)
        for(int cellCountX = 0; cellCountX < this->enemyField->getWidth(); cellCountX++)
            if(this->enemyField->GetCellType(cellCountX, cellCountY) == ECellType::wound)
            {
                Cell *currentCell = new Cell(cellCountX, cellCountY, ECellType::wound);
                if(woundCellCount == 0)
                    firstWoundCell = *currentCell;
                lastWoundCell = *new Cell(cellCountX, cellCountY, ECellType::wound);
                woundCellCount++;
            }
    return woundCellCount;
}

int MachinePlayer::GetCellIndexZeroWound()
{
    int x = 0;
    int y = 0;
    do
    {
        x = rand() % (this->enemyField->getWidth());
        y = rand() % (this->enemyField->getHeight());
    }
    while(!this->CanTakeCell(x,y));
    return y*this->enemyField->getWidth() + x;
}

int MachinePlayer::GetCellIndexOneWound(Cell *firstWoundCell)
{
    int x = firstWoundCell->getX() - 1;
    int y = firstWoundCell->getY();

    if(this->CanTakeCell(x, y))
        return y*this->enemyField->getWidth() + x;

    x = firstWoundCell->getX() + 1;
    y = firstWoundCell->getY();

    if(this->CanTakeCell(x, y))
        return y*this->enemyField->getWidth() + x;

    x = firstWoundCell->getX();
    y = firstWoundCell->getY() - 1;

    if(this->CanTakeCell(x, y))
        return y*this->enemyField->getWidth() + x;

    x = firstWoundCell->getX() ;
    y = firstWoundCell->getY() + 1;

    if(this->CanTakeCell(x, y))
        return y*this->enemyField->getWidth() + x;

    return y*this->enemyField->getWidth() + x;
}

int MachinePlayer::GetCellIndexMultyplyWound(Cell *firstWoundCell, Cell *lastWoundCell)
{
    bool direction = lastWoundCell->getY() - firstWoundCell->getY() == 0;
    int x = direction ? firstWoundCell->getX() - 1 : firstWoundCell->getX();
    int y = direction ? firstWoundCell->getY() : firstWoundCell->getY() - 1;

    if(this->CanTakeCell(x,y))
        return y*this->enemyField->getWidth() + x;

    x = direction ? lastWoundCell->getX() + 1 : lastWoundCell->getX();
    y = direction ? lastWoundCell->getY() : lastWoundCell->getY() + 1;

    return y*this->enemyField->getWidth() + x;
}

void MachinePlayer::MakeDeadShip(/*Cell cell*/)
{
    Cell firstWoundCell = Cell(0, 0, ECellType::wound);
    Cell lastWoundCell =  Cell(0, 0, ECellType::wound);

    int woundCellCount = this->GetWoundCells(firstWoundCell, lastWoundCell);
    bool direction = firstWoundCell.getY() == lastWoundCell.getY();

    Ship *ship = new Ship(firstWoundCell, direction, woundCellCount, *this->enemyField);
    for(int shipCount = 0; shipCount < this->arraySize; shipCount++)
        if(this->enemyShips[shipCount] && this->shipSizesArray[shipCount] == woundCellCount)
            this->enemyShips = &ship;

    ship->KillSelf();
    ship->ShowMe();
}

////////////////////////////////////////////////////////////////////////
// Name:       MachinePlayer::MachinePlayer()
// Purpose:    Implementation of MachinePlayer::MachinePlayer()
// Return:
////////////////////////////////////////////////////////////////////////.

MachinePlayer::MachinePlayer(int &sizesArray, int arraySize, int enemyFieldHeight, int enemyFieldWidth)
{
    this->shipSizesArray = &sizesArray;
    this->arraySize = arraySize;
    this->enemyFieldWidth = enemyFieldWidth;
    this->enemyFieldHeight = enemyFieldHeight;
    this->Initialization();
}

////////////////////////////////////////////////////////////////////////
// Name:       MachinePlayer::~MachinePlayer()
// Purpose:    Implementation of MachinePlayer::~MachinePlayer()
// Return:
////////////////////////////////////////////////////////////////////////

MachinePlayer::~MachinePlayer()
{
    // TODO : implement
}

void MachinePlayer::Initialization()
{
    this->enemyField = new Field(this->enemyFieldHeight, this->enemyFieldWidth);
    this->enemyShips = new Ship*[this->arraySize];
}

void MachinePlayer::CalcNextCoordinats(int &x, int &y)
{
    Cell *firstWoundCell = new Cell(0, 0, ECellType::wound);
    Cell *lastWoundCell = new Cell(0, 0, ECellType::wound);

    int woundCellCount = this->GetWoundCells(*firstWoundCell, *lastWoundCell);

    int cellIndex = 0;
    switch (woundCellCount)
    {
    case 0:
        cellIndex = this->GetCellIndexZeroWound();
        break;
    case 1:
        cellIndex = this->GetCellIndexOneWound(firstWoundCell);
        break;
    default:
        cellIndex = this->GetCellIndexMultyplyWound(firstWoundCell, lastWoundCell);
        break;
    }

    x = cellIndex%this->enemyField->getWidth();
    y = cellIndex/this->enemyField->getWidth();
}

bool MachinePlayer::CanTakeCell(int x, int y)
{
    if(x > this->enemyField->getWidth() || x < 0 || y > this->enemyField->getHeight() || y < 0)
        return false;

    return this->enemyField->GetCellType(x,y) == ECellType::empty;
}
