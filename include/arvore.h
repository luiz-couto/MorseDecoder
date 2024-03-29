#ifndef ARVORE_H_
#define ARVORE_H_

#include <iostream>
#include <sstream>
#include "morse_list.h"

using namespace std;

struct node{

    code data;
    node *left;
    node *right;

};


class Tree{

    private:
       
        node *root;
        int number_of_elements;

    public:

        Tree();
        ~Tree();
        void InsertElement(code &data,node *root, int n, int i);
        void PopulateTree(MorseList *list);
        void GetName(string morse,node *root,int n, int i);
        void PrintWord(string morse_word);
        void PrintPreOrdem();
        void PreOrdem(node *root);
        // n -> numero de caracteres na string morse
        // i -> auxiliar


};

#endif