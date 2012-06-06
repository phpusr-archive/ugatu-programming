#include <iostream>
#include <math.h>

int n2(){
	/** Точки ввода */
	float x,y;
	/** Радиус */
	int r=1;

	std::cout<<"\nEnter x,y\n";
	std::cin>>x>>y;

	bool ok = ((x>=-1 && x<=1 && y>=-1 && y<=1) && (x*x+y*y<=r*r));
	if (ok){
		std::cout<<"Tocka popadaet!\n";
	}else{
		std::cout<<"Tocka Ne popadaet.\n";
	}
	//std::cin>>r;
}

/*
x2+y2+ax+by+c=0
C=2PiR=PiD;
R=C/(2Pi)=D/2
D=C/Pi=2R

x2+y2=R2
*/
