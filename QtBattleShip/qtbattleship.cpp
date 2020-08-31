#include "fieldbutton.h"
#include "qtbattleship.h"
#include "ui_qtbattleship.h"

QtBattleShip::QtBattleShip(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::QtBattleShip)
{
    ui->setupUi(this);
    this->Initialization();
}

QtBattleShip::~QtBattleShip()
{
    delete ui;
}

FieldButton** QtBattleShip::ButtonArray(QGroupBox *playerBox, Field *field)
{
    FieldButton **playerButtons;
    int playerButtonHeight = playerBox->height() / field->getHeight();
    int playerButtonWidth = playerBox->width() / field->getWidth();

    playerButtons = new FieldButton*[field->getHeight()*field->getWidth()];

    for(int i = 0; i < field->getHeight(); i++)
        for(int j = 0; j < field->getWidth(); j++)
        {
            QRect rect(i*playerButtonHeight, j*playerButtonWidth, playerButtonHeight, playerButtonWidth);
            playerButtons[i*field->getWidth() + j] = new FieldButton(playerBox, rect, i*field->getWidth() + j);
        }
    return playerButtons;
}

void QtBattleShip::Initialization()
{
    this->currentSelectIndex = 0;
}

void QtBattleShip::SetSelectIndex(int selectIndex)
{
    this->currentSelectIndex = selectIndex;
}

void QtBattleShip::BuildButtons()
{
    this->firstPlayerButtons = this->ButtonArray(this->ui->firstPlayerBox, this->firstField);
    this->secondPlayerButtons = this->ButtonArray(this->ui->secondPlayerBox, this->secondField);

    for (int i = 0; i < this->secondField->getWidth()*this->secondField->getHeight(); i++)
        connect(this->secondPlayerButtons[i], SIGNAL(ClickButton(int)), this, SLOT(SetSelectIndex(int)));
}

void QtBattleShip::Update()
{
    for(int i = 0; i < this->firstField->getHeight(); i++)
            for(int j = 0; j < this->firstField->getWidth(); j++)
                this->firstPlayerButtons[i*this->firstField->getWidth() + j]->SetButtonValue(this->firstField->GetCellType(j, i));

    for(int i = 0; i < this->secondField->getHeight(); i++)
            for(int j = 0; j < this->secondField->getWidth(); j++)
                this->secondPlayerButtons[i*this->secondField->getWidth() + j]->SetButtonValue(this->secondField->GetCellType(j, i));
}

void QtBattleShip::MakeStep(int *x, int *y)
{
    QEventLoop loop;

    for (int i = 0; i < this->secondField->getWidth()*this->secondField->getHeight(); i++)
        connect(this->secondPlayerButtons[i], SIGNAL(ClickButton(int)), &loop, SLOT(quit()));
    loop.exec();

    *x = this->currentSelectIndex%this->firstField->getWidth();
    *y = this->currentSelectIndex/this->firstField->getWidth();
}
