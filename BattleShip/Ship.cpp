/***********************************************************************
 * Module:  Ship.cpp
 * Author:  nilov_pg
 * Modified: 17 ���� 2020 �. 17:33:03
 * Purpose: Implementation of the class Ship
 ***********************************************************************/

#include "Field.h"
#include "Cell.h"
#include "Ship.h"

////////////////////////////////////////////////////////////////////////
// Name:       Ship::Initialization()
// Purpose:    Implementation of Ship::Initialization()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ship::Initialization(void)
{
   this->isDead = false;
   this->x = rand() % (this->field->getWidth() - this->size);
   this->y = rand() % (this->field->getHeight() - this->size);
   this->direction = (rand() % 2) == 1;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::MakeBorder()
// Purpose:    Implementation of Ship::MakeBorder()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ship::MakeBorder(void)
{
    int borderWidth = direction ? (this->x == 0 || this->x >= this->field->getWidth() - this->size ? this->size + 1 : this->size + 2)
                                : (this->x == 0 || this->x == this->field->getWidth() - 1 ? 2 : 3 );

    int borderHeight = !direction ? (this->y == 0 || this->y >= this->field->getHeight() - this->size ? this->size + 1 : this->size + 2)
                                 : (this->y == 0 || this->y == this->field->getHeight() - 1 ? 2 : 3 );

    this->borderSize = borderWidth*borderHeight;
    this->border = new Cell* [this->borderSize];

    int tempX = this->x - 1 < 0 ? this->x : this->x - 1;
    int tempY = this->y - 1 < 0 ? this->y : this->y - 1;

    for(int borderY = 0; borderY < borderHeight; borderY++)
        for(int borderX = 0; borderX < borderWidth; borderX++)
            this->border[borderY*borderWidth + borderX] = new Cell(tempX + borderX, tempY + borderY, ECellType::miss);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::MakeDecks()
// Purpose:    Implementation of Ship::MakeDecks()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ship::MakeDecks(void)
{
   this->decks = new Cell*[this->size];

   for(int deckCount = 0; deckCount < this->size; deckCount++)
        this->decks[deckCount] = new Cell(
                this->direction ? this->x + deckCount : this->x,
                this->direction ? this->y : deckCount + this->y,
                ECellType::alive);
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::Strike(int deckCount)
// Purpose:    Implementation of Ship::Strike()
// Parameters:
// - deckCount
// Return:     void
////////////////////////////////////////////////////////////////////////

ECellType Ship::Strike(int deckCount)
{
    this->decks[deckCount]->setECellType(ECellType::wound);

    int woundCount = 0;

    for(int decksCount = 0; decksCount < this->size; decksCount++)
        if(this->decks[decksCount]->getECellType() == ECellType::wound)
            woundCount++;

    this->isDead = woundCount == this->size;

    if(this->isDead)
        for(int decksCount = 0; decksCount < this->size; decksCount++)
            this->decks[decksCount]->setECellType(ECellType::dead);

    //this->ShowMe();
    return this->isDead ? ECellType::dead : ECellType::wound;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::Attack(int x, int y)
// Purpose:    Implementation of Ship::Attack()
// Parameters:
// - x
// - y
// Return:     ECellType
////////////////////////////////////////////////////////////////////////

ECellType Ship::Attack(int x, int y)
{
    for(int deckCount = 0; deckCount < this->size; deckCount++)
        if(this->decks[deckCount]->getX() == x && this->decks[deckCount]->getY() == y)
        {
            switch(this->decks[deckCount]->getECellType())
            {
            case ECellType::dead:
                this->ShowMe();
                return this->decks[deckCount]->getECellType();
            case ECellType::alive:
                return this->Strike(deckCount);
            default:
                return this->decks[deckCount]->getECellType();
            }
        }

    return ECellType::miss;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::CanUseCell(int x, int y)
// Purpose:    Implementation of Ship::CanUseCell()
// Parameters:
// - x
// - y
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Ship::CanUseCell(int x, int y)
{
   for(int borderCellCount = 0; borderCellCount < this->borderSize; borderCellCount++)
       if(this->border[borderCellCount]->getX() == x && this->border[borderCellCount]->getY() == y)
           return false;
   return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::Check(Ship& ship)
// Purpose:    Implementation of Ship::Check()
// Parameters:
// - ship
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Ship::Check(Ship& ship)
{
   for(int decksCellCount = 0; decksCellCount < this->size; decksCellCount++)
       if (!ship.CanUseCell(this->decks[decksCellCount]->getX(), this->decks[decksCellCount]->getY()))
           return false;
   return true;
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::Regeneration()
// Purpose:    Implementation of Ship::Regeneration()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ship::Regeneration(void)
{
    delete[] this->decks;
    delete[] this->border;

    this->x = rand() % (this->field->getWidth() - this->size);
    this->y = rand() % (this->field->getHeight() - this->size);

    this->MakeDecks();
    this->MakeBorder();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::ShowMe()
// Purpose:    Implementation of Ship::ShowMe()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Ship::ShowMe(void)
{
    for(int borderCount = 0; borderCount < this->borderSize; borderCount++)
        this->field->SetCellType(this->border[borderCount]->getX(), this->border[borderCount]->getY(), this->border[borderCount]->getECellType());/**/

    for(int deckCount = 0; deckCount < this->size; deckCount++)
        this->field->SetCellType(this->decks[deckCount]->getX(), this->decks[deckCount]->getY(), this->decks[deckCount]->getECellType());
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::Ship(Field& field, int size)
// Purpose:    Implementation of Ship::Ship()
// Parameters:
// - field
// - size
// Return:     
////////////////////////////////////////////////////////////////////////

Ship::Ship(Field& field, int size)
{
   this->field = &field;
   this->size = size;
   this->Initialization();
   this->Regeneration();
}

Ship::Ship(Cell firstCell, bool direction, int size, Field &field)
{
    this->x = firstCell.getX();
    this->y = firstCell.getY();
    this->direction = direction;
    this->size = size;
    this->field = &field;
    this->MakeDecks();
    this->MakeBorder();
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::~Ship()
// Purpose:    Implementation of Ship::~Ship()
// Return:     
////////////////////////////////////////////////////////////////////////

Ship::~Ship()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Ship::getIsDead()
// Purpose:    Implementation of Ship::getIsDead()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Ship::getIsDead(void)
{
    return isDead;
}

void Ship::KillSelf(void)
{
    for(int deckCount = 0; deckCount < this->size; deckCount++)
         this->decks[deckCount]->setECellType(ECellType::dead);

    this->isDead = true;
}
