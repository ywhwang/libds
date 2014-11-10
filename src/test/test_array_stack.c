static void
test_array_stack_create(void)
{
    bool is_passed;
    struct array_stack *ins;

    ins = array_stack_create();
    is_passed = true;

    if (ins->size != ins->rest || (void*)ins->loc.sp != ins->loc.bp) {
        is_passed = false;
    }
    array_stack_destroy(&ins);

    test_result_print(SYM_2_STR(array_stack_create), is_passed);
    return;
}

static void
test_array_stack_destroy(void)
{
    bool is_passed;
    struct array_stack *ins;

    ins = array_stack_create();
    is_passed = true;

    array_stack_destroy(&ins);

    if (NULL != ins) {
        is_passed = false;
    }

    test_result_print(SYM_2_STR(array_stack_destroy), is_passed);
    return;
}

static void
test_array_stack_expand_space(void)
{
    bool is_passed;
    struct array_stack *ins;
    unsigned stk_size;
    unsigned stk_rest;

    ins = array_stack_create();
    is_passed = true;
    stk_size = ins->size;
    stk_rest = ins->rest;

    array_stack_expand_space(ins, 0);
    if ((ins->size != stk_size * 2 + 32)
        || (ins->rest != stk_rest + stk_size + 32)) {
        is_passed = false;
    }

    stk_size = ins->size;
    stk_rest = ins->rest;
    ins = array_stack_expand_space(ins, 1024);
    if ((ins->size != stk_size + 1024) || (ins->rest != stk_rest + 1024)) {
        is_passed = false;
    }

    array_stack_destroy(&ins);

    test_result_print(SYM_2_STR(array_stack_expand_space), is_passed);
    return;
}

static void
test_array_stack_is_full(void)
{
    bool is_passed;
    struct array_stack *ins;
    void *mem;
    int tmp;

    ins = array_stack_create();
    is_passed = true;
    tmp = (int)ins->size;
    mem = &tmp;

    if (false != array_stack_is_full(ins)) {
        is_passed = false;
    }

    while (tmp) {
        array_stack_push(ins, mem);
        tmp--;
    }

    if (true != array_stack_is_full(ins)) {
        is_passed = false;
    }
    array_stack_destroy(&ins);

    test_result_print(SYM_2_STR(array_stack_is_full), is_passed);
    return;
}

stati void
test_array_stack_rest_space(void)

