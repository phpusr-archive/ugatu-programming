/*
Метод итераций
0,25x3 + x - 1,2502 = 0
Отрезок, содержащий корень: [0;2]
Точное значение: 1,0001
*/

#include <iostream>
#include <math.h>
#include <stdio.h>

typedef float(*fptr2args)(float, bool);//тип-указатель на функцию уравнения c 2 аргументами

const bool debug = false;

/** Печать сообщения о найденной точке */
void printX(char* methodName, int count, float x, float y) {
    printf("[%s]\t Result(%d):: x=%.10f\t y=%.5f\n", methodName, count, x, y);
}

/** Метод Ньютона */
float methodNewton(fptr2args f, float a, float b, float e) {
    char* methodName = "Newton";
    float x = (a + b)/2, xPrev;
    int count = 0;

    do {
        xPrev = x;
        count++;
        x = xPrev - f(xPrev, false) / f(xPrev, true);
    } while(fabs(x - xPrev) > e);

    printX(methodName, count, x, (*f)(x, false));
}

/** Функция 11 варианта */
float var11Func(float x, bool proizvod) {
    //Если proizvod == false тогда возвращается значение обычной функц., в другом случае - производной
    if (!proizvod) {
        return 0.1 * pow(x,2) - x * log(x);
    } else {
        return 0.2 * x - log(x) + 1;
    }
}
