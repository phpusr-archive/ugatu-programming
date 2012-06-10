// var4 task1 (Найти количество чисел Фибоначчи в массиве)

#include <iostream>
#include <math.h>

#include <ctime>

void print(int *a, int n);

void insertFibonachiNumbers(int *f, int fCount);

void findFibonachiInArray(int *a, int n, int *f, int fCount);

void main(){
	const int fCount=30;
	int n,*a,*f;
	
	//=============================
	//Заполнение массива числами Фибоначи
	//=============================
	f=new int[fCount];
	insertFibonachiNumbers(f,fCount);
	print(f,fCount);

	//=============================
	//Заполнение моего массива
	//=============================
	
	std::cout<<"\n\nEnter n = ";
	std::cin>>n;
	std::cout<<"\n";

	a=new int[n];

	srand(time(0));
	for(int i=0;i<n;i++){
		a[i]=rand()%1000;
	}
	print(a,n);

	//=============================
	//Поиск чисел Фибоначи в моем массиве
	//=============================
	findFibonachiInArray(a,n,f,fCount);
}

void print(int *a, int n){
	std::cout<<"\nArray: ";
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<"; ";
	}
	std::cout<<"\n\n";
}

void insertFibonachiNumbers(int *f, int fCount){	
	f[0]=0;
	f[1]=1;
	std::cout<<"Fibonachi numbers:\n";
	for(int i=2;i<fCount;i++){
		f[i]=f[i-2]+f[i-1];
		//std::cout<<f[i]<<", ";
	}
}

void findFibonachiInArray(int *a, int n, int *f, int fCount){
	int count=0;

	std::cout<<"\n\nChisla Fibonachi v massive:\n\n";
	for(int i=0;i<n;i++){
		for(int j=0;j<fCount;j++){
			if(a[i]==f[j]){
				count++;
				std::cout<<a[i]<<", ";
			}
		}
	}

	std::cout<<"\n\nItogo = "<<count;
	std::cout<<"\n\n";
}
