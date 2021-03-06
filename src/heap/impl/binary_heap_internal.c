static inline struct binary_heap *
binary_heap_create(uint32 capacity)
{
    struct binary_heap *heap;
    register struct heap_data **iterator;

    if (complain_zero_size_p(capacity)) {
        capacity = DEFAULT_BINARY_HEAP_SIZE;
    }

    heap = memory_cache_allocate(sizeof(*heap));
    heap->base = memory_cache_allocate(sizeof(*iterator) * (capacity + 1));

    heap->capacity = capacity;
    heap->size = 0;

    iterator = heap->base;
    while (iterator < heap->base + u_offset(capacity, 1)) {
        *iterator++ = NULL;
    }

    return heap;
}

static inline void
binary_heap_destroy(struct binary_heap **heap)
{
    dp_assert(NULL != heap);
    dp_assert(binary_heap_structure_legal_p(*heap));

    binary_heap_cleanup(*heap);
    memory_cache_dp_free((*heap)->base);
    memory_cache_dp_free(*heap);

    *heap = NULL;
}

static inline bool
binary_heap_empty_p(struct binary_heap *heap)
{
    dp_assert(binary_heap_structure_legal_p(heap));

    return heap->size == 0 ? true : false;
}

static inline bool
binary_heap_full_p(struct binary_heap *heap)
{
    dp_assert(binary_heap_structure_legal_p(heap));

    return heap->size == heap->capacity ? true : false;
}

static inline void
binary_heap_cleanup(struct binary_heap *heap)
{
    register uint32 index;

    dp_assert(binary_heap_structure_legal_p(heap));

    index = INDEX_FIRST;

    while (index <= INDEX_LAST(heap)) {
        memory_cache_dp_free(HEAP_DATA(heap, index));
        HEAP_DATA(heap, index) = NULL;
        index++;
    }

    heap->size = 0;
}

static inline void *
binary_heap_root(struct binary_heap *heap)
{
    dp_assert(binary_heap_structure_legal_p(heap));

    return HEAP_VAL(heap, INDEX_ROOT);
}

static inline void
binary_heap_capacity_extend(struct binary_heap *heap)
{
    struct heap_data **new;
    uint32 size;

    dp_assert(binary_heap_structure_legal_p(heap));

    size = sizeof(heap->base[0]) * u_offset(heap->capacity * 2, 1);
    new = memory_cache_allocate(size);
    memset(new, 0, size);

    size = sizeof(heap->base[0]) * u_offset(heap->capacity, 1);
    dp_memcpy(new, heap->base, size);

    heap->capacity = heap->capacity * 2;
    memory_cache_dp_free(heap->base);
    heap->base = new;

    dp_assert(binary_heap_structure_legal_p(heap));
}

static inline void
binary_heap_node_create_by_index(struct binary_heap *heap, uint32 index,
    sint64 nice, void *val)
{
    dp_assert(complain_null_pointer_p(heap->base[index]));
    dp_assert(binary_heap_nice_legal_p(nice));
    dp_assert(binary_heap_index_legal_p(heap, index));
    dp_assert(binary_heap_structure_legal_p(heap));

    HEAP_DATA(heap, index) = binary_heap_node_create(nice, val);
}

static inline struct heap_data *
binary_heap_node_create(sint64 nice, void *val)
{
    struct heap_data *retval;

    dp_assert(binary_heap_nice_legal_p(nice));

    retval = memory_cache_allocate(sizeof(*retval));
    retval->nice = nice;
    retval->val = val;

    return retval;
}

/*
 * index      - specific the empty hole index of heap.
 * nice       - nice value of percolate up.
 * heap_order - function pointer of heap order, should be one of function
 *              in file binary_heap_order.c.
 * RETURN the re-ordered index of heap with that nice.
 */
