#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <fstream>
#include "cppio.h"
#include "lab9.h"
#include "Helper.h"

using namespace std;

int debugCPP = 0;


/** Заполняет файл из списка */
void putFileCPP(char* fileName, DVD* list, int count) {
    if (debugCPP) printFuncName("Put to file");

    fstream fp(fileName, ios::out);

    for (int i=0; i<count; i++) {
        fp<<list[i].name<<endl;
        fp<<list[i].director<<endl;
        fp<<list[i].duration<<endl;
        fp<<list[i].price<<endl;
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

    DVD bufer;
    int count = 0;
    while (!fp.eof()) {
        fp>>bufer.name;
        fp>>bufer.director;
        fp>>bufer.duration;
        fp>>bufer.price;
        if (fp.eof()) break;
        printStructure(count, &bufer);
        count++;
    }

    fp.close();
}

/** Создает и заполняет файл */
void createAndPutFileCPP(char* fileName, int count) {
    printFuncName("Create and put file");

    putFileCPP(fileName, getDVDList(count, "Ivan"), count);

    info("File created and formed");
}

/** Удаляет диски из файла, с ценой выше заданной */
void deleteElementsCPP(char* fileName) {
    printFuncName("Delete elements");

    int price;
    cout<<"Enter price: ";
    cin>>price;

    if (price <= 0 || price > 1000) {
        warn("Wrong price");
        return;
    }

    char* nameTmpFile = "tmp.txt";
    fstream fp(fileName, ios::in);
    fstream tmp(nameTmpFile, ios::out);
    bool isDel = false;

    DVD bufer;
    int count = 0;
    while (!fp.eof()) {
        fp>>bufer.name;
        fp>>bufer.director;
        fp>>bufer.duration;
        fp>>bufer.price;
        if (fp.eof()) break;

        if (bufer.price <= price) {
            tmp<<bufer.name<<endl;
            tmp<<bufer.director<<endl;
            tmp<<bufer.duration<<endl;
            tmp<<bufer.price<<endl;
        } else {
            isDel = true;
            info("Deleting: ");
            printStructure(count, &bufer);
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

/** Вставляет элементы в указанную позицию */
void insertElementsCPP(char* fileName) {
    printFuncName("Insert elements");

    int n = 1; //Количество вставляемых элементов
    int k; //Позиция для вставки

    cout<<"Enter k: ";
    cin>>k;
    if (k < 0 || k > 100) {
        warn("Wrong k");
        return;
    }

    DVD* list = getDVDList(n, "INSERT");

    char* nameTmpFile = "tmp.txt";
    fstream fp(fileName, ios::in);
    fstream tmp(nameTmpFile, ios::out);
    int count = 0, curCount = 0;
    bool isFindPos = false, eof = false;

    DVD bufer;
    while (curCount <= k || !eof) {
        if (curCount == k && curCount <= count) {
            isFindPos = true;
            for (int i=0; i<n; i++) {
                tmp<<list[i].name<<endl;
                tmp<<list[i].director<<endl;
                tmp<<list[i].duration<<endl;
                tmp<<list[i].price<<endl;
                if (debugCPP) {
                    info("Adding:");
                    printStructure(curCount + i, &list[i]);
                }
            }
        }

        if (!fp.eof()) {

            fp>>bufer.name;
            fp>>bufer.director;
            fp>>bufer.duration;
            fp>>bufer.price;

            if (!fp.eof()) {
                tmp<<bufer.name<<endl;
                tmp<<bufer.director<<endl;
                tmp<<bufer.duration<<endl;
                tmp<<bufer.price<<endl;
                count++;
            }
        } else {
            eof = true;
        }
        curCount++;
    }

    fp.close();
    tmp.close();
    remove(fileName);
    rename(nameTmpFile, fileName);

    if (!isFindPos) {
        warn("Wrong k");
    }
}
