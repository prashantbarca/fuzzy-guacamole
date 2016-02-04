/*
 * macaroon.h
 * Copyright (C) 2016 prashant <prashant@prashant-Geekpad>
 *
 * Distributed under terms of the MIT license.
 */

#ifndef __MACAROON_H__
#define __MACAROON_H__

#include<gcrypt.h>
#include<pthread.h>
#include "simon.h"

struct macaroon 
{
    char buffer[1025];
};
#endif /* !__MACAROON_H__ */

