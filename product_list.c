/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1:Enrique Adega Fernandez  LOGIN 1: e.adega@udc.es
 * AUTHOR 2:Pablo Vilariño Piñon LOGIN 2: pablo.vilarinop@udc.es
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include "product_list.h"

bool createNode(tPosL *P){
    *P=malloc(sizeof(struct tNode));
    return *P!=LNULL;
}

bool insertItem(tItemL I,tPosL P,tList *L){
    tPosL q,p;
    bool aux;
    if(!createNode(&q)) aux=0;
    else{
        q->data=I;
        q->next=LNULL;
        if(*L==LNULL) *L=q;
        else if(strcmp(I.productId, (*L)->data.productId)<0)
    }
}