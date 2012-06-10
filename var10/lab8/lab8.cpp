/*
+1.	Сформировать однонаправленный список, тип информационного поля указан в варианте.
+2.	Распечатать полученный список.
+3.	Выполнить обработку списка в соответствии с заданием.
+4.	Распечатать полученный список.
+5.	Удалить список из памяти.
+6.	Сформировать двунаправленный список, тип информационного поля указан в варианте.
+7.	Распечатать полученный список.
+8.	Выполнить обработку списка в соответствии с заданием.
+9.	Распечатать полученный список.
+10.	Удалить список из памяти.
+11.	Сформировать идеально сбалансированное бинарное дерево, тип информационного поля указан в варианте.
+12.	Распечатать полученное дерево.
+13.	Выполнить обработку дерева в соответствии с заданием, вывести полученный результат.
+14.	Преобразовать идеально сбалансированное дерево в дерево поиска.
+15.	Распечатать полученное дерево.
*/

#include <iostream>
#include <stdlib.h>
#include "SinglyLinkedList.h"
#include "DoubleLinkedList.h"
#include "Wood.h"

using namespace std;

bool isClearScreen = true;

void clrscr() {
    if (isClearScreen) system("cls");
}

char* getSeparator() {
    return "========================";
}

void printMenu() {
    clrscr();
    cout<<getSeparator()<<endl;
    cout<<"== Odnonapravlenii spisok =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"1. Sozdat"<<endl;
    cout<<"2. Vivesti"<<endl;
    cout<<"3. Udalit s chetn nomerami"<<endl;
    cout<<"4. Udalit iz pamyati"<<endl;

    cout<<getSeparator()<<endl;
    cout<<"== Dvunapravlenii spisok =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"5. Sozdat"<<endl;
    cout<<"6. Vivesti"<<endl;
    cout<<"7. Dobavit element"<<endl;
    cout<<"8. Udalit iz pamyati"<<endl;

    cout<<getSeparator()<<endl;
    cout<<"==        Derevo        =="<<endl;
    cout<<getSeparator()<<endl;
    cout<<"9. Sozdat"<<endl;
    cout<<"10. Vivesti"<<endl;
    cout<<"11. Naite kol-vo listev"<<endl;
    cout<<"12. Preobrazovat v derevo poiska"<<endl;

    cout<<getSeparator()<<endl;
    cout<<"13. Exit"<<endl;
    cout<<getSeparator()<<endl;
}

int main() {
    int k = -1, count = 8;
    Hot* hot = 0;
    Dub* dub = 0;
    Wood* wood = 0;

    cout<<"Var10 Lab8"<<endl;

    printMenu();

    do {
        if (k != 0 && k != -1) cout<<endl<<"Nagmi [0] dly menu ili [13] dlya vihoda..."<<endl;

        cin>>k;
        switch (k) {
            case 0: clrscr(); printMenu(); break; //Выводит меню

            //Создает однонаправ. список и выводит его
            case 1: clrscr(); hot = createList(count); printList(hot); break;
            //Выводит однонаправ список
            case 2: clrscr(); printList(hot); break;
            //Удаляет из однонаправ. списка все элементы с четными номерами (0, 2, 4, ...)
            case 3: clrscr(); hot = processingList(hot); printList(hot); break;
            //Удаляет однонаправ. список из памяти
            case 4: clrscr(); hot = delList(hot); printList(hot); break;

            //Создает двунаправ. список и выводит его
            case 5: clrscr(); dub = createListDouble(count); printListDouble(dub); break;
            //Выводит двунаправ. список
            case 6: clrscr(); printListDouble(dub); break;
            //Добавляет в двунаправ. список элмент после элмента с заданным инф. полем
            case 7: clrscr(); dub = processingListDouble(dub, createDub("INSERT")); printListDouble(dub); break;
            //Удаляет двунаправ. список из памяти
            case 8: clrscr(); dub = delListDouble(dub); printListDouble(dub); break;

            //Создает идеально сбалансированное бинарное дерево и выводит его
            case 9: clrscr(); wood = createIdealWood(count); printWood(wood); break;
            //Выводит дерево
            case 10: clrscr(); printWood(wood); break;
            //Находит количество листьев в дереве
            case 11: clrscr(); processingWood(wood); printWood(wood); break;
            //Преобразовывает идеальное дерево в дерево поиска и выводит его
            case 12: clrscr(); wood = convertIdealWoodToSearchWood(wood); printWood(wood); break;
        }
    } while (k!=13);
}
