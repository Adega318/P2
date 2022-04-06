/*
 * TITLE: PROGRAMMING II LABS
 * SUBTITLE: Practical 2
 * AUTHOR 1: ***************************** LOGIN 1: **********
 * AUTHOR 2: ***************************** LOGIN 2: **********
 * GROUP: *.*
 * DATE: ** / ** / **
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"
#include "product_list.h"

#define MAX_BUFFER 255

void setItem(char *Id, char *Seller, char *Category, char *Price, tList *L);
void seeStats(tList L);

void processCommand(char *commandNumber, char command, char *param1, char *param2, char *param3, char *param4, tList *L) {
    bool aux=0;
    switch (command) {
        case 'N':
            printf("********************\n%s N: product %s seller %s category %s price %.2f\n", commandNumber, param1, param2, param3, atof(param4));
            setItem(param1, param2, param3, param4, L);

            break;
        case 'S':
            printf("********************\n%s S\n", commandNumber);
            if(isEmptyList(*L)==1) printf("+ Error: Stats not possible\n"); //Comprobamos que la lista no esta vacía
            else {
                seeStats(*L); //Mostramos los datos y contenidos en la lista L y sus estadísticas
            }
            //
            break;
        case 'B':
            //
            break;
        case 'D':
            break;
        case 'A':
            break;
        case 'W':
            break;
        case 'R':
            break;
        default:
            break;
    }
}

void readTasks(char *filename) {
    FILE *f = NULL;
    char *commandNumber, *command, *param1, *param2, *param3, *param4;
    const char delimiters[] = " \n\r";
    char buffer[MAX_BUFFER];

    f = fopen(filename, "r");

    tList L;
    createEmptyList(&L);

    if (f != NULL) {

        while (fgets(buffer, MAX_BUFFER, f)) {
            commandNumber = strtok(buffer, delimiters);
            command = strtok(NULL, delimiters);
            param1 = strtok(NULL, delimiters);
            param2 = strtok(NULL, delimiters);
            param3 = strtok(NULL, delimiters);
            param4 = strtok(NULL, delimiters);

            processCommand(commandNumber, command[0], param1, param2, param3, param4, &L);
        }

        fclose(f);

    } else {
        printf("Cannot open file %s.\n", filename);
    }
}


int main(int nargs, char **args) {

    char *file_name = "new.txt";

    if (nargs > 1) {
        file_name = args[1];
    } else {
        #ifdef INPUT_FILE
        file_name = INPUT_FILE;
        #endif
    }

    readTasks(file_name);

    return 0;
}

void setItem(char *Id, char *Seller, char *Category, char *Price, tList *L){
    if(findItem(Id, *L)==LNULL){
        tItemL i;
        strcpy(i.productId, Id);
        strcpy(i.seller, Seller);
        if (strcmp(Category, "book") == 0) i.productCategory= book; //comprobamos si la categoria es "book", le damos valor al campo productCategory "book"
        else i.productCategory= painting;
        i.productPrice= atof(Price);
        i.bidCounter= 0;
        createEmptyStack(&(i.bidstack));
        if(insertItem(i, L)==1){
            printf("* New: product %s seller %s category %s price %.2f\n", Id, Seller, Category, i.productPrice);
        } else printf("+ Error: New not possible\n");
    }else printf("+ Error: New not possible\n");
}

char *categoryString(tItemL I){
    if (I.productCategory == book) {  //comprobamos si es libro
        return "book";  //si lo es devolvemos "book"
    } else {
        return "painting"; //en caso contrario devolvemos "painting"
    }
}

void seeStats(tList L){
    tItemL i, incre;
    tPosL p= first(L); //damos valor a p, primera posición de la lista
    int contB= 0, contP= 0;
    float sumB= 0, sumP= 0;
    float medB= 0, medP= 0;
    float increment, memoryIncre=0;

    do{
        i= getItem(p, L); //obtenemos el item en p
        if (i.productCategory == book) { //comprobamos si la categoria es libro
            contB++; //Aumentamos el contador de libros
            sumB+= i.productPrice; //Sumamos el precio al total de los libros
        } else {
            contP++; //Aumentamos el contador de pinturas
            sumP+= i.productPrice; //Sumamos el precio al total de las pinturas
        }

        if(i.bidstack.top!=SNULL) increment= peek(i.bidstack).productPrice/i.productPrice;
        else increment=0;
        if(increment>memoryIncre){
            memoryIncre= increment;
            incre=i;
        }

        printf("Product %s seller %s category %s price %.2f. ", i.productId, i.seller, categoryString(i), i.productPrice); //imprimimos las caracteristicas del item
        if(i.bidCounter!=0){
            printf("bids %d top bider %s\n",i.bidCounter, peek(i.bidstack).bidder);
        }else{
            printf("No bids\n");
        }
        p= next(p, L); //cogemos el siguiente de p
    }while (p != LNULL); //Paramos cundo se llega al final de la lista

    if(contB != 0) medB= sumB/contB; //media de libros
    if(contP != 0) medP= sumP/contP; //media de pinturas

    printf("\nCategory  Products    Price  Average\nBook      %8d %8.2f %8.2f\nPainting  %8d %8.2f %8.2f\n", contB, sumB, medB, contP, sumP, medP);
    if(memoryIncre!=0) printf("Top bid: Product %s seller %s category %s price %.2f bidder %s top price %.2f increase %.2f%%\n", incre.productId, incre.seller,
                              categoryString(incre), incre.productPrice, peek(incre.bidstack).bidder, peek(incre.bidstack).productPrice, memoryIncre*100);
    else printf("Top bid not possible\n");
}

