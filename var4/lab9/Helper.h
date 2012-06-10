#ifndef HELPER_H_INCLUDED
#define HELPER_H_INCLUDED

char* getSeparator(char* ch);
void clrscr(bool isClearScreen);

void printMenuHeader(char* title);
void printMenuHeader(int num, char* title);
void printMenuItem(int num, char* title);

void printFuncName(char* title);
void printDopFuncName(char* title);
void info(char* message);
void info(char* prefix, char* message);
void warn(char* message);
char* getErrorString(char* message);
void error(char* message);

void testMessages();

#endif // HELPER_H_INCLUDED
