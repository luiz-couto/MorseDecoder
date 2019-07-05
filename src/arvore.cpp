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

    }else{

        
        if(data.morse.substr(i,1) == "-"){
            if(root->right == nullptr)
                root->right = new node;
            this->InsertElement(data, root->right,n-1,i+1);
        }
        else if(data.morse.substr(i,1) == "."){
            if(root->left == nullptr)
                root->left = new node;
            this->InsertElement(data, root->left,n-1,i+1);
        }
    }
   

}

void Tree::PopulateTree(MorseList *list){
    
    
    code x = list->GetElement(1);
    for (int n=1;n<=5;n++){
        
        x = list->GetElement(n);
        this->InsertElement(x,this->root,n,0);
        list->RemoveElement(x.name);
       
        for(int k=0;k<list->GetSize();k++){

            if(list->GetElementByPosition(k).morse.length() == n){
                
                n = n-1;
                break;
            }
                
        }

    }

}

void Tree::GetName(string morse,node *root,int n, int i){

    if(n == 0){
        
        cout << root->data.name;
        
    
    }else{

        if(morse.substr(i,1) == "-"){
            this->GetName(morse,root->right,n-1,i+1);
        }
        else if(morse.substr(i,1) == "."){
            this->GetName(morse,&(*root->left),n-1,i+1);
        }


    }

}

void Tree::PrintWord(string morse_word){
    
   string aux;
   for(int i=0;i<morse_word.length();i++){
        
        if(morse_word[i] != ' '){
            aux = aux+morse_word[i];
        }else{
            this->GetName(aux,this->root,aux.length(),0);
            aux = "";
        }
   }
        
}

void Tree::PreOrdem(node *root){

    if(root != nullptr){
        if(root->data.name != '*' && root->data.morse != "")
            cout << root->data.name << " " << root->data.morse << "\n";
        this->PreOrdem(root->left);
        this->PreOrdem(root->right);
    }

}

void Tree::PrintPreOrdem(){
    this->PreOrdem(this->root);
}
