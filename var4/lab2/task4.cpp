// var4 tasks 4,31,38

#include <iostream>
#include <math.h>

void main(){
	int n=100,sum=0,count=0;

	std::cout<<"n=";
	std::cin>>n;

	if(n%2==0){
		count=n/2;
	}else{
		count=n/2+1;
	}

	for(int i=0;i<count;i++){
		sum += 2*i+1;
	}
	std::cout<<"\n[for]Sum = "<<sum<<"\n";

	int i=0;
	sum=0;
	while(i<count){		
		sum += 2*i+1;
		i++;
	}	
	std::cout<<"\n[while]Sum = "<<sum<<"\n";
	
	i=0;
	sum=0;
	do{				
		sum += 2*i+1;		
		i++;
	}while(i<count);	
	std::cout<<"\n[do-while]Sum = "<<sum<<"\n";
}