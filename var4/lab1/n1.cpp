#include <iostream>
#include <math.h>

void main(){
	int n,m,x;
	std::cout<<"\nEnter n,m,x\n";
	std::cin>>n>>m>>x;

	int r1 = n++ * m;
	bool r2 = n++ < m;
	bool r3 = --m > n;
	
	float tmp1 = x-x*x+pow((float)x,5);
	float tmp2 = (float)tmp1/3;
	float r4 = pow(tmp1,tmp2);	

	std::cout<<"\nr1="<<r1;
	std::cout<<"\nr2="<<r2;
	std::cout<<"\nr3="<<r3;
	std::cout<<"\nr4="<<r4<<"\n";

}