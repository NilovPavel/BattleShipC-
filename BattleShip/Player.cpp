/***********************************************************************
 * Module:  Player.cpp
 * Author:  nilov_pg
 * Modified: 20 июля 2020 г. 11:18:44
 * Purpose: Implementation of the class Player
 ***********************************************************************/

#include "IPlayer.h"
#include "Field.h"
#include "Ship.h"
#include "Player.h"

////////////////////////////////////////////////////////////////////////
// Name:       Player::Initialization()
// Purpose:    Implementation of Player::Initialization()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Player::Initialization(void)
{
    int shipSizes[10]{4,3,3,2,2,2,1,1,1,1};
    int arraySizesCount = sizeof (shipSizes)/sizeof (int);
    this->ships = new Ship *[arraySizesCount];

    for(int i = 0; i < 10; i++)
    {
        ships[i] = new Ship(*this->field, shipSizes[i]);
        for(int j = 0; j < i; j++)
        {
            while(!ships[j]->Check(*ships[i]))
            {
                ships[i]->Regeneration();
                j = 0;
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////
// Name:       Player::MakeShot(int x, int y)
// Purpose:    Implementation of Player::MakeShot()
// Parameters:
// - x
// - y
// Return:     ECellType
////////////////////////////////////////////////////////////////////////

ECellType Player::MakeShot(int x, int y)
{
    ECellType eCellType = ECellType::miss;
    for(int i = 0; i < 10; i++)
    {
        /*if(this->ships[i]->getIsDead())
            continue;*/
        eCellType = this->ships[i]->Attack(x, y);
        switch (eCellType)
        {
        case ECellType::miss:
            this->field->SetCellType(x, y, eCellType);
            continue;
        case ECellType::wound:
        case ECellType::dead:
            this->field->SetCellType(x, y, eCellType);
            return eCellType;
        }
    }
    this->field->SetCellType(x, y, eCellType);
    return eCellType;
}

////////////////////////////////////////////////////////////////////////
// Name:       Player::Attack(Player& enemyPlayer)
// Purpose:    Implementation of Player::Attack()
// Parameters:
// - enemyPlayer
// Return:     ECellType
////////////////////////////////////////////////////////////////////////

ECellType Player::Attack(Player& enemyPlayer)
{
    int *shotX = new int;
    int *shotY = new int;
    this->iPlayer->MakeShot(*shotX, *shotY);
    ECellType cellType = enemyPlayer.MakeShot(*shotX, *shotY);
    this->iPlayer->SetResult(Cell(*shotX, *shotY, cellType));
    return enemyPlayer.MakeShot(*shotX, *shotY);
}

////////////////////////////////////////////////////////////////////////
// Name:       Player::IsDead()
// Purpose:    Implementation of Player::IsDead()
// Return:     bool
////////////////////////////////////////////////////////////////////////

bool Player::IsDead(void)
{
   int shipsCount = 10;
   int deadShipCount = 0;
   for(int i = 0; i < shipsCount; i++)
       if(this->ships[i]->getIsDead())
            deadShipCount += 1;
   return deadShipCount == shipsCount;/**/
}

////////////////////////////////////////////////////////////////////////
// Name:       Player::ShowSelf()
// Purpose:    Implementation of Player::ShowSelf()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Player::ShowSelf(void)
{
   for(int i = 0; i < 10; i++)
       ships[i]->ShowMe();
}

////////////////////////////////////////////////////////////////////////
// Name:       Player::Player(IPlayer& iPlayer, Field& field)
// Purpose:    Implementation of Player::Player()
// Parameters:
// - iPlayer
// - field
// Return:     
////////////////////////////////////////////////////////////////////////

Player::Player(IPlayer& iPlayer, Field& field)
{
   this->iPlayer = &iPlayer;
   this->field = &field;
   this->Initialization();
}

////////////////////////////////////////////////////////////////////////
// Name:       Player::~Player()
// Purpose:    Implementation of Player::~Player()
// Return:     
////////////////////////////////////////////////////////////////////////

Player::~Player()
{
   // TODO : implement
}
