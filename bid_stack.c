/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "bid_stack.h"

void createEmptyStack(tStack *S){
    S->lastPos= SNULL;
}

bool push(tItemS i, tStack *S){
    bool aux;
    if(S->lastPos >= MAX-1) aux= 0;
    else{
        S->lastPos++;
        S->data[S->lastPos]= i;
        aux= 1;
    }
    return aux;
}

void pop(tStack *S){
    S->lastPos--;
}

tItemS peek(tStack S){
   return S.data[S.lastPos];
}

bool isEmptyStack (tStack S){
    return S.lastPos == SNULL;
}