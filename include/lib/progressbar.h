#pragma once

#define _GNU_SOURCE

#include <math.h>
#include <stdio.h>

#include <lib/autofree.h>
#include <lib/string-utils.h>

__attribute__((used))
static char* mk_progress_bar(int fill_length, int max, int total_length) {
    if (max <= 0 || total_length < 0)
        return strdup("");

    double progress = fmin((double)fill_length / max, 1.0);
    int filled_length = (int)floor(total_length * progress);
    int empty_length = total_length - filled_length;

    char* bar = NULL;

    for (int i = 0; i < filled_length; i++)
        APPEND(bar, "█");

    for (int i = 0; i < empty_length; i++)
        APPEND(bar, "░");

    return bar;
}
