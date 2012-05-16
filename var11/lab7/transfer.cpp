/*
Метод итераций
0,25x3 + x - 1,2502 = 0
Отрезок, содержащий корень: [0;2]
Точное значение: 1,0001
*/

#include <iostream>
#include <math.h>
#include <stdio.h>

typedef float(*fptr)(float);//тип-указатель на функцию уравнения

const bool debug = false;

void printX(char* methodName, int count, float x, float y) {
    printf("[%s]\t Result(%d):: x=%.10f\t y=%.5f\n", methodName, count, x, y);
}

/* Метод итераций */
float methodIterator(fptr f, float a, float b, float e) {
      char* methodName = "Iterator";
      float x, xNext = (a+b)/2, d = e;
      int count = 0;
      bool exit = false;
      do {
          count++;
          x = xNext;
          xNext = fabs((*f)(x));

          if (count % 100 == 0 && debug) {
             printf("%d: x(%d)=%.5f, x(%d)=%.5f\n", count, count-1, x, count, xNext);
          }

          exit = xNext < e;

      } while(fabs(xNext - x) > e && !exit);

      if (exit) {
        if (!debug) printX(methodName, count, x, (*f)(x));
        return x;
      } else {
        if (debug) printf("X Not found!");
        return 777;
      }
}

/* метод итерации сделан по моему :) */
float methodIteratorMy(fptr f, float a, float b, float e) {
      char* methodName = "IteratorMy";
      float x = a, d = e;
      int count = 0;
      bool exit = false;
      do {
          count++;
          float res = fabs((*f)(x));
          if (count % 100 == 0 && debug) {
             printf("%d: x=%f, y=%.5f\n", count, x, res);
          }

          if (res < e) {
                exit = true;
          } else {
                 x += d;
          }
      } while(!exit && x <= b);

      if (exit) {
          if (!debug) printX(methodName, count, x, (*f)(x));
          return x;
      } else {
          if (debug) printf("X Not found!");
          return 777;
      }
}

/* Метод половинного деления */
float methodBisection(fptr f, float a, float b, float e) {
    char* methodName = "Bisection";
    float x;
    int count = 0;
    do {
        count++;
        x=(a+b)/2;			//находим середину отрезка
        if ( (*f)(a) * (*f)(x) < 0 ) {		//выбираем отрезок
           b=x;
        } else {
          a=x;
        }
        if (count % 100 == 0 && debug) printf("%d: (*f)(a)=%.5f, (*f)(a) * (*f)(x)=%.10f, a=%f, b=%f\n", count, (*f)(a), (*f)(a) * (*f)(x), a, b);
    } while(fabs((*f)(x))>e && fabs(a-b)>e);

    printX(methodName, count, x, (*f)(x));

    return x;
}

/* Функция из примера */
float testf(float x) {
      return x - 1/(3 + sin(3.6 * x));
}

/* функция, для которой ищется корень */
float myFunc(float x) {
      return 0.25 * pow(x, 3) + x - 1.2502;
}
