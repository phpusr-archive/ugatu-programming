#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <string.h>
#include "DoubleLinkedList.h"

using namespace std;

/*
1 - сообщения об операцияях Creating, Adding, Deleting
2 - 1 и навания вспом функции create*, add*, del*
3 - 2 и функции print*
*/
int debugDouble = 0;

/* Выводит имя функци в заданном формате */
void printFunNameDouble(char* name) {
    printf("[DoubleLinkedList] >>%s :: \n", name);
}

/* Печатает структуру */
void printDub(int i, Dub* dub) {
    if (debugDouble > 2) printFunNameDouble("Print Dub");

    printf("%d: id: %d\t data: %s\t prev: %d\t next: %d\n", i, dub, dub->data, dub->prev, dub->next);
}

/* Создает структуру (инф. поле передается как параметр) */
Dub* createDub(char* data) {
    if (debugDouble > 1) printFunNameDouble("Create Dub");
    if (debugDouble > 1) cout<<"data="<<data<<endl;

    Dub* dub = new Dub();
    dub->data = data;
    dub->prev = 0;
    dub->next = 0;
    if (debugDouble) {
        cout<<"Creating:\t";
        printDub(0, dub);
    }

    return dub;
}

/* Создает структуру (инф. поле генерируется) */
Dub* createDub() {
    char* data = new char[20];
    sprintf(data, "data_%d", rand() % 100);
    return createDub(data);
}

/* Добавляет структуру в список */
Dub* addDub(Dub* beg, Dub* dub, int pos) {
    if (debugDouble > 1) printFunNameDouble("Add Dub");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        delete dub;
        return beg;
    }

    if (pos == 0) {
        dub->prev = 0;
        dub->next = beg;
        beg->prev = dub;
        if (debugDouble) {
            cout<<"Adding to the top: ";
            printDub(0, dub);
        }
        return dub;
    }

    Dub* cur = beg;
    int i = 0;
    while (cur != 0 && i < pos) {
        if (i == pos - 1) {
            dub->prev = cur;
            dub->next = cur->next;

            if (cur->next != 0) cur->next->prev = dub;
            cur->next = dub;
            if (debugDouble) {
                cout<<"Adding:\t\t";
                printDub(i+1, dub);
            }
        } else {
            cur = cur->next;
        }
        i++;
    }

    if (i < pos) {
        cout<<"Position "<<pos<<" not found!";
    }

    return beg;
}

/* Добавляет структуру в список после заданного информац. поля */
Dub* addDub(Dub* beg, Dub* dub, char* s) {
    if (debugDouble > 1) printFunNameDouble("Add Dub");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        delete dub;
        return beg;
    }

    Dub* cur = beg;
    int i = 0;
    bool find = false;
    while (cur != 0 && !find) {
        if (strcmp(cur->data, s) == 0) {
            find = true;
            dub->prev = cur;
            dub->next = cur->next;

            if (cur->next != 0) cur->next->prev = dub;
            cur->next = dub;
            if (debugDouble) {
                cout<<"Adding:\t\t";
                printDub(i+1, dub);
            }
        } else {
            cur = cur->next;
        }
        i++;
    }

    if (!find) {
        cout<<">>Tekst: \""<<s<<"\" ne naiden!"<<endl<<endl;
    }

    return beg;
}

/** Создает список */
Dub* createListDouble(int n) {
    printFunNameDouble("Create List");

    Dub* beg;
    beg = createDub("ROOT");

    srand(time(0));
    for(int i=0;i<n-1;i++) {
        addDub(beg, createDub(), i+1);
    }

    cout<<"List creating!"<<endl<<endl;

    return beg;
}

/** Печатает список */
void printListDouble(Dub* beg) {
    printFunNameDouble("Print List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        return;
    }

    Dub* cur = beg;
    int count = 0;
    while (cur !=0) {
        printDub(count, cur);
        cur = cur->next;
        count++;
    }
}

/** Обработка списка (вставляет структуру после элемента с заданным информационным полем) */
Dub* processingListDouble(Dub* beg, Dub* dub) {
    printFunNameDouble("Processing List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl<<endl;
        return beg;
    }

    char s[100];
    cout<<"Vvedite informat. pole: ";

    fflush(stdin);
    gets(s);

    cout<<"Insert: "; printDub(0, dub); cout<<endl;

    return addDub(beg, dub, s);
}

/** Удаляет список */
Dub* delListDouble(Dub* beg) {
    printFunNameDouble("Delete List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl<<endl;
        return beg;
    }

    Dub* cur = 0;
    int count = 0;
    while (beg != 0) {
        cur = beg;
        if (debugDouble) {
            cout<<"Deleting: ";
            printDub(count, cur);
        }
        beg = beg->next;
        delete cur;
        count++;
    }

    cout<<"List deleting!"<<endl<<endl;

    return beg;
}
