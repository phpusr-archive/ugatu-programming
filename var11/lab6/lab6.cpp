/*
1.	+Сформировать динамический массив из элементов структурного типа. Структурный тип определен в варианте.
2.	+Распечатать сформированный массив.
3.	+Выполнить поиск элементов в массиве, удовлетворяющих заданному в варианте условию и сформировать из них новый массив.
4.	+Распечатать полученный массив.
5.	+Сформировать динамический массив, состоящий из динамических строк.
6.	+Распечатать сформированный массив.
7.	+Выполнить обработку этого массива.
8.	+Распечатать полученный массив.

4	struct employee
{
char*name;
float salary;
int stage
};

+Сотрудники со стажем больше 10 лет

+Удалить  строку из конца матрицы

*/


#include <cstdlib>
#include <iostream>
#include <ctime>
#include <stdio.h>

using namespace std;

struct Employee {
    char name[50];
    float salary;
    int stage;
};

Employee* formedStructure(int n) {
         cout<<">>Formed array structure type\n";

         srand(time(0));
         Employee* eList = new Employee[n];
         for(int i=0;i<n;i++) {
             sprintf(eList[i].name, "Name%d", i);
             eList[i].salary = 10000 + rand() % 10000;
             eList[i].stage = rand() % 20;
         }

         return eList;
}

void printEmployee(Employee e) {
     cout<<"name: "<<e.name<<"; salary: "<<e.salary<<"; stage="<<e.stage<<"\n";
}

void printStructure(Employee* eList, int n) {
     cout<<">>Print array structure\n";

     if (n == 0) {
           cout<<"Array is empty!";
     }

     for(int i=0;i<n;i++) {
          printEmployee(eList[i]);
     }
}

void findEmployee(Employee* e, int n, int stage) {
     cout<<">>Find employee where stage > "<<stage<<"\n";

     if (n == 0) {
           cout<<"Array is empty!";
     }

     for(int i=0;i<n;i++) {
             if (e[i].stage > 10) {
                printEmployee(e[i]);
             }
     }
}

char** formedDynArrayDynStrings(int n) {
       cout<<">>Formed dyn array dyn strings\n";

       char** array = new char*[n];
       for(int i=0;i<n;i++) {
               array[i] = new char[20];
               sprintf(array[i], "DynString-%d", rand()%50);
       }

       return array;
}

void printDynArrayDynStrings(char** array, int n) {
     cout<<">>Print dyn array dyn strings\n";

     if (n == 0) {
           cout<<"Array is empty!";
     }

     for(int i=0;i<n;i++) {
             cout<<i+1<<": "<<array[i]<<"\n";
     }
}

char** processingDynArrayDynString(char** array, int* n) {
       cout<<">>Processing dyn array dyn strings\n";

       if (*n > 0) {
          *n -= 1;
          delete array[*n];
       } else {
              cout<<"Array is empty!";
       }

       return array;
}

int main(int argc, char *argv[]) {
    int k;
    int n = 0;
    const int stage = 10;
    Employee* eList;
    char** array;

    do {
        cout<<"\n=======================\n";
        cout<<"1. Formed array structure type\n";
        cout<<"2. Print array structure\n";
        cout<<"3. Find employtt where stage > "<<stage<<"\n";
        cout<<"4. Formed dyn array dyn strings\n";
        cout<<"5. Print dyn array dyn strings\n";
        cout<<"6. Processing dyn array dyn strings\n";
        cout<<"7. Exit\n";
        cout<<"=======================\n";
        cin>>k;
        switch (k) {
            case 1:
                n = 10;
                eList = formedStructure(n);
                break;
            case 2: printStructure(eList, n); break;
            case 3: findEmployee(eList, n, stage); break;//
            case 4: n = 10; array = formedDynArrayDynStrings(n); break;//
            case 5: printDynArrayDynStrings(array, n); break;//
            case 6: array = processingDynArrayDynString(array, &n); break;//
        }
    } while (k!=7);//выход
}
