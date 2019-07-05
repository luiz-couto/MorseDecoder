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

void Print(string file, Tree *arvore){
    
    string aux;
    string word;
    string line;
    ifstream infile(file);

    while(getline(infile,line)){
        
        for(int i=0;i<line.length();i++){
            
            if(line[i-1] != '/')
                aux = line[i];
            
            if(aux != "/") {
                word = word + aux;
                if(i == line.length()-1){
                    word = word + " ";
                }
            }
            if((aux == "/")||(i == line.length()-1)){
                arvore->PrintWord(word);
                word = "";
                aux = "";
                cout << " ";
            }
        }

        cout << "\n";
    }
    


}

int main(){

    
    MorseList list;
    Tree arvore;
    PopulateMorseList(&list);
    arvore.PopulateTree(&list);
    Print("test.txt",&arvore);
    
    return 0;

}

