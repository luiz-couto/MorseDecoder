#ifndef LIST_H_
#define LIST_H_


#include <iostream>
#include <sstream>

using namespace std;

struct code{
    char name;
    string morse;

    code *prox;
};

class MorseList{
    
    private:
        code *start;
        code *end;
        int number_of_elements;

    public:
        MorseList();
        ~MorseList();
        void InsertElement(char name, string morse);
        void RemoveElement(char name);
        code GetElement(int n); // n -> número de caracteres no código morse
        code GetElementByPosition(int p);
        void Print();
        int GetSize();

};

#endif