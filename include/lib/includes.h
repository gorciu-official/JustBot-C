#pragma once

#define INCLUDES(array, checking, reply_var_name, cond) \
    bool reply_var_name = false; \
    do { \
        for (size_t i = 0; (array)[i] != NULL; ++i) { \
            __auto_type checking = (array)[i]; \
            if (cond) { \
                reply_var_name = true; \
                break; \
            } \
        } \
    } while (0);

#define INCLUDES_I(array, checking, reply_var_name, cond) \
    bool reply_var_name = false; \
    do { \
        for (size_t i = 0; (array)[i] != 0; ++i) { \
            __auto_type checking = (array)[i]; \
            if (cond) { \
                reply_var_name = true; \
                break; \
            } \
        } \
    } while (0);