static inline uint32
binary_heap_reorder(struct binary_heap *heap, uint32 index, sint64 nice,
    void *heap_order)
{
    uint32 index_next;
    bool (*order)(struct binary_heap *, uint32, sint64, uint32 *);

    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));
    dp_assert(binary_heap_nice_legal_p(nice));

    order = heap_order;

    while (!(*order)(heap, index, nice, &index_next)) {
        HEAP_DATA(heap, index) = HEAP_DATA(heap, index_next);
        index = index_next;
    }

    HEAP_DATA(heap, index) = NULL;
    return index;
}

static inline bool
binary_heap_child_exist_p(struct binary_heap *heap, uint32 index)
{
    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));

    return INDEX_L_CHILD(index) <= INDEX_LAST(heap) ? true : false;
}

static inline uint32
binary_heap_child_min_nice_index(struct binary_heap *heap, uint32 index)
{
    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));

    if (!binary_heap_child_exist_p(heap, index)) {
        return INDEX_INVALID;
    } else if (INDEX_R_CHILD(index) > INDEX_LAST(heap)) {
        return INDEX_L_CHILD(index);
    } else if (HEAP_L_CHILD_NICE(heap, index) > HEAP_R_CHILD_NICE(heap, index)) {
        return INDEX_R_CHILD(index);
    } else {
        return INDEX_L_CHILD(index);
    }
}

static inline uint32
binary_heap_child_max_nice_index(struct binary_heap *heap, uint32 index)
{
    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));

    if (!binary_heap_child_exist_p(heap, index)) {
        return INDEX_INVALID;
    } else if (INDEX_R_CHILD(index) > INDEX_LAST(heap)) {
        return INDEX_L_CHILD(index);
    } else if (HEAP_L_CHILD_NICE(heap, index) < HEAP_R_CHILD_NICE(heap, index)) {
        return INDEX_R_CHILD(index);
    } else {
        return INDEX_L_CHILD(index);
    }
}

static inline uint32
binary_heap_gdp_randchild_min_nice_index(struct binary_heap *heap, uint32 index)
{
    uint32 begin;
    uint32 ret_index;

    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));
    dp_assert(binary_heap_depth_even_p(heap, index));

    if (!binary_heap_child_exist_p(heap, index)) {
        return INDEX_INVALID;
    } else if (INDEX_LL_CHILD(index) > INDEX_LAST(heap)) {
        return binary_heap_child_min_nice_index(heap, index);
    } else {
        begin = INDEX_LL_CHILD(index);
        ret_index = binary_heap_serial_small_nice_index(heap, begin, 4);

        if (HEAP_NICE(heap, INDEX_R_CHILD(index))
            < HEAP_NICE(heap, ret_index)) {
            return INDEX_R_CHILD(index);
        } else {
            return ret_index;
        }
    }
}

static inline uint32
binary_heap_gdp_randchild_max_nice_index(struct binary_heap *heap, uint32 index)
{
    uint32 begin;
    uint32 ret_index;

    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));
    dp_assert(binary_heap_depth_odd_p(heap, index));

    if (!binary_heap_child_exist_p(heap, index)) {
        return INDEX_INVALID;
    } else if (INDEX_LL_CHILD(index) > INDEX_LAST(heap)) {
        return binary_heap_child_max_nice_index(heap, index);
    } else {
        begin = INDEX_LL_CHILD(index);
        ret_index = binary_heap_serial_big_nice_index(heap, begin, 4);

        if (HEAP_NICE(heap, INDEX_R_CHILD(index))
            > HEAP_NICE(heap, ret_index)) {
            return INDEX_R_CHILD(index);
        } else {
            return ret_index;
        }
    }
}

static inline uint32
binary_heap_serial_small_nice_index(struct binary_heap *heap,
    uint32 index, uint32 count)
{
    uint32 small_index;
    uint32 rest;

    dp_assert(!complain_zero_size_p(count));
    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));

    small_index = index;
    rest = INDEX_LAST(heap) - index + 1;
    count = count > rest ? rest : count;

    while (count--) {
        if (HEAP_NICE(heap, index) < HEAP_NICE(heap, small_index)) {
            small_index = index;
        }
        index++;
    }

    return small_index;
}

