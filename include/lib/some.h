#pragma once

#define SOME(type, array, res, cond) \
    type * res = commands[0]; \
    \
    for (int i = 0; commands[i] != NULL; i++) { \
        if (cond) \
            break; \
        res = array [i + 1]; \
    } 
