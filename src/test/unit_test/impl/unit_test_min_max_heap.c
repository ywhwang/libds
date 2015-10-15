static inline void
unit_test_min_max_heap_struct_field(void)
{
    bool pass;
    uint32 index;
    struct min_max_heap *heap;
    struct doubly_linked_list *tmp;

    pass = true;
    index = 1;
    heap = test_min_max_heap_sample(0x6bca, 0x3ed1);

    RESULT_CHECK_uint32(heap->alias->size, min_max_heap_size(heap), &pass);
    RESULT_CHECK_uint32(heap->alias->capacity, min_max_heap_capacity(heap), &pass);
    RESULT_CHECK_sint64(heap->alias->base[index]->nice,
        min_max_heap_nice(heap, index), &pass);
    RESULT_CHECK_pointer(heap->alias->base[index]->link,
        min_max_heap_link(heap, index), &pass);
    tmp = min_max_heap_link(heap, index);
    RESULT_CHECK_pointer(NULL, min_max_heap_link_set(heap, index, NULL), &pass);
    RESULT_CHECK_pointer(tmp, min_max_heap_link_set(heap, index, tmp), &pass);

    min_max_heap_destroy(&heap);
    unit_test_result_print(SYM_2_STR(min_max_heap_struc_field), pass);
}

static inline void
unit_test_min_max_heap_create(void)
{
    bool pass;
    uint32 capacity;
    struct min_max_heap *heap;
    struct collision_chain **iter;

    pass = true;
    capacity = 0u;

    heap = min_max_heap_create(capacity++);
    min_max_heap_destroy(&heap);

    heap = min_max_heap_create(capacity);
    RESULT_CHECK_uint32(capacity, min_max_heap_capacity(heap), &pass);
    RESULT_CHECK_uint32(0u, min_max_heap_size(heap), &pass);

    iter = heap->alias->base;
    while (iter < heap->alias->base + u_offset(heap->alias->capacity, 1)) {
        RESULT_CHECK_pointer(NULL, *iter++, &pass);
    }

    min_max_heap_destroy(&heap);
    unit_test_result_print(SYM_2_STR(min_max_heap_create), pass);
}

static inline void
unit_test_min_max_heap_destroy(void)
{
    bool pass;
    struct min_max_heap *heap;

    pass = true;
    heap = NULL;

    min_max_heap_destroy(&heap);

    heap = min_max_heap_create(0u);
    min_max_heap_destroy(&heap);
    RESULT_CHECK_pointer(NULL, heap, &pass);
    unit_test_result_print(SYM_2_STR(min_max_heap_destroy), pass);
}

static inline void
unit_test_min_max_heap_empty_p(void)
{
    bool pass;
    struct min_max_heap *heap;

    pass = true;
    heap = NULL;

    RESULT_CHECK_bool(false, min_max_heap_empty_p(heap), &pass);

    heap = test_min_max_heap_sample(0x4234, 0x2234);
    RESULT_CHECK_bool(false, min_max_heap_empty_p(heap), &pass);
    min_max_heap_destroy(&heap);

    heap = min_max_heap_create(0u);
    RESULT_CHECK_bool(true, min_max_heap_empty_p(heap), &pass);

    min_max_heap_destroy(&heap);
    unit_test_result_print(SYM_2_STR(min_max_heap_empty_p), pass);
}

static inline void
unit_test_min_max_heap_full_p(void)
{
    bool pass;
    struct min_max_heap *heap;

    pass = true;
    heap = NULL;

    RESULT_CHECK_bool(true, min_max_heap_full_p(heap), &pass);

    heap = test_min_max_heap_sample(0x1, 0x1);
    RESULT_CHECK_bool(true, min_max_heap_full_p(heap), &pass);
    min_max_heap_destroy(&heap);

    heap = min_max_heap_create(0u);
    RESULT_CHECK_bool(false, min_max_heap_full_p(heap), &pass);

    min_max_heap_destroy(&heap);
    unit_test_result_print(SYM_2_STR(min_max_heap_full_p), pass);
}

static inline void
unit_test_min_max_heap_cleanup(void)
{
    bool pass;
    struct min_max_heap *heap;

    pass = true;
    heap = NULL;

    min_max_heap_cleanup(heap);

    heap = test_min_max_heap_sample(0x3345, 0x204E);
    min_max_heap_cleanup(heap);

    RESULT_CHECK_bool(false, min_max_heap_full_p(heap), &pass);
    RESULT_CHECK_bool(true, min_max_heap_empty_p(heap), &pass);

    min_max_heap_destroy(&heap);
    unit_test_result_print(SYM_2_STR(min_max_heap_cleanup), pass);
}

