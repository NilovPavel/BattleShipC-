#include <qtbattleship.h>
#include <HumanPlayer.h>
#include <QApplication>
#include <session.h>


int main(int argc, char *argv[])
{
    srand(time(nullptr));
    QApplication a(argc, argv);

    QtBattleShip userInterFace;
    Session *session = new Session();
    session->SetGUI(userInterFace);

    IPlayer *firstIPlayer = new HumanPlayer(userInterFace);
    session->SetFirstIPlayer(*firstIPlayer);
    userInterFace.BuildButtons();
    userInterFace.show();
    session->RunGame();

    return a.exec();
}
