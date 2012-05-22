#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "Helper.h"
#include "lab9.h"
#include "cio.h"
#include "cppio.h"

using namespace std;

bool isClearScreen = true;

// TODO (phpusr#1#): Влияет только на вывод структуры
int debug = 2;

/** Выводит структуру */
void printStructure(int num, DVD* struc) {
    if (debug > 2) printFuncName("Print structure");

    printf("id:%d movie name: %s  director: %s\t duration: %.2f  price: %.2f\t\n", num, struc->name, struc->director, struc->duration, struc->price);
}

/** Возвращает список структур */
DVD* getDVDList(int count, char* name) {
    if (debug) printFuncName("Get DVD list");

    int SIZE_MESSAGE = 100;
    srand(time(0));
    DVD* list = new DVD[count];

    for(int i=0; i<count; i++) {
        sprintf(list[i].name, "%s_%d", name, rand() % 98 + 1);
        sprintf(list[i].director, "Dir_%d", rand() % 200);
        list[i].duration = rand() % 199 + 100;
        list[i].price = rand() % 100 + 1;

        if (debug > 1) {
            info(">>Generate:");
            printStructure(i, &list[i]);
        }
    }

    return list;
}

//////////////////////////////////////
int printMenu() {
    int i = 0;
    clrscr(isClearScreen);
    printMenuHeader("Stream Input Output C");
    printMenuItem(++i, "Create file");
    printMenuItem(++i, "Print file");
    printMenuItem(++i, "Delete elements");
    printMenuItem(++i, "Insert elements");

    printMenuHeader("Stream Input Output CPP");
    printMenuItem(++i, "Create file");
    printMenuItem(++i, "Print file");
    printMenuItem(++i, "Delete elements");
    printMenuItem(++i, "Insert elements");

    printMenuHeader(++i, "Exit");

    return i;
}

int main() {
    const int count = 8;
    int k = -1, countMenuItem;
    char* fileName = "data.txt";
    char* fileName2 = "data2.txt";

    cout<<"Lab 9"<<endl;
    cout<<"Debug Level: "<<debug<<endl;

    countMenuItem = printMenu();

    do {
        if (k != 0 && k != -1) cout<<endl<<"Press [0] to show menu or ["<<countMenuItem<<"] to exit..."<<endl;

        cin>>k;
        switch (k) {
            case 0: clrscr(isClearScreen); printMenu(); break;
            case 1: clrscr(isClearScreen); createAndPutFile(fileName, count); break;
            case 2: clrscr(isClearScreen); printFile(fileName); break;
            case 3: clrscr(isClearScreen); deleteElements(fileName); break;
            case 4: clrscr(isClearScreen); insertElements(fileName); break;

            case 5: clrscr(isClearScreen); createAndPutFileCPP(fileName2, count); break;
            case 6: clrscr(isClearScreen); printFileCPP(fileName2); break;
            case 7: clrscr(isClearScreen); deleteElementsCPP(fileName2); break;
            case 8: clrscr(isClearScreen); insertElementsCPP(fileName2); break;
        }
    } while (k != countMenuItem);
}
//////////////////////////////////////
