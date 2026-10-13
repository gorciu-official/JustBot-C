#pragma once

#include <stdlib.h>

static inline void free_cleanup(void *p) {
    free(*(void**)p);
}

// we may define it as keyword-like ;) 
// it's kinda cool
#define autofree __attribute__((cleanup(free_cleanup)))
