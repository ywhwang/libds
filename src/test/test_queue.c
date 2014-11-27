#include "impl/test_array_queue.c"

void
queue_unit_test(void)
{
    array_queue_unit_test();
    return;
}

static void
array_queue_unit_test(void)
{
    void (*all_tests[])(void) = {
        &test_array_queue_create,
        &test_array_queue_destroy,
        &test_array_queue_expand_space,
        &test_array_queue_capacity,
        &test_array_queue_rest_space,
        &test_array_queue_is_full,
        &test_array_queue_is_empty,
        &test_array_queue_enter,
        &test_array_queue_leave,
        &test_array_queue_cleanup,
        &test_array_queue_iterate,
    };
    register void (**iter)(void);

    fprintf(stdout, "\n  >> Array Queue Unit Test <<\n");
    iter = all_tests;
    while (iter < all_tests + sizeof(all_tests) / sizeof(all_tests[0])) {
        (*iter++)();
    }

    fprintf(stdout, "  >> Test Finished.\n");
    return;
}