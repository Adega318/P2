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

bool isEmptyList(tList L){
    return L==LNULL;
}

tPosL findItem(tProductId I, tList L){
    tPosL p;
    if(isEmptyList(L)) p=LNULL;
    else for(p=L; p!=LNULL && 0!=strcmp(p->data.productId, I); p=p->next);
    return p;
}

bool insertItem(tItemL I,tPosL P,tList *L){
    tPosL q,p;
    bool aux= 1;
    if(!createNode(&q)) aux=0;
    else{
        q->data=I;
        q->next=LNULL;
        if(*L==LNULL) *L=q;
        else if(strcmp(I.productId, (*L)->data.productId)<0){
            q->next= *L;
            *L= q;
        }
        else{
            p= findItem(I.productId, *L);
            q->next= p->next;
            p->next= q;
        }
    }
    return aux;
}