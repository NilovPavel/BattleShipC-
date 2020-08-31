#include "Cui.h"
#include "UserConsole.h"
#include <time.h>
#include <Field.h>
#include <GUI.h>
#include <HumanPlayer.h>
#include <IPlayer.h>
#include <MachinePlayer.h>
#include <Player.h>

#include <iostream>
#include <session.h>

using namespace std;

int main()
{
    srand(time(nullptr));

    /*int shipSizes[10]{4,3,3,2,2,2,1,1,1,1};
    int arraySizesCount = sizeof (shipSizes)/sizeof (int);

    Field *firstPlayerField = new Field(10, 10);
    Field *secondPlayerField = new Field(10, 10);*/

    Session *session = new Session();
    /*IPlayer *firstIPlayer = new HumanPlayer(*(new UserConsole()));
    session->SetFirstIPlayer(*firstIPlayer);*/
    GUI *userInterFace = new Cui();
    session->SetGUI(*userInterFace);
    session->RunGame();

    //GUI *userInterFace = new Cui(*firstPlayerField, *secondPlayerField);
    /*userInterFace->Update();*/

    /*FieldWindow *window = new FieldWindow();
    window->SetFields(*firstPlayerField, *secondPlayerField);
    GUI *userInterFace = window;*/

    //IPlayer *firstIPlayer = new HumanPlayer(*(new UserConsole()));
    /*IPlayer *firstIPlayer = new MachinePlayer(shipSizes[0], arraySizesCount, secondPlayerField->getHeight(), secondPlayerField->getWidth());
    IPlayer *secondIPlayer = new MachinePlayer(shipSizes[0], arraySizesCount, firstPlayerField->getHeight(), firstPlayerField->getWidth());

    Player *firstPlayer = new Player(*firstIPlayer, *firstPlayerField);
    Player *secondPlayer = new Player(*secondIPlayer, *secondPlayerField);

    secondPlayer->ShowSelf();
    firstPlayer->ShowSelf();*/

    /*Player *currentAttacker = firstPlayer;
    Player *currentSacrifice = secondPlayer;
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
    }*/
    userInterFace->Update();

    return 0;
}
