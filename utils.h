#ifndef UTILS_H
#define UTILS_H

int const MAX_SIZE = 10;


enum STAT{
    OCCUPIED,
    EMPTY,
    DELETED
};

struct Item {
    int value = -1;
    STAT stat = STAT::EMPTY;

    Item(){}
    Item(int key){
        this->value = key;
    }
    void setItem(int key){
        value = key;
    }
};




#include<iostream>
using namespace std;

void displayMenu();
int NumberOfDigits(int n);
pair<int, int> divisionMethod(int key, int m);
pair<int, int> multiplicationMethod(int key, int m, double A);
pair<int, int> midSquareMethod(int key , int m);
pair<int, int> foldingMethod( int key , int m);
#endif  // UTILS_H