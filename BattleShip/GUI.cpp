#include <GUI.h>

GUI::~GUI()
{
    delete this->firstField;
    delete this->secondField;
}

void GUI::SetFirstField(Field &firstField)
{
    this->firstField = &firstField;
}

void GUI::SetSecondField(Field &secondField)
{
    this->secondField = &secondField;
}

GUI::GUI()
{

}
