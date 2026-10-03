#pragma once

#define SOME(type, array, res, cond) \
    type * res = array[0]; \
    \
    for (int i = 0; array[i] != NULL; i++) { \
        if (cond) \
            break; \
        res = array [i + 1]; \
    } 
