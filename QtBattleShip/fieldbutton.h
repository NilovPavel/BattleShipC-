#ifndef FIELDBUTTON_H
#define FIELDBUTTON_H

#include <QGroupBox>
#include <QPushButton>
#include <ECellType.h>
#include <QDir>
#include <QObject>

class FieldButton : public QPushButton
{
    Q_OBJECT
public:
    int index;
public:
    FieldButton(QGroupBox *box, QRect rect, int index);
    void SetButtonValue(ECellType eCellType);
public:
signals:
    void ClickButton(int index);

    // QWidget interface
protected:
    void mousePressEvent(QMouseEvent *event);
};

#endif // FIELDBUTTON_H
