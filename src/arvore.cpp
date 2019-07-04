#include "arvore.h"
#include <iostream>
#include <sstream>

Tree::Tree(){
    
    node *root = new node;
    code data;
    data.name = '*';
    data.morse = "*";
    root->data = data;
    root->left = nullptr;
    root->right = nullptr;

    this->root = root;
    //this->InsertElement(data,root,0,0);
   
    this->number_of_elements = 0;
}

Tree::~Tree(){

}

void Tree::InsertElement(code &data,node *root,int n, int i){
    
    if(n == 0){
        
        
        root->data = data;
        root->left = nullptr;
        root->right = nullptr;
        
        
        printf("HEY\n");

    }else{

        
        if(data.morse.substr(i,1) == "."){
            
            root->right = new node;
            this->InsertElement(data, root->right,n-1,i+1);
        }
        else if(data.morse.substr(i,1) == "-"){
            
            root->left = new node;
            this->InsertElement(data, root->left,n-1,i+1);
        }
    }
   

}

void Tree::PopulateTree(MorseList *list){
    
    code x = list->GetElement(1);
    this->InsertElement(x,this->root,1,0);
    cout << this->root->left->data.name << endl;
    //cout << x.name << endl;
    //list->RemoveElement(x.name);
    //cout << this->root->right->data.name << endl;
    

}
