//
// Created by timot on 05-04-2019.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <string>
using namespace std;

int Random(int upper){
    int num = rand() % upper;
    return num;
}

// Driver code
int main(){
    int upper = 10;

    srand(time(0));
    string naam = "streepjeInVakje" + to_string(Random(upper));
    cout << "Naam: " << naam << endl;
   // cout << Random(upper) << "\n";
}