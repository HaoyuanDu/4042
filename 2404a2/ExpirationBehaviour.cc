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
using namespace std;
#include "ExpirationBehaviour.h"



Date Perishable::computeExpDate(Date& mfDate,int sp)
{ 
  return mfDate+sp;

}
Date NonPerishable::computeExpDate(Date& mfDate,int sp)
{ 
  return mfDate+MAX_EXP;

}
