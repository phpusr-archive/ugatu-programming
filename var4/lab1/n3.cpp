#include <iostream>
#include <math.h>

void main(){
	float a,b;
	std::cout<<"\nEnter a,b\n";
	std::cin>>a>>b;

	float chislit = pow(a-b,3)-pow(a,3);
	float znamen = 3*a*pow(b,2) - pow(b,3) - 3*a*a*b;
	float result = chislit/znamen;

	std::cout<<"\nresult="<<result<<"\n";

}