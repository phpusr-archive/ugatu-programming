#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "SinglyLinkedList.h"

using namespace std;

/*
1 - сообщения об операцияях Creating, Adding, Deleting
2 - 1 и навания вспом функции create*, add*, del*
3 - 2 и функции print*
*/
int debug = 0;

/* Выводит имя функци в заданном формате */
void printFunName(char* name) {
    printf(">>%s :: \n", name);
}

/* Печатает структуру */
void printHot(int i, Hot* hot) {
    if (debug > 2) printFunName("Print Hot");

    printf("%d. id:%d\t data: %.5f\t next: %d\n", i, hot, hot->data, hot->next);
}

/* Создает структуру */
Hot* createHot() {
    if (debug > 1) printFunName("Create Hot");

    Hot* hot = new Hot();
    hot->data = (float)(rand() % 100) / (rand() % 10);
    hot->next = 0;
    if (debug) {
        cout<<"Creating:\t";
        printHot(0, hot);
    }

    return hot;
}

/* Добавляет структуру в список */
Hot* addHot(Hot* beg, Hot* hot, int pos) {
    if (debug > 1) printFunName("Add Hot");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        delete hot;
        return beg;
    }

    if (pos == 0) {
        hot->next = beg;
        if (debug) {
            cout<<"Adding to the top: ";
            printHot(0, hot);
        }
        return hot;
    }

    Hot* cur = beg;
    int i = 0;
    while (cur != 0 && i < pos) {
        if (i == pos - 1) {
            hot->next = cur->next;
            cur->next = hot;
            if (debug) {
                cout<<"Adding:\t\t";
                printHot(i+1, hot);
            }
        } else {
            cur = cur->next;
        }
        i++;
    }

    return beg;
}

/* Создает список */
Hot* createList(int n) {
    printFunName("Create List");

    Hot* beg;
    beg = createHot();

    srand(time(0));
    for(int i=0;i<n-1;i++) {
        addHot(beg, createHot(), i+1);
    }

    cout<<"List creating!"<<endl<<endl;

    return beg;
}

/** Печатает список */
void printList(Hot* beg) {
    printFunName("Print List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        return;
    }

    Hot* cur = beg;
    int count = 0;
    while (cur !=0) {
        printHot(count, cur);
        cur = cur->next;
        count++;
    }
}

/** Удаляет элемент списка по номеру */
Hot* delHot(Hot* beg, int pos) {
    if (debug > 1) printFunName("Del Hot");

    if (beg == 0) {
        cout<<"List is empty!"<<endl;
        return beg;
    }

    Hot* cur;
    if (pos == 0) {
        cur = beg->next;
        if (debug) {
            cout<<"Deleting from the begining: ";
            printHot(0, beg);
        }
        delete beg;
        return cur;
    }

    cur = beg;
    int i = 0;
    while (cur != 0 && i < pos) {
        if (i == pos - 1) {
            Hot* delHot = cur->next;
            cur->next = cur->next->next;
            if (debug) {
                cout<<"Deleting:\t";
                printHot(i+1, delHot);
            }
            delete delHot;
        } else {
            cur = cur->next;
        }
        i++;
    }

    return beg;
}

/** Обработка списка (Удаляет из списка все элементы с четными номерами (0, 2, 4, 6 и. т. д.) */
Hot* processingList(Hot* beg) {
    printFunName("Processing List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl<<endl;
        return beg;
    }

    Hot *cur = beg, *hot;
    int count = 0, i = 0;
    while (cur !=0) {
        i++;
        if (i % 2 == 1) {
            hot = cur;
            cur = cur->next;
            cout<<"Deleting: ";
            printHot(count, hot);
            beg = delHot(beg, count);
        } else {
            cur = cur->next;
            count++;
        }
    }
    cout<<endl;

    return beg;
}

/** Удаляет список */
Hot* delList(Hot* beg) {
    printFunName("Delete List");

    if (beg == 0) {
        cout<<"List is empty!"<<endl<<endl;
        return beg;
    }

    Hot* cur = 0;
    int count = 0;
    while (beg != 0) {
        cur = beg;
        if (debug) {
            cout<<"Deleting: ";
            printHot(count, cur);
        }
        beg = beg->next;
        delete cur;
        count++;
    }

    cout<<"List deleting!"<<endl<<endl;

    return beg;
}

