#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
#include <string>

#include "morse_list.h"

using namespace std;

void PopulateMorseList(MorseList *list){

    ifstream infile("morse.txt");
    string line;
    
    while(getline(infile,line)){
       
        char name = line[0];
        string morse = line.substr(1);
        list->InsertElement(name,morse);        
    }

}



int main(){

    
    MorseList list;
    PopulateMorseList(&list);
    list.Print();
    

}

