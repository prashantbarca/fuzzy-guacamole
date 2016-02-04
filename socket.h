/*
 * socket.h
 * Copyright (C) 2016 prashant <prashant@prashant-Geekpad>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef __SOCKET_H__
#define __SOCKET_H__
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

extern void send(int port);
extern void receive(int port);

#endif /* !__SOCKET_H__ */

