#include <iostream>
#include <stdio.h>
#include <stdlib.h>

#include "morse_list.h"

using namespace std;

int main(){

    MorseList list;
    code test;
    
    list.InsertElement('A',"..-.");
    list.InsertElement('B',"-...");
    list.InsertElement('C',"-.-.");
    list.InsertElement('D',"-");
    list.InsertElement('E',".");

    test = list.GetElement(1);
    cout << test.name << "   " << test.morse << endl;
    list.RemoveElement(test.name);
    test = list.GetElement(1);
    cout << test.name << "   " << test.morse << endl;

}

