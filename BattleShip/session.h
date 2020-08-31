#ifndef SESSION_H
#define SESSION_H

#include "Player.h"
#include "Field.h"
#include "GUI.h"
#include "IPlayer.h"
#include "MachinePlayer.h"
#include <unistd.h>

class Session
{
private:
    int *shipSizes;
    int shipsCount;
    GUI *userInterFace;
    Field *firstPlayerField;
    Field *secondPlayerField;
    IPlayer *firstIPlayer;
    IPlayer *secondIPlayer;
    void Initialization();
public:
    void SetGUI(GUI &userInterFace);
    void SetFirstIPlayer(IPlayer &iPlayer);
    void SetSecondIPlayer(IPlayer &iPlayer);
    void RunGame();
    Session();
    ~Session();
};

#endif // SESSION_H
