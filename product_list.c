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

void createEmptyList(tList *L){
    *L=LNULL;
}

bool isEmptyList(tList L){
    return L==LNULL;
}

tPosL first(tList L){
    return L;
}

tPosL last(tList L){
    tPosL p;
    for(p=L; p->next!=LNULL; p=p->next);
    return p;
}

tPosL next(tPosL P, tList L){
    return P->next;
}

tPosL previous(tPosL P, tList L){
    tPosL p;
    if(P==L) p=LNULL;
    else for(p=L; p->next!=P; p=p->next);
    return p;
}
//Mirar de optimizar

tPosL findItem(tProductId I, tList L){
    tPosL p;
    if (isEmptyList(L)) p=LNULL;
    else for(p=L; p!=LNULL && p->data.productId!=I && strcmp(I, p->data.productId)>0; p= next(p, L));
    return p;   
}

bool insertItem(tItemL I,tList *L){
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

void updateItem(tItemL I, tPosL P, tList *L){
    P->data=I;
}

tItemL getItem(tPosL P, tList L){
    return P->data;
}

void deleteAtPosition(tPosL P,tList *L){
    if(P!=LNULL && !isEmptyStack(P->data.bidstack)){
        tPosL q;
        if(P == *L) *L= P->next;
        else if(P->next == LNULL){
            for(q= *L; q->next!=P; q= q->next);
            q->next= LNULL;
        }else {
            q= P->next;
            P->data= q->data;
            P->next= q->next;
            P= q;
        }
        free(P);
    }
}
