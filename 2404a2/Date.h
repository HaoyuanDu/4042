/* * * * * * * * * * * * * * * * * * * * * * * * * */
/*                                                 */
/*  Program:  Simple Inventory System              */
/*  Author:   Christine Laurendeau                 */
/*  Date:     28-JUN-2016                          */
/*                                                 */
/*  (c) 2016 Christine Laurendeau                  */
/*  All rights reserved.  Distribution and         */
/*  reposting, in part or in whole, without the    */
/*  written consent of the author, is illegal.     */
/*                                                 */
/* * * * * * * * * * * * * * * * * * * * * * * * * */

#ifndef DATE_H
#define DATE_H

#include <string>
using namespace std;
#include "defs.h"

class Date
{
  public:
    Date(int=0, int=0, int=0);
    Date&   operator+=(int);
    Date   operator+(int);
    bool   operator>(Date&);
    void toString(string& outStr);
  private:
    int day;
    int month;
    int year;
    
};


#endif
