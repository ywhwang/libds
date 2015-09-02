struct maximal_heap *
maximal_heap_create(uint32 capacity)
{
    struct maximal_heap *heap;

    heap = malloc_ds(sizeof(*heap));
    if (!heap) {
        pr_log_err("Fail to get memory from system.\n");
    } else {
        heap->bin_heap = binary_heap_create(capacity);
    }

    return heap;
}

void
maximal_heap_destroy(struct maximal_heap **heap)
{
    if (!*heap || !heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
    } else {
        binary_heap_destroy(&(*heap)->bin_heap);
        free_ds(*heap);
        *heap = NULL;
    }
}

bool
maximal_heap_empty_p(struct maximal_heap *heap)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
        return false;
    } else {
        return binary_heap_empty_p(heap->bin_heap);
    }
}

bool
maximal_heap_full_p(struct maximal_heap *heap)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
        return true;
    } else {
        return binary_heap_full_p(heap->bin_heap);
    }
}

void
maximal_heap_cleanup(struct maximal_heap *heap)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
    } else {
        binary_heap_cleanup(heap->bin_heap);
    }
}

struct doubly_linked_list *
maximal_heap_node_find(struct maximal_heap *heap, sint64 nice)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
        return NULL;
    } else if (HEAP_NICE_LOWER_LMT == nice || HEAP_NICE_UPPER_LMT == nice) {
        pr_log_warn("Nice specificed reach the limit.\n");
        return NULL;
    } else {
        return binary_heap_node_find(heap->bin_heap, nice);
    }
}

struct doubly_linked_list *
maximal_heap_node_find_max(struct maximal_heap *heap)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
        return NULL;
    } else {
        return binary_heap_node_root(heap->bin_heap);
    }
}

void
maximal_heap_node_insert(struct maximal_heap *heap, void *val, sint64 nice)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
    } else if (HEAP_NICE_LOWER_LMT == nice || HEAP_NICE_UPPER_LMT == nice) {
        pr_log_warn("Nice specificed reach the limit.\n");
    } else {
        binary_heap_node_insert(heap->bin_heap, val, nice,
            &binary_heap_order_maximal);
    }
}

struct doubly_linked_list *
maximal_heap_node_remove(struct maximal_heap *heap, sint64 nice)
{
    uint32 index;

    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
        return NULL;
    } else if (!binary_heap_node_contains_p(heap->bin_heap, nice, &index)) {
        pr_log_warn("No such the node of heap, nothing will be done.\n");
        return NULL;
    } else {
        return binary_heap_node_remove(heap->bin_heap, index,
            &binary_heap_order_maximal);
    }
}

void
maximal_heap_node_remove_and_destroy(struct maximal_heap *heap, sint64 nice)
{
    uint32 index;

    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
    } else if (!binary_heap_node_contains_p(heap->bin_heap, nice, &index)) {
        pr_log_warn("No such the node of heap, nothing will be done.\n");
    } else {
        binary_heap_node_remove_and_destroy(heap->bin_heap, index,
            &binary_heap_order_maximal);
    }
}

struct doubly_linked_list *
maximal_heap_node_remove_max(struct maximal_heap *heap)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
        return NULL;
    } else {
        return binary_heap_node_remove(heap->bin_heap, HEAP_ROOT_INDEX,
            &binary_heap_order_maximal);
    }
}

void
maximal_heap_node_remove_max_and_destroy(struct maximal_heap *heap)
{
    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
    } else {
        binary_heap_node_remove_and_destroy(heap->bin_heap, HEAP_ROOT_INDEX,
            &binary_heap_order_maximal);
    }
}

void
maximal_heap_node_decrease_nice(struct maximal_heap *heap, sint64 nice, uint32 offset)
{
    uint32 index;
    sint64 new_nice;

    new_nice = nice - offset;

    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
    } else if (0 == offset) {
        pr_log_info("Zero offset of nice, nothing will be done.\n");
    } else if (HEAP_NICE_LOWER_LMT == nice || HEAP_NICE_UPPER_LMT == nice
        || HEAP_NICE_LOWER_LMT == new_nice) {
        pr_log_warn("Nice specificed reach the limit.\n");
    } else if (!binary_heap_node_contains_p(heap->bin_heap, nice, &index)) {
        pr_log_warn("No such the node of heap, nothing will be done.\n");
    } else {
        /*
         * index of nice has been set already.
         */
        binary_heap_nice_alter_percolate(heap->bin_heap, index, new_nice,
            &binary_heap_order_maximal, &binary_heap_percolate_down);
    }
}

void
maximal_heap_node_increase_nice(struct maximal_heap *heap, sint64 nice, uint32 offset)
{
    uint32 index;
    sint64 new_nice;

    new_nice = nice + offset;

    if (!heap) {
        pr_log_warn("Attempt to access NULL pointer.\n");
    } else if (0 == offset) {
        pr_log_info("Zero offset of nice, nothing will be done.\n");
    } else if (HEAP_NICE_LOWER_LMT == nice || HEAP_NICE_UPPER_LMT == nice
        || HEAP_NICE_UPPER_LMT == new_nice) {
        pr_log_warn("Nice specificed reach the limit.\n");
    } else if (!binary_heap_node_contains_p(heap->bin_heap, nice, &index)) {
        pr_log_warn("No such the node of heap, nothing will be done.\n");
    } else {
        /*
         * index of nice has been set already.
         */
        binary_heap_nice_alter_percolate(heap->bin_heap, index, new_nice,
            &binary_heap_order_maximal, &binary_heap_percolate_up);
    }
}
