#ifndef HAVE_DEFINED_DEPENDS_H
#define HAVE_DEFINED_DEPENDS_H

#if defined LIBC
#include <unistd.h>
#include <limits.h>
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stddef.h>
#include <sys/time.h>

#define dp_atoll               atoll
#define dp_assert              assert
#define dp_exit                exit
#define dp_fclose              fclose
#define dp_fopen               fopen
#define dp_fprintf             fprintf
#define dp_fgets               fgets
#define dp_free                free
#define dp_fwrite              fwrite
#define dp_getpid              getpid
#define dp_gettimeofday        gettimeofday
#define dp_malloc              malloc
#define dp_memcpy              memcpy
#define dp_memset              memset
#define dp_printf              printf
#define dp_rand                rand
#define dp_realloc             realloc
#define dp_sprintf             sprintf
#define dp_sqrt                sqrt
#define dp_sscanf              sscanf
#define dp_strchr              strchr
#define dp_strlen              strlen
#define dp_strncmp             strncmp
#define dp_strncpy             strncpy

#elif defined KERNEL

typedef unsigned int           size_t;

extern void kassert(bool);
extern void kexit(uint32);
extern void *kmalloc(uint32);
extern void kmemcpy(void *, void *, uint32);
extern void *realloc(void *, uint32);
extern void printf_vga(char *format, ...);
extern double sqrt(double);
extern void exit(int);
extern uint32 rand(void);
extern void *memset(void *, uint8 c, uint32);

#define UINT_MAX               ((uint32)-1)
#define NULL                   ((void *)0)
#define dp_assert              kassert
#define dp_exit                exit
#define dp_malloc              kmalloc
#define dp_memcpy              kmemcpy
#define dp_memset              kmemset
#define dp_printf              printf_vga
#define dp_rand                rand
#define dp_realloc             krealloc
#define dp_sqrt                sqrt

#endif

#endif

