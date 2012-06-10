// var4 tasks 4,31,38

#include <iostream>
#include <math.h>

void main(){
	int n;
	int start=15;
	int s=start;

	std::cout<<"Enter n = ";
	std::cin>>n;
	std::cout<<"\n";

	for(int i=0;i<n-1;i++){		
		start+=2;		
		if(i%2==0){			
			s+=start;
		}else{
			s-=start;
		}
		std::cout<<"\nS="<<s<<"; start="<<start<<"\n";			
	}

	std::cout<<"\nS="<<s<<"\n";	
}