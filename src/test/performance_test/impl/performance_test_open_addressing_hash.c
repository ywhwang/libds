static void
performance_test_open_addressing_hash_struct_field(uint32 count)
{
    struct open_addressing_hash *hash;

    hash = open_addressing_hash_create(0x1341);

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        open_addressing_hash_load_factor_set(hash, 50);
    }

    PERFORMANCE_TEST_ENDPOINT;

    open_addressing_hash_destroy(&hash);
    performance_test_result_print(SYM_2_STR(open_addressing_hash_struct_field),
        performance_test_time_stamp_period());
}

static void
performance_test_open_addressing_hash_create(uint32 count)
{
    struct open_addressing_hash *hash;

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        hash = open_addressing_hash_create(0x231);
        open_addressing_hash_destroy(&hash);
    }

    PERFORMANCE_TEST_ENDPOINT;

    performance_test_result_print(SYM_2_STR(open_addressing_hash_create),
        performance_test_time_stamp_period());
}

static void
performance_test_open_addressing_hash_destroy(uint32 count)
{
    struct open_addressing_hash *hash;

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        hash = test_open_addressing_hash_sample(0xd);
        open_addressing_hash_destroy(&hash);
    }

    PERFORMANCE_TEST_ENDPOINT;

    performance_test_result_print(SYM_2_STR(open_addressing_hash_destroy),
        performance_test_time_stamp_period());
}

static void
performance_test_open_addressing_hash_load_factor_calculate(uint32 count)
{
    struct open_addressing_hash *hash;

    hash = test_open_addressing_hash_sample(0x18f);

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        open_addressing_hash_load_factor_calculate(hash);
    }

    PERFORMANCE_TEST_ENDPOINT;

    open_addressing_hash_destroy(&hash);
    performance_test_result_print(SYM_2_STR(open_addressing_hash_load_factor_calculate),
        performance_test_time_stamp_period());
}

static void
performance_test_open_addressing_hash_insert(uint32 count)
{
    struct open_addressing_hash *hash;

    count = count >> 5;
    count = 0 == count ? 1000 : count;
    hash = open_addressing_hash_create(count * 3 + 1);

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        open_addressing_hash_insert(&hash, &count + count);
    }

    PERFORMANCE_TEST_ENDPOINT;

    open_addressing_hash_destroy(&hash);
    performance_test_result_print(SYM_2_STR(open_addressing_hash_insert),
        performance_test_time_stamp_period());
}

static void
performance_test_open_addressing_hash_remove(uint32 count)
{
    uint32 tmp;
    struct open_addressing_hash *hash;

    count = count >> 5;
    count = 0 == count ? 1000 : count;
    tmp = count;

    hash = open_addressing_hash_create(count * 3 + 1);

    while (count--) {
        open_addressing_hash_insert(&hash, &count + count);
    }

    count = tmp;

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        open_addressing_hash_remove(hash, &count + count);
    }

    PERFORMANCE_TEST_ENDPOINT;

    open_addressing_hash_destroy(&hash);
    performance_test_result_print(SYM_2_STR(open_addressing_hash_remove),
        performance_test_time_stamp_period());
}

static void
performance_test_open_addressing_hash_find(uint32 count)
{
    uint32 tmp;
    struct open_addressing_hash *hash;

    count = count >> 5;
    count = 0 == count ? 1000 : count;
    tmp = count;

    hash = open_addressing_hash_create(count * 3 + 1);

    while (count--) {
        open_addressing_hash_insert(&hash, &count + count);
    }

    count = tmp;

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        open_addressing_hash_find(hash, &count + count);
    }

    PERFORMANCE_TEST_ENDPOINT;

    open_addressing_hash_destroy(&hash);
    performance_test_result_print(SYM_2_STR(open_addressing_hash_find),
        performance_test_time_stamp_period());
}

static void
performance_test_open_addressing_hash_rehashing(uint32 count)
{
    struct open_addressing_hash *hash;

    count = count >> 13;
    count = 0 == count ? 100 : count;

    hash = test_open_addressing_hash_sample(0x1);

    PERFORMANCE_TEST_CHECKPOINT;

    while (count--) {
        hash = open_addressing_hash_rehashing(&hash);
    }

    PERFORMANCE_TEST_ENDPOINT;

    open_addressing_hash_destroy(&hash);
    performance_test_result_print(SYM_2_STR(open_addressing_hash_rehashing),
        performance_test_time_stamp_period());
}

