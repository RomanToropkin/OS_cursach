/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: roman
 *
 * Created on 30 апреля 2020 г., 13:24
 * 
 */

#include <cstdlib>
#include <cstring>
#include <iostream>
#include "Column/test_column.h"

using namespace std;

/*
 *  
 */
int main(int argc, char** argv) {

    if (argc > 1){
        if (strcmp(argv[0], "1")){
            cout << "The sum of 1 and 1 is " << add(1, 1) << endl;
        } else if (strcmp(argv[0], "2")){
            cout << "The sum of 2 and 2 is " << add(2, 2) << endl;
        } else {
            cout << "Bad argument!" << endl;
        }
    } else {
        cout << "Arguments not found!" << endl;
    }
    return 0;
}

