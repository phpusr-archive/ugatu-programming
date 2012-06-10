#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "cio.h"
#include "lab9.h"
#include "Helper.h"

using namespace std;

int debugC = 0;

/** Открывает или создает файл */
FILE* openFile(char* fileName, char* mode) {
    if (debugC > 1) printDopFuncName("Open file");

    FILE *fp;
    if ((fp = fopen(fileName, mode)) == NULL) {
        perror(getErrorString("Error open file\n"));
        exit(0);
    }

    if (debugC) cout<<">>Open or create file: "<<fileName<<" mode: "<<mode<<endl;

    return fp;
}

/** Заполняет файл из списка */
void putFile(char* fileName, People* list, int count) {
    if (debugC) printDopFuncName("Put to file");

    FILE* fp = openFile(fileName, "w");

    for (int i=0; i<count; i++) {
        fwrite(&list[i], sizeof(People), 1, fp);
        if (debugC) {
            info("Adding:");
            printStructure(i, &list[i]);
        }
    }

    fclose(fp);
}

/** Печатает содержимое файла */
void printFile(char* fileName) {
    printFuncName("Print file");

    FILE *fp = openFile(fileName, "r");

    People bufer;
    int count = 0;
    while (fread(&bufer, sizeof(People), 1, fp)) {
        printStructure(count, &bufer);
        count++;
    }

    fclose(fp);
}

/** Создает и заполняет файл */
void createAndPutFile(char* fileName, int count) {
    printFuncName("Create and put file");

    putFile(fileName, getPeopleList(count, "Vasya"), count);

    info("File created and formed");
}

/** Удаляет людей из файла, по заданному возрасту */
void deleteElements(char* fileName) {
    printFuncName("Delete elements");

    int age;
    cout<<"Enter age: ";
    cin>>age;

    if (age <= 0 || age > 150) {
        warn("Wrong age");
        return;
    }

    char* nameTmpFile = "tmp.txt";
    FILE* fp = openFile(fileName, "r");
    FILE* tmp = openFile(nameTmpFile, "w");
    bool isDel = false;

    People bufer;
    int count = 0;
    while (fread(&bufer, sizeof(People), 1, fp)) {
        if (bufer.age != age) {
            fwrite(&bufer, sizeof(People), 1, tmp);
        } else {
            isDel = true;
            info("Deleting: ");
            printStructure(count, &bufer);
        }
        count++;
    }

    fclose(fp);
    fclose(tmp);
    remove(fileName);
    rename(nameTmpFile, fileName);

    if (!isDel) {
        info("Nothing delete!");
    }
}

/** Вставляет элементы в указанную позицию */
void insertElements(char* fileName) {
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
    FILE* fp = openFile(fileName, "r");
    FILE* tmp = openFile(nameTmpFile, "w");
    int count = 0, curCount = 0;
    bool isFindPos = false, eof = false;

    People bufer;
    while (curCount <= k || !eof) {
        if (curCount == k && curCount <= count) {
            isFindPos = true;
            for (int i=0; i<n; i++) {
                fwrite(&list[i], sizeof(People), 1, tmp);
                if (debugC) {
                    info("Adding:");
                    printStructure(curCount + i, &list[i]);
                }
            }
        }

        if (fread(&bufer, sizeof(People), 1, fp)) {
            fwrite(&bufer, sizeof(People), 1, tmp);
            count++;
        } else {
            eof = true;
        }
        curCount++;
    }

    fclose(fp);
    fclose(tmp);
    remove(fileName);
    rename(nameTmpFile, fileName);

    if (!isFindPos) {
        warn("Wrong k");
    } else {
        info("Insert done");
    }
}
