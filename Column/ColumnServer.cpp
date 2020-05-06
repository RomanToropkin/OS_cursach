/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "ColumnServer.h"
#include <fcntl.h>
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdio.h>
#include <unistd.h>
#include <iostream>
#include <string>
#include <string.h>
#include <stdio.h>

using namespace std;


ColumnServer::ColumnServer(){
    
    printf("Программа сервер запущена:\n");
    key_t ipckey;
    int cycle=0;
    int mq_id;
    char mymsg[100];
    char str[100];
    char dir[256];
    getcwd(dir, 256);
    ipckey = 10;
    mq_id = msgget(ipckey, 0);
    int received;
    
    while (cycle<3){
        received = msgrcv(mq_id, &mymsg, sizeof(mymsg), 0, 1);    
        printf("Сообщение от клиента: \"%s\" получено\n", mymsg);
        cycle++;
    }
    msgctl(mq_id,IPC_RMID,(struct msqid_ds *) 0);
    
}