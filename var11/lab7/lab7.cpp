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
5. Решить уравнение указанным в варианте методом. Уравнение передать в функцию как параметр с помощью указателя.


+Функция с умалчиваемыми параметрами
+Функция с переменным числом параметров
+Перегруженные функции и шаблон функции
+Передача функции как параметра другой функции с помощью указателя


+Печать фамилии, имени и рейтинга
+Среднее арифметическое элементов в списке параметров
+Минимальный элемент в массиве
Метод итераций
0,25x3 + x - 1,2502 = 0
Отрезок, содержащий корень: [0;2]
Точное значение: 1,0001

*/

using namespace std;

/** Функция с умалчиваемыми параметрами */
void functionDefaultParameters(int x1 = 4, int y1 = 3, int x2 = 5, int y2 = 7) {
    cout<<">>functionDefaultParameters"<<endl;

    float dl = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
    cout<<"dl="<<dl;
}

/** Функция с переменным числом параметров, поиск минимума */
int variableFunction(int k, ...) {
     cout<<"Function this variable parameters"<<endl;

     int min = k;
     int* p = &k;
     while (*p != 0) { //Цикл продолжается пока не найдется элемент = 0
           p++;
           if (*p < min) min = *p;
           //cout<<"min="<<min<<endl; //для отладки
     }

     return min;
}

/** Распечатка массива */
template<class T>
void printArray(T a[], int n) {
  cout<<">>Print array"<<endl;

   for(int i=0; i<n; i++) {
      cout<<a[i]<<endl;
   }
}

/** Удаление элемента с заданным ключом из динамического массива для int */
int* deleteRowById(int* array, int n, int id) {
       cout<<">>Delete row by id (int)"<<endl;

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

/** Удаление элемента с заданным ключом из динамического массива для float */
float* deleteRowById(float* array, int n, int id) {
       cout<<">>Delete row by id (float)"<<endl;

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
T* minInArrayTemplate(T* array, int n, int id) {
    cout<<"Template function"<<endl;

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

typedef float(*fptr)(float);//тип-указатель на функцию уравнения
typedef float(*fptr2args)(float, bool);//тип-указатель на функцию уравнения c 2 аргументами

float methodNewton(fptr2args f, float a, float b, float e); //Заголовок для функции в файле (transfer.cpp)
float var11Func(float x, bool proizvod); //Заголовок для функции в файле (transfer.cpp)

/** Главная запускаемая функция */
int main(int argc, char *argv[]) {
    int k;
    do {
        cout<<endl<<"======================="<<endl;
        cout<<"1. Function default parameters"<<endl;
        cout<<"2. Function default parameters 2"<<endl;
        cout<<"3. Function default parameters 3"<<endl;
        cout<<"4. Function this variable parameters"<<endl;
        cout<<"5. Overloaded & template function"<<endl;
        cout<<"6. Transfer function"<<endl;
        cout<<"7. Exit"<<endl;
        cout<<"======================="<<endl;
        cin>>k;
        switch (k) {
            //Запуск функц. с умалч. параметрами (все параметры указаны явно)
            case 1: functionDefaultParameters(9,2,6,8); break;
            //Запуск функц. с умалч. параметрами (часть параметров указана явно)
            case 2: functionDefaultParameters(4,6,2); break;
            //Запуск функц. с умалч. параметрами (параметры не указаны)
            case 3: functionDefaultParameters(); break;
            //Запуск функц. с переменным числом параметров
            case 4: cout<<"min: "<<variableFunction(4, 3, -12, 8, -1, 20, 0)<<endl; break;
            //Перегруженные функции и шаблон функции
            case 5: {
                 int k;
                 cout<<"Enter k: ";
                 cin>>k;

                 int a[] = {-11, 92, -58, 23, 91, 912};
                 int n = 6;
                 deleteRowById(a, n, k-1); //Запуск перегруженной функции для int
                 minInArrayTemplate(a, n, k-1); //Запуск шаблонной функции для int
                 cout<<endl;

                 float f[] = {43.23, -23.1, -58.21, 34.34, -91.2, 912.3};
                 n = 6;
                 deleteRowById(f, n, k-1); //Запуск перегруженной функции для float
                 minInArrayTemplate(f, n, k-1); //Запуск шаблонной функции для float

                 break;
            }
            //Передача функции как параметра другой функции с помощью указателя
            case 6:
                 float res = 0;
                 res = methodNewton(var11Func, 1, 2, 0.0001);
                 break;
        }
    } while (k!=7);//выход
}
