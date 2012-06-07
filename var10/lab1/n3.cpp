#include <iostream>
#include <math.h>
#include "n3.h"

using namespace std;

/**
* Лаба 1: Задание 3
* Вычислить значение выражения, используя различные вещественные типы данных
*/
int n3(){
	float a,b;
	cout<<endl<<"Enter a,b"<<endl;
	cin>>a>>b;

	float chislit = pow(a+b,3) - (pow(a,3) + 3*pow(a,2)*b);
	float znamen = 3*a*pow(b,2) + pow(b,3);
	//Результат будет всегда один, потому что, если в числителе раскрыть скобки, то будет знаменатель
	float result = chislit/znamen;

	cout<<endl<<"result="<<result<<endl;

}
