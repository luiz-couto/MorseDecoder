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

    while(current->name != name){
        previous = current;
        current = current->prox;
    }

    if(current == this->start){
        this->start = current->prox;
        current->prox = nullptr;
        delete current;
    }
    else if(current == this->end){
        this->end = previous;
        delete current;
    }
    else{
        previous->prox = current->prox;
        current->prox = nullptr;
        delete current;
    }

    this->number_of_elements--;

}

code MorseList::GetElement(int n){

    code *current = this->start;

    while(current->morse.length() != n){
        current = current->prox;
    }

    return *current;

}