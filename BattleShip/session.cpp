#include "session.h"

void Session::Initialization()
{
    this->shipsCount = 10;
    this->shipSizes = new int[shipsCount]{4,3,3,2,2,2,1,1,1,1};

    this->firstPlayerField = new Field(10, 10);
    this->secondPlayerField = new Field(10, 10);

    this->firstIPlayer = new MachinePlayer(shipSizes[0], this->shipsCount, secondPlayerField->getHeight(), secondPlayerField->getWidth());
    this->secondIPlayer = new MachinePlayer(shipSizes[0], this->shipsCount, firstPlayerField->getHeight(), firstPlayerField->getWidth());
}

void Session::SetGUI(GUI &userInterFace)
{
    this->userInterFace = &userInterFace;
    this->userInterFace->SetFirstField(*this->firstPlayerField);
    this->userInterFace->SetSecondField(*this->secondPlayerField);
}

void Session::SetFirstIPlayer(IPlayer &iPlayer)
{
    this->firstIPlayer = &iPlayer;
}

void Session::SetSecondIPlayer(IPlayer &iPlayer)
{
    this->secondIPlayer = &iPlayer;
}

void Session::RunGame()
{
    Player *currentAttacker = new Player(*firstIPlayer, *firstPlayerField);
    Player *currentSacrifice = new Player(*secondIPlayer, *secondPlayerField);
    Player *temp = nullptr;

    while(!currentAttacker->IsDead() && !currentSacrifice->IsDead())
    {
        userInterFace->Update();
        ECellType eCellType = currentAttacker->Attack(*currentSacrifice);
        switch(eCellType)
        {
        case ECellType::empty:
        case ECellType::alive:
            continue;
        case ECellType::wound:
        case ECellType::dead:
            continue;
        case ECellType::miss:
            temp = currentAttacker;
            currentAttacker = currentSacrifice;
            currentSacrifice = temp;
            continue;
        }
    }
    userInterFace->Update();
}

Session::Session()
{
    this->Initialization();
}

Session::~Session()
{
    delete[] this->shipSizes;
}
