#include <iostream>
#include <math.h>
#include "n2.h"

using namespace std;

/**
* Лаба 1: Задание 2
* Записать выражение, зависящее от координат точки X и Y и принимающее значение TRUE, если точка принадлежит заштрихованной области, и FALSE, если не принадлежит.
*/
int n2(){
	/** Точки ввода */
	float x,y;

	/** Две точки треугольника */
	int x1 = -7, y1 = 0;
	int x2 = 0, y2 = -1;

	cout<<endl<<"Enter x,y"<<endl;
	cin>>x>>y;


	bool ok = (x<=x2 && x>=x1 && y<=y1 && y>=y2) && ((y - y1) / (y2 - y1) <= (x - x1) / (x2 - x1));
	if (ok){
		cout<<"Tocka popadaet!"<<endl;
	}else{
		cout<<"Tocka Ne popadaet."<<endl;
	}
}

/*
Уравнение прямой: (y - y1)/(y2 - y1) = (x - x1)/(x2 - x1)
*/
