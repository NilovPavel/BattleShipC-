/***********************************************************************
 * Module:  Field.cpp
 * Author:  nilov_pg
 * Modified: 17 июля 2020 г. 15:28:58
 * Purpose: Implementation of the class Field
 ***********************************************************************/

#include "Cell.h"
#include "Field.h"

////////////////////////////////////////////////////////////////////////
// Name:       Field::Initialization()
// Purpose:    Implementation of Field::Initialization()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Field::Initialization(void)
{
    this->cells = new Cell* [this->width*this->height];
    for(int y = 0; y < this->height; y++)
        for(int x = 0; x < this->width; x++)
            this->cells[y*this->width + x] = new Cell(x, y, ECellType::empty);
}

////////////////////////////////////////////////////////////////////////
// Name:       Field::GetCellType(int x, int y)
// Purpose:    Implementation of Field::GetCellType()
// Parameters:
// - x
// - y
// Return:     ECellType
////////////////////////////////////////////////////////////////////////

ECellType Field::GetCellType(int x, int y)
{
   return this->cells[y*this->width + x]->getECellType();
}

////////////////////////////////////////////////////////////////////////
// Name:       Field::SetCellType(int x, int y, ECellType eCellType)
// Purpose:    Implementation of Field::SetCellType()
// Parameters:
// - x
// - y
// - eCellType
// Return:     void
////////////////////////////////////////////////////////////////////////

void Field::SetCellType(int x, int y, ECellType eCellType)
{
   this->cells[y*this->width + x]->setECellType(eCellType);
}

////////////////////////////////////////////////////////////////////////
// Name:       Field::Field(int height, int width)
// Purpose:    Implementation of Field::Field()
// Parameters:
// - height
// - width
// Return:     
////////////////////////////////////////////////////////////////////////

Field::Field(int height, int width)
{
    this->height = height;
    this->width = width;
    this->Initialization();
}

////////////////////////////////////////////////////////////////////////
// Name:       Field::~Field()
// Purpose:    Implementation of Field::~Field()
// Return:     
////////////////////////////////////////////////////////////////////////

Field::~Field()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Field::getHeight()
// Purpose:    Implementation of Field::getHeight()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Field::getHeight(void)
{
   return height;
}

////////////////////////////////////////////////////////////////////////
// Name:       Field::getWidth()
// Purpose:    Impl%mentation of Field::getWidth()
// Return:     int
////////////////////////////////////////////////////////////////////////

int Field::getWidth(void)
{
   return width;
}