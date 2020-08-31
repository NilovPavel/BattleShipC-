#ifndef QTBATTLESHIP_H
#define QTBATTLESHIP_H

#include "fieldbutton.h"

#include <GUI.h>
#include <IUserManipulator.h>
#include <QDialog>
#include <QEventLoop>
#include <unistd.h>

namespace Ui {
class QtBattleShip;
}

class QtBattleShip : public QDialog, public GUI, public IUserManipulator
{
    Q_OBJECT

public:
    explicit QtBattleShip(QWidget *parent = nullptr);
    ~QtBattleShip();
    FieldButton** ButtonArray(QGroupBox *firstPlayerBox, Field *firstField);
    void BuildButtons(void);
private:
    int currentSelectIndex;
    FieldButton **firstPlayerButtons;
    FieldButton **secondPlayerButtons;
    void Initialization(void);

    Ui::QtBattleShip *ui;
private slots:
    void SetSelectIndex(int selectIndex);
    // GUI interface
public:
    void Update();

    // IUserManipulator interface
public:
    void MakeStep(int *x, int *y);
};

#endif // QTBATTLESHIP_H
