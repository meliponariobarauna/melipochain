// Copyright (c) 2014-2019 Coin Sciences Ltd
// Meliponariod code distributed under the GPLv3 license, see COPYING file.

#include "meliponario/meliponario.h"

void* custom_get_blockchain_default(const char *param,int* size,void *param_in)
{
    *size=0;
    
    return NULL;
}

