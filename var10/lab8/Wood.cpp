#include <iostream>
#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include "Wood.h"

using namespace std;

/*
1 - сообщения об операцияях Creating, Adding
2 - 1 и навания рекурсионные функции create*, add*
3 - 2 и функции print*
*/
int debugWood = 0;

/* Выводит имя функци в заданном формате */
void printFunNameWood(char* name) {
    printf("[Wood] >>%s :: \n", name);
}

/* Печатает узел дерева */
void printNode(Wood* wood) {
    if (debugWood > 2) printFunNameWood("Print node");

    printf("id=%d\t data=%d\t left=%7d\t right=%7d\n", wood, wood->data, wood->left, wood->right);
}

/* Создает идеальное дерево рекурсивно */
Wood* createIdealWoodRecourse(Wood* wood, int count) {
    if (debugWood > 1) printFunNameWood("Create ideal wood recourse");

    if (count == 0) {
        return 0;
    }

    int countLeft = count / 2;
    int countRight = count - countLeft - 1;

    wood = new Wood();
    wood->data = rand() % 90 + 10;

    if (debugWood) {
        if (debugWood > 1) printf("count=%d\t countLeft=%d\t countRight=%d\n", count, countLeft, countRight);
        cout<<"Creating: "; printNode(wood);
    }

    wood->left = createIdealWoodRecourse(wood->left, countLeft);
    wood->right = createIdealWoodRecourse(wood->right, countRight);

    return wood;
}

/* Печатает дерево рекурсивно */
void printWoodRecourse(Wood* wood) {
    if (debugWood > 1) printFunNameWood("Print wood recourse");

    if (wood) {
        printNode(wood);

        printWoodRecourse(wood->left);
        printWoodRecourse(wood->right);
    }
}

/** Создает идеальное дерево */
Wood* createIdealWood(int count) {
    printFunNameWood("Create ideal wood");

    srand(time(0));
    Wood* wood = createIdealWoodRecourse(new Wood(), count);
    cout<<"Wood created!"<<endl<<endl;

    return wood;
}

/** Печатает дерево */
void printWood(Wood* wood) {
    printFunNameWood("Print wood");

    if (wood == 0) {
        cout<<"Wood is empty!"<<endl;
        return;
    }

    printWoodRecourse(wood);
}

/* Считает количество листов рекурсивно */
int countLeafRecourse(Wood* wood, int count) {

    //Подсчет для левой ветки
    if (!wood->left) {
        count++;
    } else {
        count = countLeafRecourse(wood->left, count);
    }

    //Подсчет для правой ветки
    if (!wood->right) {
        count++;
    } else {
        count = countLeafRecourse(wood->right, count);
    }

    return count;
}

/** Обработка дерева (Находит количество листьев в дереве) */
void processingWood(Wood* wood) {
    printFunNameWood("Processing wood");

    if (wood == 0) {
        cout<<"Wood is empty!"<<endl<<endl;
        return;
    }

    int count = countLeafRecourse(wood, 0);

    cout<<endl<<"Kolichestvo listov: "<<count<<endl<<endl;
}

/* Добавляет узел в поисковое дерево (если уже нет такого элемента) */
Wood* addNodeToSearchWood(Wood* searchWood, Wood* el) {
    if (debugWood) printFunNameWood("Add node");

    if (!searchWood || !el) {
        if (!el) cout<<"el == 0"<<endl;
        if (!searchWood) cout<<"searchWood == 0"<<endl;
        return el;
    }

    bool isset = false;
    Wood *cur = searchWood, *endNode;

    while (!isset && cur) {
        if (el->data == cur->data) {
            isset = true;
            if (debugWood) {
                cout<<"el="; printNode(el);
                cout<<"cur="; printNode(cur);
            }
        } else {
            endNode = cur;
            if (el->data < cur->data) {
                cur = cur->left;
            } else {
                cur = cur->right;
            }
        }
    }

    if (isset) {
        cout<<"Already have: "; printNode(cur);
        return cur;
    }

    Wood* newWood = new Wood();
    newWood->data = el->data;
    if (el->data < endNode->data) {
        endNode->left = newWood;
    } else {
        endNode->right = newWood;
    }
    if (debugWood) {
        cout<<"Adding: ";
        printWood(newWood);
    }

    return newWood;
}

/* Конвертирует идеальное дерево в (поисковое рекурсивно) */
Wood* convertIdealWoodToSearchWoodRecurse(Wood* wood, Wood* searchWood) {
    if (debugWood) printFunNameWood("Convert to Search wood recourse");

    if (wood) {
        addNodeToSearchWood(searchWood, wood);

        convertIdealWoodToSearchWoodRecurse(wood->left, searchWood);
        convertIdealWoodToSearchWoodRecurse(wood->right, searchWood);
    }

    return searchWood;
}

/* Выводит числа в виде дерева под 90гр (косячно работает) */
void printTree(Wood *q, int n) {
   if (q) {
      printTree(q->right, n+5);
      for (int i = 0; i < n; i++) {
         printf(" ");
      }
      printf("%.3f\n", q->data);
      printTree(q->left, n+5);
   }
}

/** Конвертирует идеальное дерево в поисковое */
Wood* convertIdealWoodToSearchWood(Wood* wood) {
    printFunNameWood("Convert to Search wood");

    if (wood == 0) {
        cout<<"Wood is empty!"<<endl<<endl;
        return wood;
    }

    Wood* searchWood = new Wood();
    searchWood->data = wood->data;
    convertIdealWoodToSearchWoodRecurse(wood, searchWood);

    cout<<"Wood converted to Search wood!"<<endl<<endl;

    if (debugWood) printTree(searchWood, 0);

    return searchWood;
}
