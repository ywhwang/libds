#ifndef HAVE_DEFINED_HEAP_OPTIMIZE_H
#define HAVE_DEFINED_HEAP_OPTIMIZE_H

#if defined X86_64
    /*
     * if (NULL == node) {
     *     return -1;
     * } else {
     *     return node->npl;
     * }
     */
    #define leftist_heap_npl_optimize(node, npl) \
        asm volatile (                           \
            "mov            %1, %%rdx\n\t"       \
            "cmp          $0x0, %%rdx\n\t"       \
            "mov   $0xffffffff, %0\n\t"          \
            "cmovz       %%rsp, %%rdx\n\t"       \
            "cmovnz 0x0(%%rdx), %0\n\t"          \
            :"=r"(npl)                           \
            :"r"(node)                           \
            :"rdx")

#endif

#if defined X86_32
    /*
     * if (NULL == node) {
     *     return -1;
     * } else {
     *     return node->npl;
     * }
     */
    #define leftist_heap_npl_optimize(node, npl) \
        asm volatile (                           \
            "mov            %1, %%edx\n\t"       \
            "cmp          $0x0, %%edx\n\t"       \
            "mov   $0xffffffff, %0\n\t"          \
            "cmovz       %%esp, %%edx\n\t"       \
            "cmovnz 0x0(%%edx), %0\n\t"          \
            :"=r"(npl)                           \
            :"r"(node)                           \
            :"edx")

#endif


#endif

