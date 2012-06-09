#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "cio.h"
#include "lab9.h"
#include "Helper.h"

using namespace std;

int debugC = 0;

/* Открывает или создает файл */
FILE* openFile(char* fileName, char* mode) {
    if (debugC > 1) printFuncName("Open file");

    FILE *fp;
    if ((fp = fopen(fileName, mode)) == NULL) {
        perror(getErrorString("Error open file\n"));
        exit(0);
    }

    if (debugC) cout<<">>Open or create file: "<<fileName<<" mode: "<<mode<<endl;

    return fp;
}

/* Заполняет файл из списка */
void putFile(char* fileName, Inf* list, int count) {
    if (debugC) printFuncName("Put to file");

    FILE* fp = openFile(fileName, "w");

    for (int i=0; i<count; i++) {
        fwrite(&list[i], sizeof(Inf), 1, fp);
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

    Inf bufer;
    int count = 0;
    while (fread(&bufer, sizeof(Inf), 1, fp)) {
        printStructure(count, &bufer);
        count++;
    }

    fclose(fp);
}

/** Создает и заполняет файл */
void createAndPutFile(char* fileName, int count, char* name) {
    printFuncName("Create and put file");

    putFile(fileName, getInfList(count, name), count);

    info("File created and formed");
}

/** Удаляет первый элемент с ценой выше заданной */
void deleteElements(char* fileName) {
    printFuncName("Delete elements");

    float volume;
    cout<<"Enter volume: ";
    cin>>volume;

    if (volume <= 0 || volume > 10000) {
        warn("Wrong volume");
        return;
    }

    char* nameTmpFile = "tmp.txt";
    FILE* fp = openFile(fileName, "r");
    FILE* tmp = openFile(nameTmpFile, "w");
    bool isDel = false;

    Inf bufer;
    int count = 0;
    while (fread(&bufer, sizeof(Inf), 1, fp)) {
        if (bufer.volume == volume && !isDel) {
            isDel = true;
            info("Deleting: ");
            printStructure(count, &bufer);
        } else {
            fwrite(&bufer, sizeof(Inf), 1, tmp);
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

/** Добавляет K элементов в конец файла */
void insertElements(char* fileName) {
    printFuncName("Insert elements");

    int k; //Количество вставляемых элементов

    cout<<"Enter k: ";
    cin>>k;
    if (k <= 0 || k > 100) {
        warn("Wrong k");
        return;
    }

    Inf* list = getInfList(k, "INSERT");

    char* nameTmpFile = "tmp.txt";
    FILE* fp = openFile(fileName, "a");

    for(int i=0; i<k; i++) {
        fwrite(&list[i], sizeof(Inf), 1, fp);
        if (debugC) {
            info("Adding:");
            printStructure(i, &list[i]);
        }
    }

    fclose(fp);
}
