/***********************************************************************
 * Module:  Ui.h
 * Author:  nilov_pg
 * Modified: 17 июля 2020 г. 15:35:34
 * Purpose: Declaration of the class Ui
 ***********************************************************************/

#if !defined(__BattleShip_Ui_h)
#define __BattleShip_Ui_h

#include <Field.h>

class GUI
{
public:
   void SetFirstField(Field &firstField);
   void SetSecondField(Field &secondField);
   virtual void Update(void)=0;
   GUI();
   virtual ~GUI();

protected:
   Field *firstField;
   Field *secondField;
private:

};

#endif
