// var4 task1

#include <iostream>
#include <math.h>


void print(int *a, int n){
	std::cout<<"\nArray: ";
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<"; ";
	}
	std::cout<<"\n\n";
}

void main(){
	int n,*a;
	
	std::cout<<"Enter n = ";
	std::cin>>n;
	std::cout<<"\n";

	a=new int[n+10];

	//=============================
	//Заполнение
	//=============================
	for(int i=0;i<n;i++){
		a[i]=rand()/100;
	}
	print(a,n);
	
	//=============================
	//Удаление (N элементов, начиная с номера K)
	//=============================
	
	int delN, delK;
	std::cout<<"Enter n = ";
	std::cin>>delN;
	std::cout<<"Enter k = ";
	std::cin>>delK;
	std::cout<<"\n";

	for(int i=delK-1; i<n-delN; i++){
		a[i]=a[i+delN];
	}
	n -= delN;
	print(a,n);

	//=============================
	//Вставка (Элемент с номером К)
	//=============================
	/*
	int insEl=555, insK;
	std::cout<<"Enter k = ";
	std::cin>>insK;
	std::cout<<"\n";

	n++; insK--;
	for(int i=n-1;i>insK;i--){
		a[i]=a[i-1];
	}
	a[insK]=insEl;
	print(a,n);
	*/

	//=============================
	//Перестановка (Поменять местами элементы с четными и нечетными номерами)
	//=============================
	/*
	int tmp;
	for(int i=0;i<n/2;i++){
		tmp=a[2*i];
		a[2*i]=a[2*i+1];
		a[2*i+1]=tmp;
	}
	print(a,n);
	*/

	//=============================
	//Поиск (Элемент равный среднему арифметическому элементов массива)
	//=============================
	/*
	float sr=a[0];
	bool find=false;
	for(int i=1;i<n;i++){
		sr+=a[i];
	}
	sr=sr/n;
	std::cout<<"\nSr="<<sr;

	for(int i=0;i<n;i++){
		if(abs(a[i]-sr)<1){
			find=true;
			std::cout<<"\nElement naiden n="<<i+1<<"\n";
			break;
		}
	}
	if (!find){
		std::cout<<"\nElement ne naiden\n";
	}
	*/

	//=============================
	//Сортировка методом простого обмена
	//=============================
	/*
	int tmp; 
	for(int i=0;i<n-1;i++){
		for(int j=n-1;j>=i;j--){
			if(a[j]<a[j-1]){
				tmp=a[j];
				a[j]=a[j-1];
				a[j-1]=tmp;
			}
		}	
	}
	print(a,n);
	*/

	//std::cout<<"\nS="<<s<<"\n";	
}
