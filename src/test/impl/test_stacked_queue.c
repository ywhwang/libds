static void
test_stacked_queue_create(void)
{
    bool is_passed;
    struct stacked_queue *queue;

    queue = stacked_queue_create();
    is_passed = true;

    if (queue->enter->space.dim != queue->leave->space.dim) {
        is_passed = false;
    }

    if (queue->enter->space.dim != queue->dim &&
        0u == queue->sid) {
        is_passed = false;
    }

    stacked_queue_destroy(&queue);
    test_result_print(SYM_2_STR(stacked_queue_create), is_passed);
    return;
}

static void
test_stacked_queue_destroy(void)
{
    bool is_passed;
    struct stacked_queue *queue;

    queue = stacked_queue_create();
    is_passed = true;

    stacked_queue_destroy(&queue);
    if (NULL != queue) {
        is_passed = false;
    }

    test_result_print(SYM_2_STR(stacked_queue_destroy), is_passed);
    return;
}

static void
test_stacked_queue_expand_space(void)
{
    bool is_passed;
    struct stacked_queue *queue;
    uint32 capacity;
    uint32 extra;

    queue = stacked_queue_create();
    is_passed = true;
    capacity = stacked_queue_capacity(queue);
    extra = 1023;

    stacked_queue_expand_space(queue, extra);
    if (capacity + extra != stacked_queue_capacity(queue)) {
        is_passed = false;
    }

    if (capacity + extra != queue->enter->space.dim
        || capacity + extra != queue->leave->space.dim) {
        is_passed = false;
    }

    stacked_queue_destroy(&queue);
    test_result_print(SYM_2_STR(stacked_queue_expand_space), is_passed);
    return;
}

static void
test_stacked_queue_capacity(void)
{
    bool is_passed;
    struct stacked_queue *queue;

    queue = stacked_queue_create();
    is_passed = true;

    if (0 != stacked_queue_capacity(NULL)) {
        is_passed = false;
    }

    if (queue->dim != stacked_queue_capacity(queue)) {
        is_passed = false;
    }

    stacked_queue_expand_space(queue, 0);
    if (queue->dim != stacked_queue_capacity(queue)) {
        is_passed = false;
    }

    stacked_queue_destroy(&queue);
    test_result_print(SYM_2_STR(stacked_queue_capacity), is_passed);
    return;
}

static void
test_stacked_queue_rest_space(void)
{
    bool is_passed;
    struct stacked_queue *queue;

    queue = stacked_queue_create();
    is_passed = true;

    if (0 != stacked_queue_rest_space(NULL)) {
        is_passed = false;
    }

    if (stacked_queue_capacity(queue) != stacked_queue_rest_space(queue)) {
        is_passed = false;
    }

    stacked_queue_enter(queue, queue);
    if (stacked_queue_capacity(queue) != stacked_queue_rest_space(queue) + 1) {
        is_passed = false;
    }

    stacked_queue_destroy(&queue);
    test_result_print(SYM_2_STR(stacked_queue_rest_space), is_passed);
    return;
}

/*
static void
test_stacked_queue_create(void)
{
    bool is_passed;
    struct stacked_queue *queue;

    queue = stacked_queue_create();
    is_passed = true;


    stacked_queue_destroy(&queue);
    test_result_print(SYM_2_STR(stacked_queue_create), is_passed);
    return;
}
*/
