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
#include "Column/Column.h"
#include "Column/Column.cpp"
#include "Column/ColumnServer.h"

using namespace std;

/*
 *  
 */
int main(int argc, char** argv) {

    cout << argv[1] << endl;
    if (argc > 1){
        if (strcmp(argv[1], "1")){
            Column *column = new Column;
            
            delete column;
        } else if (strcmp(argv[1], "2")){
            ColumnServer *column = new ColumnServer;
            
            delete column;
        } else {
            cout << "Bad argument!" << endl;
        }
    } else {
        cout << "Arguments not found!" << endl;
    }
    
    return 0;
}

