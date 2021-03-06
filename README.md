[![Build Status](https://travis-ci.org/Incarnation-p-lee/libds.svg?branch=trunk)](https://travis-ci.org/Incarnation-p-lee/libds)

##UNIFIED DATA STRUCTURE IMPLEMENTATION LIB OF C LANGUAGE

### build
    1. sh src/script/build.sh DEBUG/RELEASE
                              X86_64/X86_32
                              LIBC
                              ELF/OBJ/DYN
                              PROFILE         -optional
                              CODE_COVERAGE   -optional

    2. Output output/out/ds.elf
              output/out/ds.h
              output/out/libds.a
              output/out/libds.so

### Design

    This project export sorts of API of data structure with libds.so or libds.a.

### list

    The following data structure implemented in this project.
    1. linked list
        a. single linked list
        b. doubly linked list
        c. skip linked list.
    2. stack
        a. array stack
        b. linked stack
    3. queue
        a. array queue
        b. stacked queue
        c. doubly end queue
    4. tree
        a. binary search tree
        b. avl tree
        c. splay tree
        d. binary indexed tree
    5. hash
        a. separate chain hash
        b. open addressing hash
    6. heap
        a. minimal heap
        b. maximal heap
        c. min-max heap
        d. leftist heap
    7. sort
        a. insertion sort
        b. shell sort
        c. heap sort
        d. merge sort
        e. quick sort

