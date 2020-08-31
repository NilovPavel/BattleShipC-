/***********************************************************************
 * Module:  Cui.h
 * Author:  nilov_pg
 * Modified: 17 июля 2020 г. 15:38:15
 * Purpose: Declaration of the class Cui
 ***********************************************************************/
#include <iostream>

using namespace std;

#if !defined(__BattleShip_Cui_h)
#define __BattleShip_Cui_h

class Field;

#include <GUI.h>
#include <Field.h>

class Cui : public GUI
{
public:
   Cui();
   ~Cui();
   void Update(void);

protected:
private:
};

#endif
