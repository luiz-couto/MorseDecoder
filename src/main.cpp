#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "morse_list.h"
#include "arvore.h"

using namespace std;

void PopulateMorseList(MorseList *list){

    ifstream infile("morse.txt");
    string line;
    
    while(getline(infile,line)){
       
        char name = line[0];
        string morse = line.substr(2);
        list->InsertElement(name,morse);        
    }

}



int main(){

    
    MorseList list;
    Tree arvore;
    PopulateMorseList(&list);
    arvore.PopulateTree(&list);
    
    return 0;

}

