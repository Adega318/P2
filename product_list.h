/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef PRODUCT_LIST_H
#define PRODUCT_LIST_H

#include <string.h>
#include "types.h"
#include "bid_stack.h"


#define LNULL NULL
typedef struct{
    tUserId seller;
    tProductId productId;
    tProductCategory productCategory;
    tProductPrice productPrice;
    tBidCounter bidCounter;
    tStack bidstack;
}tItemL;
typedef struct tNode *tPosL;
struct tNode{
    tItemL data;
    tPosL next;
};
typedef tPosL tList;


#endif
