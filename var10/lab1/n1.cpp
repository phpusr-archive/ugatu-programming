#include <iostream>
#include <math.h>
#include "n1.h"

/**
* Лаба 1: Задание 1
* Определить тип заданных выражений и найти их значения
*/
int n1(){
	int n,m,x;
	std::cout<<"\nEnter n,m,x\n";
	std::cin>>n>>m>>x;

	float r1 =  (float)m/ (--n)++;
	bool r2 = m/n < n --;
	bool r3 = --m + n > n + m;

	float tmp1 = pow(x, 5) * pow(fabs(x - 1), (double)1/2);
	float tmp2 = fabs(25 - pow(x, 5));
	float r4 = tmp1 + tmp2;

	std::cout<<"\nr1="<<r1;
	std::cout<<"\nr2="<<r2;
	std::cout<<"\nr3="<<r3;
	std::cout<<"\nr4="<<r4<<"\n";

}
