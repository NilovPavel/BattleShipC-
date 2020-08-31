#include "fieldbutton.h"

FieldButton::FieldButton(QGroupBox *box, QRect rect, int index) : QPushButton(box)
{
    this->index = index;
    this->setGeometry(rect);
}

void FieldButton::SetButtonValue(ECellType eCellType)
{
    QString currentPath = QDir::currentPath() + "/Icons/" + QString::number((int)eCellType) + ".ico";
    QPixmap pixmap(currentPath);
    QIcon icon = QIcon(pixmap);
    this->setIcon(icon);
    if(eCellType != ECellType::empty)
        this->setEnabled(false);
}

void FieldButton::mousePressEvent(QMouseEvent *event)
{
    emit this->ClickButton(this->index);
}
