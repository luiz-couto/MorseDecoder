#include "arvore.h"
#include <iostream>
#include <sstream>

Tree::Tree(){
    
    node *root = new node;
    code data;
    data.name = '*';
    data.morse = "*";
    root->left = nullptr;
    root->right = nullptr;

    this->root = root;
    this->InsertElement(data,root,0,0);
   
    this->number_of_elements = 0;
}

Tree::~Tree(){

}

void Tree::InsertElement(code data,node *root,int n, int i){
    
    if(n == 0){
        node *new_node = new node;
        new_node->data = data;
        new_node->left = nullptr;
        new_node->right = nullptr;
    }
    if(data.morse[i] == '.'){
        this->InsertElement(data,root->right,n-1,i+1);
    }
    else if(data.morse[i] == '-'){
        this->InsertElement(data,root->left,n-1,i+1);
    }

}

void Tree::PopulateTree(MorseList list){
    
}
