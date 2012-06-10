// var4 task3 (Удалить каждое четное слово из строки)

#include <iostream>
#include <math.h>


void todo(char *s);


void main(){
	char s[100];
	
	//=============================
	//Заполнение моего массива
	//=============================
	
	std::cout<<"\n\nEnter s = ";
	gets(s);
	//std::cout<<"\n"<<s<<"\n";

	todo(s);
	
	std::cin>>s;
}

void todo(char *s){
	
	int len=strlen(s),countWord=1,lenSC=0;
	char sc[100];

	for(int i=0;i<len;i++){
		if(s[i]==' '){
			countWord++;
		}
		if(countWord%2==1){			
			sc[lenSC]=s[i];
			lenSC++;
		}
	}
	sc[lenSC]='\0';

	std::cout<<"\n"<<sc<<"\n";
}