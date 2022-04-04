/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#ifndef BID_STACK_H
#define BID_STACK_H

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "types.h"


#define MAX 25
#define SNULL -1
typedef struct{
    tUserId bidder;
    tProductPrice productPrice;
}tItemS;
typedef int tPosS;
typedef struct {
    tItemS data[MAX];
    tPosS lastPos;
} tStack;

void createEmptyStack(tStack *S);
bool push(tItemS i, tStack *S);
void pop(tStack *S);
tItemS peek(tStack S);
bool isEmptyStack (tStack S);


#endif
