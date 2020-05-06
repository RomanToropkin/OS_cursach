/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

using namespace std;
#include <iostream>
#include "Column.h"

#include <sys/types.h>
#include <fcntl.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

bool Response();

Column::Column(){
    cout << "Constructor Column" << endl;
    printf("Программа клиент запущена\n");
    int cycle=0;
    key_t ipckey;
    int mq_id;
    char dir[256];
    getcwd(dir, 256);
    ipckey = 10;
    mq_id = msgget(ipckey, IPC_CREAT | 0644);
    while(cycle<3){
        printf("Введите сообщение для отправки на сервер: ");
        char chr[12] ;
        cin.getline(chr,12);
        printf("Запрос серверу: \"%s\" отправлен\n", chr);
        msgsnd(mq_id, &chr, sizeof(chr), 0);
        //while(Response());
        cycle++;
    }
}

bool Response(){
    key_t ipckey;
    int mq_id;
    char mymsg[BUFSIZ] ;
    int received;
    char str[100];
    char dir[256];
    getcwd(dir, 256);
    ipckey = ftok(dir, 43);
    mq_id = msgget(ipckey, 0);
    
    memset(mymsg, 0, sizeof(mymsg));
    received = msgrcv(mq_id, &mymsg, sizeof(mymsg), 0, 1);
    printf("Ответ от сервера: \"%s\" получен\n\n", mymsg);
    auto temp=std::to_string(getpid());
    char const *pchar = temp.c_str();
    
    memset(&str[0], 0, sizeof(str));
    strcat(str,"echo ");
    strcat(str,mymsg);
    strcat(str," >> client_msgs.");
    strcat(str,pchar );
    system(str);
    return false;
    
}