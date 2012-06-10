// var4 tasks 4,31,38

#include <iostream>
#include <math.h>

void main(){
	int n,k,count=0;

	std::cout<<"Enter n = ";
	std::cin>>n;
	std::cout<<"\n";
	n++;

	std::cout<<"\nEnter k = ";
	std::cin>>k;
	std::cout<<"\n";

	int *a=new int[n];

	for(int i=0;i<n-1;i++){
		a[i]=rand()%100;		
	}

	//Установка последнего элемента нулем
	a[n-1]=0;

	//Вывод и счет кол-ва чисел кратных указанному
	for(int i=0;i<n;i++){
		std::cout<<a[i]<<", ";
		if(a[i]!=0 && a[i]%k==0){
			count++;
		}
	}
	std::cout<<"\nCount = "<<count<<"\n";

}