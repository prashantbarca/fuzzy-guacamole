/*
 * server.c
 * Copyright (C) 2016 Prashant A <prashant.barca@gmail.com> 2016-02-01
 *
 * Distributed under terms of the MIT license.
 */

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<fcntl.h>
#include<arpa/inet.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<netinet/in.h>
#include "macaroon.h"
#include<unistd.h>
#include "socket.h"
#include<pthread.h>

void *recvthread(void *arg)
{
    while(1)
    {
    receive(5000);
    }
}
struct macaroon* mint()
{
    struct macaroon abcd;
    return &abcd;
}

int main()
{
    pthread_t thread;
    pthread_create(&thread,NULL,recvthread,NULL);
    pthread_join(thread,NULL);
    return 0;
}

