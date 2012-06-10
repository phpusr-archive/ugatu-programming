// var4 task2 (Перевернуть все нечетные столбцы матрицы)

#include <iostream>
#include <math.h>

#include <ctime>

void print(int *a, int n);
void change(int *a, int n);

void main(){	
	int n,*a;
	
	//=============================
	//Заполнение моего массива
	//=============================
	
	std::cout<<"\n\nEnter n = ";
	std::cin>>n;
	std::cout<<"\n";

	a=new int[n*n];

	srand(time(0));
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			*(a+i*n+j)=rand()%100;
		}		
	}
	print(a,n);

	change(a,n);

	print(a,n);

}

void print(int *a, int n){
	std::cout<<"\nArray: \n";
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			std::cout<<*(a+i*n+j)<<" ";
		}
		std::cout<<"\n";
	}
	std::cout<<"\n\n";
}

void change(int *a, int n){
	int tmp,stl;
	int k=n/2;

	for(int i=0;i<k;i++){
		for(int j=0;j<k;j++){			
			stl=2*i+1;
			tmp=*(a+j*n+stl);
			*(a+j*n+stl)=*(a+(n-1-j)*n+stl);
			*(a+(n-1-j)*n+stl)=tmp;
			
		}
	}	
}
