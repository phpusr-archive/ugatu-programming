/*
1.	+Сформировать динамический массив из элементов структурного типа. Структурный тип определен в варианте.
2.	+Распечатать сформированный массив.
3.	+Выполнить поиск элементов в массиве, удовлетворяющих заданному в варианте условию и сформировать из них новый массив.
4.	+Распечатать полученный массив.
5.	+Сформировать динамический массив, состоящий из динамических строк.
6.	+Распечатать сформированный массив.
7.	+Выполнить обработку этого массива.
8.	+Распечатать полученный массив.

struct person
{
char*name;
int age;
float rating
}


+Ученики, у которых фамилия “Иванов”

+Удалить К строк из начала массива

*/


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdio.h>
#include <string.h>

using namespace std;

/** Структура */
struct Person {
    char name[50];
    int age;
    float rating;
};

/** Формирование массива структур */
Person* formedListStructure(int n) {
         cout<<">>Formed array structure type"<<endl;

         srand(time(0));
         Person* personList = new Person[n];
         for(int i=0;i<n;i++) {
             if (rand() % 3 == 0) {
                 strcpy(personList[i].name, "Ivanov");
             } else {
                sprintf(personList[i].name, "Name%d", i);
             }
             personList[i].age = rand() % 30;
             personList[i].rating = (float)(rand() % 100) / 100;
         }

         return personList;
}

/** Печать структуры */
void printPerson(Person e) {
     cout<<"name: "<<e.name<<"; age="<<e.age<<";\traiting="<<e.rating<<endl;
}

/** Печать списка структур */
void printListStructure(Person* personList, int n) {
     cout<<">>Print array structure"<<endl;

     if (n == 0) {
           cout<<"Array is empty!"<<endl;
     }

     for(int i=0;i<n;i++) {
          printPerson(personList[i]);
     }
}

/** Поиск учеников у которых фамилия “Ivanov” */
void findPerson(Person* e, int n) {
     cout<<">>Poisk uchenikov s fam Ivanov"<<endl;

     if (n == 0) {
           cout<<"Array is empty!"<<endl;
     }

     for(int i=0;i<n;i++) {
             if (strcmp(e[i].name, "Ivanov") == 0) {
                printPerson(e[i]);
             }
     }
}

/** Формирование динамического массива, динамических строк */
char** formedDynArrayDynStrings(int n) {
       cout<<">>Formed dyn array dyn strings"<<endl;

       char** array = new char*[n];
       for(int i=0;i<n;i++) {
               array[i] = new char[20];
               sprintf(array[i], "DynString-%d", rand()%50);
       }

       return array;
}

/** Печать динамического массива, динамических строк */
void printDynArrayDynStrings(char** array, int n) {
     cout<<">>Print dyn array dyn strings"<<endl;

     if (n == 0) {
           cout<<"Array is empty!";
     }

     for(int i=0;i<n;i++) {
             cout<<i+1<<": "<<array[i]<<endl;
     }
}

/** Удаление K строк из начала массива */
char** deleteRows(char** array, int* n, int k) {
       cout<<">>Udalenie strok iz nachala massiva"<<endl;

       if (*n == 0) {
           cout<<"Array is empty!"<<endl;
           return array;
       }
       if (k > *n) {
           cout<<"K > N"<<endl;
           return array;
       }

       for (int i=0; i<*n-k; i++) {
           strcpy(array[i], array[i+k]);
       }

       *n -= k;
       return array;
}

/** Главная запускаемая функция */
int main(int argc, char *argv[]) {

    cout << "Var 10 Lab 6" << endl;

    int k;
    int nStructure = 0, nDynArray = 0;
    const int age = 18;
    Person* personList;
    char** array;

    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Formirovanit massiva struktur"<<endl;
        cout<<"2. Vivod massiva struktur"<<endl;
        cout<<"3. Poisk Ivanovih"<<endl;
        cout<<"4. Formirovanit dinamich massiva strok"<<endl;
        cout<<"5. Vivod dinamich massiva strok"<<endl;
        cout<<"6. Udalenie strok iz nachala massiva"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            case 1: //Формирование списка структур
                nStructure = 10;
                personList = formedListStructure(nStructure);
                printListStructure(personList, nStructure);
                break;
            case 2: //Распечатка списка структур
                printListStructure(personList, nStructure);
                break;
            case 3: //Поиск учеников у которых фамилия “Ivanov”
                findPerson(personList, nStructure);
                break;
            case 4: //Формирование динамического массива, динамических строк
                nDynArray = 10;
                array = formedDynArrayDynStrings(nDynArray);
                printDynArrayDynStrings(array, nDynArray);
                break;
            case 5: //Печать динамического массива, динамических строк
                printDynArrayDynStrings(array, nDynArray);
                break;
            case 6: //Удаление K строк из начала массива
                int k;
                cout<<"Enter k: ";
                cin>>k;
                deleteRows(array, &nDynArray, k);
                printDynArrayDynStrings(array, nDynArray);
                break;
        }
    } while (k!=7);//выход
}
