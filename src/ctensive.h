#ifndef CTENSIVE_H
#define CTENSIVE_H

#include <stdlib.h>      // malloc(), calloc(), exit()
#include <stdio.h>       // printf()
#include <stdbool.h>     // Boolean type
#include <string.h>      // strcmp()

#ifdef _WIN32
#include <Windows.h>     // Sleep()
#else
#include <unistd.h>      // usleep()
#endif

#ifndef MALLOC
    #define MALLOC(sz)      malloc(sz)
#endif // MALLOC

#ifndef CALLOC
    #define CALLOC(n,sz)    calloc(n,sz)
#endif // CALLOC

#ifndef FREE
    #define FREE(ptr)       free(ptr)
#endif // FREE

typedef char* cstr_t;
typedef unsigned short int u_int16;
typedef unsigned int u_int32;
typedef unsigned long long int u_int64;

inline static void cputs(cstr_t s, u_int32 times)
{
    if (times > 0 && s[0] == '\0') {
        for (u_int32 i = 0; i < times; ++i) {
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

#ifdef CTENSIVE_ENABLE_ASSERT
inline static void impassert(int condition, const cstr_t msg)
{
    if (condition == 0) {
        if (msg[0] != '\0') {
            printf("%s", msg);
        } else {
            printf("\n");
        }
        exit(0);
    }
}
#endif

#ifndef DISABLE_SLEEP
    #ifdef _WIN32
        #ifndef SLEEP_MS
            #define SLEEP_MS(ms)        Sleep(ms)
        #endif // SLEEP_MS
        #ifndef SLEEP
            #define SLEEP(s)            Sleep(s * 1000)
        #endif // SLEEP
    #else
        #ifndef SLEEP_MS
            #define SLEEP_MS(ms)        usleep(ms)
        #endif // SLEEP_MS
        #ifndef SLEEP
            #define SLEEP(s)            usleep(s * 1000)
        #endif // SLEEP
    #endif
#endif

#ifndef DISABLE_TRACE_LOGGING
static const cstr_t info_k = "[*] INFO: ";
static const cstr_t warn_k = "[?] WARN: ";
static const cstr_t error_k = "[!] ERROR: ";

inline static void print_trace(const cstr_t s, u_int32 level)
{
    if (s[0] != '\0')
    {
        cstr_t level_str = (cstr_t)MALLOC(sizeof(cstr_t)*64);
        
        if (level == 0) {
            strcpy(level_str, info_k);
        } else if (level == 1) {
            strcpy(level_str, warn_k);
        } else if (level == 2) {
            strcpy(level_str, error_k);
        }
        
        printf("%s%s", level_str, s);
        
        FREE(level_str);
    }
}
#endif

#ifndef DISABLE_DRAW_FUNCTIONS
inline static void draw_line(u_int32 len, u_int32 variation)
{
    u_int32 n_len = 0;
    
    if (len > 128) n_len = 128;
    else if (len <= 0) n_len = 75;
    else n_len = len;
    
    const char c_arr[] = {
        '-', '+', '=', '*', '#', '.', 
        '_', '/', '\\', '|', '~', ':',
    };
    
    u_int32 n_variation = 0;
    if (variation > sizeof(c_arr)/sizeof(c_arr[0])) n_variation = 0;
    else n_variation = variation;
    
    for (u_int32 i = 0; i < n_len; ++i) {
        printf("%c", c_arr[n_variation]);
    }
}

inline static void draw_option(const cstr_t s, const cstr_t desc)
{
    if (s[0] != '\0' && s[0] != '\0') {
        printf("\n[%s]: \"%s\"", s, desc);
    }
}

inline static void draw_prompt(const cstr_t s, cstr_t s_optiona, cstr_t s_optionb)
{
    if (s[0] != '\0' && s[0] != '\0' && s[0] != '\0') {
        printf("\n> %s (%s/%s) ", s, s_optiona, s_optionb);
    }
}
#endif

inline static void ccmdcall(cstr_t cmd_s)
{
    if (cmd_s[0] != '\0') {
        char v_cmd[512];
        strcpy(v_cmd, cmd_s);
        
        // Just to prevent users from doing this lol
        if (strcmp(v_cmd, "exit") != 0) {
            system(v_cmd);
        } else {
            printf("\n\nYou cannot use the \"exit\" command this way,");
            printf("\nUse the built-in \"cexit()\" function instead.");
            printf("\n:)\n\n");
        }
    } else {
        #ifndef DISABLE_TRACE_LOGGING
        print_trace("Cannot execute command", 2);
        #else
        printf("ERROR: Cannot execute command");
        #endif
    }
}

inline static void cclearscreen()
{
    #ifdef _WIN32
    ccmdcall("cls");
    #else
    ccmdcall("clear");
    #endif
}

inline static void cexit()
{
    exit(0);
}

#endif // CTENSIVE_H
