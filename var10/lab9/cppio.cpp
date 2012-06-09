#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "cppio.h"
#include "lab9.h"
#include "Helper.h"

using namespace std;

int debugCPP = 0;


/* Заполняет файл из списка */
void putFileCPP(char* fileName, Inf* list, int count) {
    if (debugCPP) printFuncName("Put to file");

    fstream fp(fileName, ios::out);

    for (int i=0; i<count; i++) {
        fp<<list[i].media<<endl;
        fp<<list[i].volume<<endl;
        fp<<list[i].name<<endl;
        fp<<list[i].author<<endl;
        if (debugCPP) {
            info("Adding:");
            printStructure(i, &list[i]);
        }
    }

    fp.close();
}

/** Печатает содержимое файла */
void printFileCPP(char* fileName) {
    printFuncName("Print file");

    fstream fp(fileName, ios::in);

    Inf bufer;
    int count = 0;
    while (!fp.eof()) {
        fp>>bufer.media;
        fp>>bufer.volume;
        fp>>bufer.name;
        fp>>bufer.author;
        if (fp.eof()) break;
        printStructure(count, &bufer);
        count++;
    }

    fp.close();
}

/** Создает и заполняет файл */
void createAndPutFileCPP(char* fileName, int count) {
    printFuncName("Create and put file");

    putFileCPP(fileName, getInfList(count, "Ivan"), count);

    info("File created and formed");
}

/** Удаляет первый элемент с ценой выше заданной */
void deleteElementsCPP(char* fileName) {
    printFuncName("Delete elements");

    float volume;
    cout<<"Enter volume: ";
    cin>>volume;

    if (volume <= 0 || volume > 10000) {
        warn("Wrong volume");
        return;
    }

    char* nameTmpFile = "tmp.txt";
    fstream fp(fileName, ios::in);
    fstream tmp(nameTmpFile, ios::out);
    bool isDel = false;

    Inf bufer;
    int count = 0;
    while (!fp.eof()) {
        fp>>bufer.media;
        fp>>bufer.volume;
        fp>>bufer.name;
        fp>>bufer.author;
        if (fp.eof()) break;

        if (bufer.volume == volume && !isDel) {
            isDel = true;
            info("Deleting: ");
            printStructure(count, &bufer);
        } else {
            tmp<<bufer.media<<endl;
            tmp<<bufer.volume<<endl;
            tmp<<bufer.name<<endl;
            tmp<<bufer.author<<endl;
        }
        count++;
    }

    fp.close();
    tmp.close();
    remove(fileName);
    rename(nameTmpFile, fileName);

    if (!isDel) {
        info("Nothing delete!");
    }
}

/** Добавляет K элементов в конец файла */
void insertElementsCPP(char* fileName) {
    printFuncName("Insert elements");

    int k; //Количество вставляемых элементов

    cout<<"Enter k: ";
    cin>>k;
    if (k <= 0 || k > 100) {
        warn("Wrong k");
        return;
    }

    Inf* list = getInfList(k, "INSERT");

    ofstream fp(fileName, ios::app);

    Inf bufer;
    for(int i=0; i<k; i++) {
        fp<<list[i].media<<endl;
        fp<<list[i].volume<<endl;
        fp<<list[i].name<<endl;
        fp<<list[i].author<<endl;
        if (debugCPP) {
            info("Adding:");
            printStructure(i, &list[i]);
        }
    }

    fp.close();
}