static inline uint32
binary_heap_serial_big_nice_index(struct binary_heap *heap,
    uint32 index, uint32 count)
{
    uint32 big_index;
    uint32 rest;

    dp_assert(!complain_zero_size_p(count));
    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_index_legal_p(heap, index));

    big_index = index;
    rest = INDEX_LAST(heap) - index + 1;
    count = count > rest ? rest : count;

    while (count--) {
        if (HEAP_NICE(heap, index) > HEAP_NICE(heap, big_index)) {
            big_index = index;
        }
        index++;
    }

    return big_index;
}

static inline void
binary_heap_insert(struct binary_heap *heap, void *val, sint64 nice,
    void *ordering)
{
    uint32 index;

    dp_assert(binary_heap_nice_legal_p(nice));
    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_valid_ordered_func_ptr_p(ordering));

    if (binary_heap_full_p(heap)) {
        pr_log_warn("Binary heap is full, will rebuild for percolate up.\n");
        binary_heap_capacity_extend(heap);
    }

    heap->size++;
    HEAP_DATA(heap, heap->size) = NULL;

    index = binary_heap_reorder(heap, heap->size, nice, ordering);
    binary_heap_node_create_by_index(heap, index, nice, val);

    dp_assert(binary_heap_ordered_p(heap, ordering));
}

static inline void *
binary_heap_data_destroy(struct heap_data *data)
{
    void * retval;

    dp_assert(!complain_null_pointer_p(data));

    retval = data->val;
    memory_cache_dp_free(data);

    return retval;
}

static inline void *
binary_heap_remove_root(struct binary_heap *heap, void *order)
{
    sint64 nice;
    uint32 index;
    uint32 index_last;
    struct heap_data *last;
    void *retval;

    dp_assert(!binary_heap_empty_p(heap));
    dp_assert(binary_heap_structure_legal_p(heap));
    dp_assert(binary_heap_valid_ordered_func_ptr_p(order));

    index_last = INDEX_LAST(heap);
    retval = binary_heap_data_destroy(HEAP_DATA(heap, INDEX_ROOT));
    heap->size--;

    if (INDEX_ROOT != index_last) {
        nice = HEAP_NICE(heap, index_last);
        last = HEAP_DATA(heap, index_last);

        HEAP_DATA(heap, index_last) = NULL;

        index = binary_heap_reorder(heap, INDEX_ROOT, nice, order);
        dp_assert(NULL == HEAP_DATA(heap, index));

        HEAP_DATA(heap, index) = last;
    }

    dp_assert(binary_heap_ordered_p(heap, order));
    return retval;
}

static inline uint32
binary_heap_depth(uint32 index)
{
    uint32 depth;

    dp_assert(INDEX_INVALID != index);

    depth = 0;

    while (index >= (1 << (depth + 1))) {
        depth++;
    }

    return depth;
}

static inline bool
binary_heap_nice_legal_p(sint64 nice)
{
    if (nice > HEAP_NICE_LOWER_LMT && nice < HEAP_NICE_UPPER_LMT) {
        return true;
    } else {
        pr_log_warn("Nice specificed reach the limit.\n");
        return false;
    }
}

static inline bool
binary_heap_index_legal_p(struct binary_heap *heap, uint32 index)
{
    dp_assert(binary_heap_structure_legal_p(heap));

    if (INDEX_INVALID == index || index > INDEX_LAST(heap)) {
        pr_log_warn("Illegal index value of heap.\n");
        return false;
    } else {
        return true;
    }
}

static inline bool
binary_heap_structure_legal_p(struct binary_heap *heap)
{
    if (complain_null_pointer_p(heap)) {
        return false;
    } else if (complain_null_pointer_p(heap->base)) {
        return false;
    } else if (complain_zero_size_p(heap->capacity)) {
        return false;
    } else {
        return true;
    }
}

