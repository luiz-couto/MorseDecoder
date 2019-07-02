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
        void InsertElement(code data,node *root, int n, int i);
        void PopulateTree(MorseList list);
        // n -> numero de caracteres na string morse
        // i -> auxiliar


};
