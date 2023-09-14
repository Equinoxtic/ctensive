#ifndef CTENSIVE_H
#define CTENSIVE_H

#include<stdlib.h>      // malloc(), calloc()
#include<stdio.h>       // printf()
#include<stdbool.h>     // Boolean type
#include<string.h>      // strcmp()

#ifndef MALLOC
    #define MALLOC(sz)      malloc(sz)
#endif // MALLOC

#ifndef CALLOC
    #define CALLOC(n,sz)    calloc(n,sz)
#endif // CALLOC

#ifndef FREE
    #define FREE(ptr)       free(ptr)
#endif

typedef char* cstr_t;
typedef unsigned short int u_int16;
typedef unsigned int u_int32;
typedef unsigned long long int u_int64;

inline static void cputs(cstr_t s, u_int32 times)
{
    if (times > 0 && s[0] == '\0') {
        for (int i = 0; i < times; ++i) {
            printf("%s", s);
        }
    }
}

inline static int strempty(cstr_t s)
{
    if (s[0] != '\0') {
        return 1;
    }
    return 0;
}

inline static int strcompare(cstr_t as, cstr_t bs)
{
    while(strcmp(as, bs) != 0)
    {
        return 1;
    }
    return 0;
}

#endif // CTENSIVE_H
