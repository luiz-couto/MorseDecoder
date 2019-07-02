#include "morse_list.h"
#include <iostream>
#include <sstream>

MorseList::MorseList(){

    this->start = nullptr;
    this->end = nullptr;
    this->number_of_elements = 0;
}

MorseList::~MorseList(){

}

void MorseList::InsertElement(char name, string morse){
    
    code *novo = new code;
    novo->name = name;
    novo->morse = morse;

    if(this->number_of_elements == 0){
        
        novo->prox = nullptr;
        this->start = novo;
        this->end = novo;
   
    }else{
        
        this->end->prox = novo;
        novo->prox = nullptr;
        this->end = novo;
    }

    this->number_of_elements++;

}

void MorseList::RemoveElement(char name){

    code *current = this->start;
    code *previous;
    bool deleted = false;

    while(current->name != name){
        previous = current;
        current = current->prox;
        if(current == this->end && current->name != name){
            break;
        }
    }

    if(current == this->start){
        this->start = current->prox;
        current->prox = nullptr;
        delete current;
        deleted = true;

    }
    else if(current == this->end && current->name == name){
        this->end = previous;
        delete current;
        deleted = true;
    }
    else if(current != this->start && current != this->end){
        previous->prox = current->prox;
        current->prox = nullptr;
        delete current;
        deleted = true;
    }

    if(deleted){
        this->number_of_elements--;
    }else{
        cout << "Não existe esse elemento na lista" << endl;
    }

}

code MorseList::GetElement(int n){

    code *current = this->start;

    while(current->morse.length() != n){
        current = current->prox;
    }

    return *current;

}

void MorseList::Print(){

    code *current = this->start;

    for(int i=0;i<this->number_of_elements;i++){
        cout << current->name << "   " << current->morse << endl;
        current = current->prox;
    }
}