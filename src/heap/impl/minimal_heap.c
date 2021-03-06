struct minimal_heap *
minimal_heap_create(uint32 capacity)
{
    struct minimal_heap *heap;

    heap = memory_cache_allocate(sizeof(*heap));
    heap->alias = binary_heap_create(capacity);

    return heap;
}

void
minimal_heap_destroy(struct minimal_heap **heap)
{
    if (!complain_null_pointer_p(heap) && !complain_null_pointer_p(*heap)) {
        binary_heap_destroy(&(*heap)->alias);
        memory_cache_dp_free(*heap);
        *heap = NULL;
    }
}

bool
minimal_heap_empty_p(struct minimal_heap *heap)
{
    if (complain_null_pointer_p(heap)) {
        return false;
    } else {
        return binary_heap_empty_p(heap->alias);
    }
}

bool
minimal_heap_full_p(struct minimal_heap *heap)
{
    if (complain_null_pointer_p(heap)) {
        return true;
    } else {
        return binary_heap_full_p(heap->alias);
    }
}

void
minimal_heap_cleanup(struct minimal_heap *heap)
{
    if (!complain_null_pointer_p(heap)) {
        binary_heap_cleanup(heap->alias);
    }
}

void *
minimal_heap_get_min(struct minimal_heap *heap)
{
    if (complain_null_pointer_p(heap)) {
        return NULL;
    } else {
        return binary_heap_root(heap->alias);
    }
}

void
minimal_heap_insert(struct minimal_heap *heap, void *val, sint64 nice)
{
    if (complain_null_pointer_p(heap)) {
        return;
    } if (binary_heap_nice_legal_p(nice)) {
        binary_heap_insert(heap->alias, val, nice,
            &binary_heap_minimal_ordered_p);
    }
}

static inline void *
minimal_heap_remove_internal(struct minimal_heap *heap, uint32 index)
{
    sint64 nice;
    struct heap_data *tmp;
    struct binary_heap *alias;

    dp_assert(!complain_null_pointer_p(heap));
    dp_assert(!binary_heap_empty_p(heap->alias));
    dp_assert(binary_heap_structure_legal_p(heap->alias));
    dp_assert(binary_heap_index_legal_p(heap->alias, index));

    alias = heap->alias;

    tmp = HEAP_DATA(alias, index);
    HEAP_DATA(alias, index) = NULL;
    nice = HEAP_NICE(alias, INDEX_ROOT) - 1;

    /*
     * percolate current index node to root, then remove the root.
     */
    index = binary_heap_reorder(alias, index, nice, &binary_heap_minimal_ordered_p);

    dp_assert(INDEX_ROOT == index);
    dp_assert(complain_null_pointer_p(HEAP_DATA(alias, INDEX_ROOT)));

    HEAP_DATA(alias, INDEX_ROOT) = tmp;
    return binary_heap_remove_root(alias, &binary_heap_minimal_ordered_p);
}

void *
minimal_heap_remove(struct minimal_heap *heap, uint32 index)
{
    if (complain_null_pointer_p(heap)) {
        return NULL;
    } else if (!binary_heap_index_legal_p(heap->alias, index)) {
        return NULL;
    } else if (INDEX_ROOT == index) {
        return binary_heap_remove_root(heap->alias,
            &binary_heap_minimal_ordered_p);
    } else {
        return minimal_heap_remove_internal(heap, index);
    }
}

void *
minimal_heap_remove_min(struct minimal_heap *heap)
{
    if (complain_null_pointer_p(heap)) {
        return NULL;
    } else if (binary_heap_empty_p(heap->alias)) {
        pr_log_warn("Attempt to remove node in empty heap.\n");
        return NULL;
    } else {
        return binary_heap_remove_root(heap->alias,
            &binary_heap_minimal_ordered_p);
    }
}

static inline void
minimal_heap_nice_alter(struct minimal_heap *heap, uint32 index,
    sint64 new_nice)
{
    struct heap_data *tmp;
    struct binary_heap *alias;

    dp_assert(!complain_null_pointer_p(heap));
    dp_assert(binary_heap_structure_legal_p(heap->alias));
    dp_assert(binary_heap_index_legal_p(heap->alias, index));

    alias = heap->alias;
    tmp = HEAP_DATA(alias, index);
    HEAP_DATA(alias, index) = NULL;

    index = binary_heap_reorder(alias, index, new_nice,
        &binary_heap_minimal_ordered_p);
    dp_assert(NULL == HEAP_DATA(alias, index));

    tmp->nice = new_nice;
    HEAP_DATA(alias, index) = tmp;
}

void
minimal_heap_decrease_nice(struct minimal_heap *heap, uint32 index,
    uint32 offset)
{
    sint64 nice;

    if (complain_null_pointer_p(heap)) {
        return;
    } else if (complain_zero_size_p(offset)) {
        return;
    } else if (!binary_heap_index_legal_p(heap->alias, index)) {
        return;
    } else {
        nice = HEAP_NICE(heap->alias, index) - offset;
        minimal_heap_nice_alter(heap, index, nice);
    }
}

void
minimal_heap_increase_nice(struct minimal_heap *heap, uint32 index,
    uint32 offset)
{
    sint64 nice;

    if (complain_null_pointer_p(heap)) {
        return;
    } else if (complain_zero_size_p(offset)) {
        return;
    } else if (!binary_heap_index_legal_p(heap->alias, index)) {
        return;
    } else {
        nice = HEAP_NICE(heap->alias, index) + offset;
        minimal_heap_nice_alter(heap, index, nice);
    }
}

static inline void
minimal_heap_build_internal(struct minimal_heap *heap)
{
    uint32 iter;
    uint32 index;
    sint64 nice;
    struct heap_data *tmp;
    struct binary_heap *alias;

    dp_assert(!complain_null_pointer_p(heap));
    dp_assert(binary_heap_full_p(heap->alias));
    dp_assert(binary_heap_structure_legal_p(heap->alias));

    alias = heap->alias;
    iter = HEAP_SIZE(alias) / 2;

    while (iter != INDEX_INVALID) {
        index = iter;
        tmp = HEAP_DATA(alias, index);
        nice = HEAP_NICE(alias, index);
        HEAP_DATA(alias, index) = NULL;

        index = binary_heap_reorder(alias, index, nice,
            &binary_heap_minimal_percolate_down);

        dp_assert(NULL == HEAP_DATA(alias, index));
        HEAP_DATA(alias, index) = tmp;

        iter--;
    }
}

struct minimal_heap *
minimal_heap_build(struct heap_data **hd_array, uint32 size)
{
    struct minimal_heap *heap;

    if (complain_null_pointer_p(hd_array)) {
        return NULL;
    } else if (complain_zero_size_p(size)) {
        return NULL;
    } else {
        heap = memory_cache_allocate(sizeof(*heap));
        heap->alias = memory_cache_allocate(sizeof(*heap->alias));

        heap->alias->base = hd_array;
        heap->alias->capacity = size - 1;
        heap->alias->size = size - 1;

        hd_array[0] = NULL;
        minimal_heap_build_internal(heap);

        return heap;
    }
}

