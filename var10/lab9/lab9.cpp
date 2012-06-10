#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <ctime>
#include "Helper.h"
#include "lab9.h"
#include "cio.h"
#include "cppio.h"

using namespace std;

bool isCS = true;

int debug = 2;

/** Выводит структуру */
void printStructure(int num, Inf* struc) {
    if (debug > 2) printFuncName("Print structure");

    printf("id:%d Inf:: media: %s\  volume: %.2f  name: %s author: %s\n", num, struc->media, struc->volume, struc->name, struc->author);
}

/** Возвращает список структур */
Inf* getInfList(int count, char* name) {
    if (debug) printFuncName("Get Inf list");

    int SIZE_MESSAGE = 100;
    srand(time(0));
    Inf* list = new Inf[count];

    for(int i=0; i<count; i++) {
        sprintf(list[i].media, "disk_%d", rand() % 90 + 10);
        list[i].volume = (float)(rand() % 100) / 10;
        sprintf(list[i].name, "%s_%d", name, rand() % 90 + 10);
        sprintf(list[i].author, "Semen_%d", rand() % 200);

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
    clrscr(isCS);
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
    char* name = "Kniga";

    cout<<"Lab 9"<<endl;
    cout<<"Debug Level: "<<debug<<endl;

    countMenuItem = printMenu();

    do {
        if (k != 0 && k != -1) cout<<endl<<"Press [0] to show menu or ["<<countMenuItem<<"] to exit..."<<endl;

        cin>>k;
        switch (k) {
            case 0: clrscr(isCS); printMenu(); break;
            case 1: clrscr(isCS); createAndPutFile(fileName, count, name); break;
            case 2: clrscr(isCS); printFile(fileName); break;
            case 3: clrscr(isCS); deleteElements(fileName); break;
            case 4: clrscr(isCS); insertElements(fileName); break;

            case 5: clrscr(isCS); createAndPutFileCPP(fileName2, count); break;
            case 6: clrscr(isCS); printFileCPP(fileName2); break;
            case 7: clrscr(isCS); deleteElementsCPP(fileName2); break;
            case 8: clrscr(isCS); insertElementsCPP(fileName2); break;
        }
    } while (k != countMenuItem);
}
//////////////////////////////////////
