/***********************************************************************
 * Module:  Cui.cpp
 * Author:  nilov_pg
 * Modified: 17 ���� 2020 �. 15:38:15
 * Purpose: Implementation of the class Cui
 ***********************************************************************/

#include "Field.h"
#include "Cui.h"

////////////////////////////////////////////////////////////////////////
// Name:       Cui::Cui(Field& firstField, Field secondField)
// Purpose:    Implementation of Cui::Cui()
// Parameters:
// - firstField
// - secondField
// Return:     
////////////////////////////////////////////////////////////////////////

Cui::Cui() : GUI()
{
}

////////////////////////////////////////////////////////////////////////
// Name:       Cui::~Cui()
// Purpose:    Implementation of Cui::~Cui()
// Return:     
////////////////////////////////////////////////////////////////////////

Cui::~Cui()
{
   // TODO : implement
}

////////////////////////////////////////////////////////////////////////
// Name:       Cui::Update()
// Purpose:    Implementation of Cui::Update()
// Return:     void
////////////////////////////////////////////////////////////////////////

void Cui::Update(void)
{
    for(int i = 0; i < this->firstField->getHeight(); i++)
    {
        cout << i << ' ';
        for(int j = 0; j < this->firstField->getWidth(); j++)
            cout << (int)this->firstField->GetCellType(j, i);

        cout << '\t';

        for(int j = 0; j < this->secondField->getWidth(); j++)
            cout << (int)this->secondField->GetCellType(j, i);
        cout << endl;
    }
    cout << endl;
}
