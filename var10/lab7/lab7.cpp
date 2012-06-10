#include <cstdlib>
#include <iostream>
#include <stdio.h>
#include <Math.h>
/*
+1.Написать функцию с умалчиваемыми параметрами в соответствии с вариантом, продемонстрировать различные способы вызова функции:
	+с параметрами заданными явно,
	+с опущенными параметрами
	+часть параметров задана явно, а часть опущена.
2. +Написать функцию с переменным числом параметров в соответствии с вариантом, продемонстрировать вызов функции с различным числом параметров.
3. +Написать перегруженные функции в соответствии с вариантом. Написать демонстрационную программу для вызова этих функций.
4. +Написать шаблон функций вместо перегруженных функций из задания 3. Написать демонстрационную программу для вызова этих функций. списка параметров
5. +Решить уравнение указанным в варианте методом. Уравнение передать в функцию как параметр с помощью указателя.


+Функция с умалчиваемыми параметрами
+Функция с переменным числом параметров
+Перегруженные функции и шаблон функции
+Передача функции как параметра другой функции с помощью указателя

*/

using namespace std;

/** Функция с умалчиваемыми параметрами */
void functionDefaultParameters(int x1 = 5, int y1 = 5) {
    cout<<">>functionDefaultParameters"<<endl;

    float dl = sqrt(pow(0 - x1, 2) + pow(0 - y1, 2));
    cout<<"dl="<<dl;
}

/** Функция с переменным числом параметров, Среднее арифметическое из элементов в списке параметров, стоящих на нечетных местах */
float variableFunction(int k, ...) {
     cout<<"Function this variable parameters"<<endl;

     int count = 0, countChet = 0;
     int sum = 0;
     int* p = &k;
     while (*p != 0) { //Цикл продолжается пока не найдется элемент = 0
        count++;
        if (count % 2 == 1) {
            countChet++;
            sum += *p;
            cout<<"p="<<*p<<endl;
        }
        p++;
     }
     cout<<"sum="<<sum<<"; count="<<countChet<<endl;

     return (float)sum / countChet;
}

/** Распечатка массива */
template<class T>
void printArray(T a[], int n) {
  if (false) cout<<">>Print array"<<endl;

   for(int i=0; i<n; i++) {
      cout<<a[i]<<"; ";
   }
   cout<<endl;
}

/** Удаление элемента с заданным номером из динамического массива для int */
int* deleteRowById(int* array, int n, int id) {
       cout<<">>Peregrujenaya func (int)"<<endl;

       if (n == 0) {
           cout<<"Array is empty!";
           return array;
       }

       int* a = new int[n];
       int curRow = 0;

       for (int i=0; i<n; i++) {
           if (i != id) {
               a[curRow] = array[i];
               curRow++;
           }
       }
       n = curRow;

       printArray(a, n);

       return a;
}

/** Удаление элемента с заданным номером из динамического массива для float */
float* deleteRowById(float* array, int n, int id) {
       cout<<">>Peregrujenaya func (float)"<<endl;

       if (n == 0) {
           cout<<"Array is empty!";
           return array;
       }

       float* a = new float[n];
       int curRow = 0;

       for (int i=0; i<n; i++) {
           if (i != id) {
               a[curRow] = array[i];
               curRow++;
           }
       }
       n = curRow;

       printArray(a, n);

       return a;
}

/** Шаблон функции для удаления заданного элемента из массива */
template<class T>
T* deleteElTemplate(T* array, int n, int id) {
    cout<<">>Shablon func"<<endl;

    if (n == 0) {
       cout<<"Array is empty!";
       return array;
   }

   T* a = new T[n];
   int curRow = 0;

   for (int i=0; i<n; i++) {
       if (i != id) {
           a[curRow] = array[i];
           curRow++;
       }
   }
   n = curRow;

   printArray(a, n);

   return a;
}

typedef float(*fptr)(float, bool);//тип-указатель на функцию уравнения

float methodIterator(fptr f, float a, float b, float e); //Заголовок для функции в файле (transfer.cpp)
float methodBisection(fptr f, float a, float b, float e); //Заголовок для функции в файле (transfer.cpp)
float var10Func(float x, bool std); //Заголовок для функции в файле (transfer.cpp)

/** Главная запускаемая функция */
int main(int argc, char *argv[]) {
    int k;
    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Func umalch parameters"<<endl;
        cout<<"2. Func umalch parameters 2"<<endl;
        cout<<"3. Func umalch parameters 3"<<endl;
        cout<<"4. Func s peremen chislom parametrov"<<endl;
        cout<<"5. Peregrujenaya func"<<endl;
        cout<<"6. Peredacha func kak parametra"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            //Запуск функц. с умалч. параметрами (все параметры указаны явно)
            case 1: functionDefaultParameters(4, 6); break;
            //Запуск функц. с умалч. параметрами (часть параметров указана явно)
            case 2: functionDefaultParameters(4); break;
            //Запуск функц. с умалч. параметрами (параметры не указаны)
            case 3: functionDefaultParameters(); break;
            //Запуск функц. с переменным числом параметров
            case 4: cout<<"Sr: "<<variableFunction(4, 3, -12, 8, -1, 20, 0)<<endl; break;
            //Перегруженные функции и шаблон функции
            case 5: {
                 int k;
                 cout<<"Enter k: ";
                 cin>>k;

                 int a[] = {-11, 92, -58, 23, 91, 912};
                 int n = 6;
                 cout<<"Nachalnii massiv:"<<endl;
                 printArray(a, n);

                 deleteRowById(a, n, k-1); //Запуск перегруженной функции для int
                 deleteElTemplate(a, n, k-1); //Запуск шаблонной функции для int
                 cout<<endl;

                 float f[] = {43.23, -23.1, -58.21, 34.34, -91.2, 912.3};
                 n = 6;
                 cout<<"Nachalnii massiv:"<<endl;
                 printArray(f, n);

                 deleteRowById(f, n, k-1); //Запуск перегруженной функции для float
                 deleteElTemplate(f, n, k-1); //Запуск шаблонной функции для float

                 break;
            }
            //Передача функции как параметра другой функции с помощью указателя
            case 6:
                 float res = methodIterator(var10Func, 1, 2, 0.0001);
                 cout<<"x="<<res<<endl;
                 res = methodBisection(var10Func, 1, 2, 0.0001);
                 cout<<"x="<<res<<endl;
                 break;
        }
    } while (k!=7);//выход
}
