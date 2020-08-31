/***********************************************************************
 * Module:  IUserManipulator.h
 * Author:  nilov_pg
 * Modified: 10 июля 2020 г. 10:44:31
 * Purpose: Declaration of the class IUserManipulator
 ***********************************************************************/

#if !defined(__BattleShip_IUserManipulator_h)
#define __BattleShip_IUserManipulator_h

class IUserManipulator
{
public:
   virtual void MakeStep(int *x, int *y)=0;

protected:
private:

};

#endif
