/*
 * socket.c
 * Copyright (C) 2016 Prashant A <prashant.barca@gmail.com> 2016-02-04
 *
 * Distributed under terms of the MIT license.
 */

#include "socket.h"

void send(int port)
{
    int sockfd = 0,n = 0;
    struct macaroon recvBuff;
    struct sockaddr_in serv_addr;

    memset(recvBuff.buffer, '0' ,sizeof(recvBuff));
    strcpy(recvBuff.buffer,"Sending something");
    if((sockfd = socket(AF_INET, SOCK_STREAM, 0))< 0)
    {
        printf("\n Error : Could not create socket \n");
        exit(0);
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(port);
    serv_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    if(connect(sockfd, (struct sockaddr *)&serv_addr, sizeof(serv_addr))<0)
    {
        printf("\n Error : Connect Failed \n");
        exit(1);
    }

    /*printf("Sending\n");*/
    printf("\n Sending %s\n\n",recvBuff.buffer);
    n = send(sockfd, &recvBuff, sizeof(recvBuff),0);
    if(n<0)
    {
        printf("Read Error\n");
    }
    //while((n = read(sockfd, &recvBuff, sizeof(recvBuff)-1)) > 0)
}

void receive(int port)
{
    int listenfd=0,connfd=0;
    struct sockaddr_in serv_addr;
    listenfd=socket(AF_INET,SOCK_STREAM,0);
    memset(&serv_addr,'0',sizeof(serv_addr));    
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = htonl(INADDR_ANY);
    serv_addr.sin_port = htons(port);
    bind(listenfd, (struct sockaddr*)&serv_addr,sizeof(serv_addr));
    if(listen(listenfd, 10) == -1){
        printf("Failed to listen\n");
        exit(1);
    }
    /*while(1)*/
    /*{*/
    connfd = accept(listenfd, (struct sockaddr*)NULL ,NULL); // accept awaiting request

    struct macaroon buff;
    strcpy(buff.buffer,"");
    recv(connfd, &buff, sizeof(buff),0);
    printf("\nRead: %s",buff.buffer);
    close(connfd);    
    sleep(1);
    /*}*/
}

