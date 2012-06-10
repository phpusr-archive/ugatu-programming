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
void putFileCPP(char* fileName, People* list, int count) {
    if (debugCPP) printDopFuncName("Put to file");

    fstream fp(fileName, ios::out);

    for (int i=0; i<count; i++) {
        fp<<list[i].fio<<endl;
        fp<<list[i].adres<<endl;
        fp<<list[i].phone<<endl;
        fp<<list[i].age<<endl;
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

    People bufer;
    int count = 0;
    while (!fp.eof()) {
        fp>>bufer.fio;
        fp>>bufer.adres;
        fp>>bufer.phone;
        fp>>bufer.age;
        if (fp.eof()) break;
        printStructure(count, &bufer);
        count++;
    }

    fp.close();
}

/** Создает и заполняет файл */
void createAndPutFileCPP(char* fileName, int count) {
    printFuncName("Create and put file");

    putFileCPP(fileName, getPeopleList(count, "Ivan"), count);

    info("File created and formed");
}

/** Удаляет людей из файла, по заданному возрасту */
void deleteElementsCPP(char* fileName) {
    printFuncName("Delete elements");

    int age;
    cout<<"Enter age: ";
    cin>>age;

    if (age <= 0 || age > 150) {
        warn("Wrong age");
        return;
    }

    char* nameTmpFile = "tmp.txt";
    fstream fp(fileName, ios::in);
    fstream tmp(nameTmpFile, ios::out);
    bool isDel = false;

    People bufer;
    int count = 0;
    while (!fp.eof()) {
        fp>>bufer.fio;
        fp>>bufer.adres;
        fp>>bufer.phone;
        fp>>bufer.age;
        if (fp.eof()) break;

        if (bufer.age != age) {
            tmp<<bufer.fio<<endl;
            tmp<<bufer.adres<<endl;
            tmp<<bufer.phone<<endl;
            tmp<<bufer.age<<endl;
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

// TODO (phpusr#1#): Переделать под CPP!
/** Вставляет элементы в указанную позицию */
void insertElementsCPP(char* fileName) {
    printFuncName("Insert elements");

    int n,k;

    cout<<"Enter n: ";
    cin>>n;
    if (n <= 0 || n > 10) {
        warn("Wrong n");
        return;
    }

    cout<<"Enter k: ";
    cin>>k;
    if (k < 0 || k > 100) {
        warn("Wrong k");
        return;
    }

    People* list = getPeopleList(n, "INSERT");

    char* nameTmpFile = "tmp.txt";
    fstream fp(fileName, ios::in);
    fstream tmp(nameTmpFile, ios::out);
    int count = 0, curCount = 0;
    bool isFindPos = false, eof = false;

    People bufer;
    while (curCount <= k || !eof) {
        if (curCount == k && curCount <= count) {
            isFindPos = true;
            for (int i=0; i<n; i++) {
                tmp<<list[i].fio<<endl;
                tmp<<list[i].adres<<endl;
                tmp<<list[i].phone<<endl;
                tmp<<list[i].age<<endl;
                if (debugCPP) {
                    info("Adding:");
                    printStructure(curCount + i, &list[i]);
                }
            }
        }

        if (!fp.eof()) {

            fp>>bufer.fio;
            fp>>bufer.adres;
            fp>>bufer.phone;
            fp>>bufer.age;

            if (!fp.eof()) {
                tmp<<bufer.fio<<endl;
                tmp<<bufer.adres<<endl;
                tmp<<bufer.phone<<endl;
                tmp<<bufer.age<<endl;
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
    } else {
        info("Insert done");
    }
}
