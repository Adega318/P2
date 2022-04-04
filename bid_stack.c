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
    S->top= SNULL;
}

bool push(tItemS i, tStack *S){
    bool aux;
    if(S->top >= MAX - 1) aux= 0;
    else{
        S->top++;
        S->data[S->top]= i;
        aux= 1;
    }
    return aux;
}

void pop(tStack *S){
    S->top--;
}

tItemS peek(tStack S){
   return S.data[S.top];
}

bool isEmptyStack (tStack S){
    return S.top == SNULL;
}