#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "Helper.h"

using namespace std;

/** Размер для сообщений */
const int SIZE_MESSAGE = 100;

/** Разделитель */
char* getSeparator(char* ch) {
    const int count = 30;
    char separator[count + 1] = "";
    for (int i=0;i<count; i++) {
        strcat(separator, ch);
    }

    return strdup(separator);
}

/** Очистка экрана */
void clrscr(bool isClearScreen) {
    if (isClearScreen) system("cls");
}

/** Выводит заголовок меню */
void printMenuHeader(char* title) {
    cout<<getSeparator("=")<<endl;
    cout<<"== "<<title<<" =="<<endl;
    cout<<getSeparator("=")<<endl;
}

/** Выводит № и заголовок меню */
void printMenuHeader(int num, char* title) {
    cout<<getSeparator("=")<<endl;
    cout<<"== "<<num<<". "<<title<<" =="<<endl;
    cout<<getSeparator("=")<<endl;
}

/** Выводит элемент меню */
void printMenuItem(int num, char* title) {
    cout<<num<<". "<<title<<endl;
}

/** Выводит информационное сообщение */
void info(char* message) {
    cout<<">>"<<message<<endl;
}

/** Выводит информационное сообщение с префиксом */
void info(char* prefix, char* message) {
    printf("[%s] >>%s\n", prefix, message);
}

/** Предупреждающее сообщение */
void warn(char* message) {
    cout<<"[WARN:] "<<message<<"!"<<endl;
}

/** Воозвращает строку сообщения об ошибке */
char* getErrorString(char* message) {
    char* result = new char[SIZE_MESSAGE];
    sprintf(result, "[ERROR:] %s\n", message);

    return result;
}

/** Выводит сообщение об ошибке */
void error(char* message) {
    cout<<getErrorString(message);
}

/** Выводит название функции */
void printFuncName(char* title) {
    printf("%s\n[ %s ]\n%s\n\n", getSeparator("="), title, getSeparator("="));
}

/** Выводит название доп. функции */
void printDopFuncName(char* title) {
    printf("%s\n- %s -\n%s\n\n", getSeparator("-"), title, getSeparator("-"));
}

/** Выводит все варианты сообщений */
void testMessages() {
    printFuncName("Test messages");

    info("Info message");
    info("Prefix","Info message");
    warn("Warning message");
    error("Error message");
}
