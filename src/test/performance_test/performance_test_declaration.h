#ifndef PERFORMANCE_TEST_DECLARATION_H
#define PERFORMANCE_TEST_DECLARATION_H


static inline double performance_test_reference_variance_calculate(char *name, sint64 period);
static inline sint64 performance_test_time_stamp_period(void);
static inline sint64 performance_test_time_stamp_timeval_unpack(struct timeval *tv);
static inline struct performance_test_reference * performance_test_reference_entry_find_by_name(char *name);
static inline void performance_test_execution_category(const struct test_layer_table *category, struct test_case_filter *filter, struct test_extra_info *info);
static inline void performance_test_execution_implement(const struct test_layer_table *implement, struct test_case_filter *filter, struct test_extra_info *info);
static inline void performance_test_execution_interface(const struct test_layer_table *interface, struct test_case_filter *filter, struct test_extra_info *info);
static inline void performance_test_execution_start(struct test_extra_info *info, char *content);
static inline void performance_test_reference_golden_prepare(const char *fname);
static inline void performance_test_reference_new_writeback(const char *fname);
static inline void performance_test_reference_update(char *raw, struct performance_test_reference *ref);
static inline void performance_test_result_print(char *name, sint64 period);
static inline void performance_test_time_stamp_begin(void);
static inline void performance_test_time_stamp_end(void);
static void performance_test_array_stack_capacity(uint32 count);
static void performance_test_array_stack_cleanup(uint32 count);
static void performance_test_array_stack_create(uint32 count);
static void performance_test_array_stack_destroy(uint32 count);
static void performance_test_array_stack_empty_p(uint32 count);
static void performance_test_array_stack_full_p(uint32 count);
static void performance_test_array_stack_iterate(uint32 count);
static void performance_test_array_stack_pop(uint32 count);
static void performance_test_array_stack_push(uint32 count);
static void performance_test_array_stack_space_expand(uint32 count);
static void performance_test_array_stack_space_rest(uint32 count);
static void performance_test_array_stack_struct_field(uint32 count);
static void performance_test_doubly_linked_list_contains_p(uint32 count);
static void performance_test_doubly_linked_list_create(uint32 count);
static void performance_test_doubly_linked_list_destroy(uint32 count);
static void performance_test_doubly_linked_list_initial(uint32 count);
static void performance_test_doubly_linked_list_iterate(uint32 count);
static void performance_test_doubly_linked_list_length(uint32 count);
static void performance_test_doubly_linked_list_merge(uint32 count);
static void performance_test_doubly_linked_list_node_append(uint32 count);
static void performance_test_doubly_linked_list_node_by_index(uint32 count);
static void performance_test_doubly_linked_list_node_copy(uint32 count);
static void performance_test_doubly_linked_list_node_create(uint32 count);
static void performance_test_doubly_linked_list_node_initial(uint32 count);
static void performance_test_doubly_linked_list_node_insert_after(uint32 count);
static void performance_test_doubly_linked_list_node_insert_before(uint32 count);
static void performance_test_doubly_linked_list_node_remove(uint32 count);
static void performance_test_doubly_linked_list_node_remove_and_destroy(uint32 count);
static void performance_test_doubly_linked_list_serialize(uint32 count);
static void performance_test_doubly_linked_list_struct_field(uint32 count);
static void performance_test_linked_stack_capacity(uint32 count);
static void performance_test_linked_stack_cleanup(uint32 count);
static void performance_test_linked_stack_create(uint32 count);
static void performance_test_linked_stack_destroy(uint32 count);
static void performance_test_linked_stack_empty_p(uint32 count);
static void performance_test_linked_stack_full_p(uint32 count);
static void performance_test_linked_stack_iterate(uint32 count);
static void performance_test_linked_stack_pop(uint32 count);
static void performance_test_linked_stack_push(uint32 count);
static void performance_test_linked_stack_space_expand(uint32 count);
static void performance_test_linked_stack_space_rest(uint32 count);
static void performance_test_linked_stack_struct_field(uint32 count);
static void performance_test_single_linked_list_contains_p(uint32 count);
static void performance_test_single_linked_list_create(uint32 count);
static void performance_test_single_linked_list_destroy(uint32 count);
static void performance_test_single_linked_list_initial(uint32 count);
static void performance_test_single_linked_list_iterate(uint32 count);
static void performance_test_single_linked_list_length(uint32 count);
static void performance_test_single_linked_list_merge(uint32 count);
static void performance_test_single_linked_list_node_append(uint32 count);
static void performance_test_single_linked_list_node_by_index(uint32 count);
static void performance_test_single_linked_list_node_copy(uint32 count);
static void performance_test_single_linked_list_node_create(uint32 count);
static void performance_test_single_linked_list_node_initial(uint32 count);
static void performance_test_single_linked_list_node_insert_after(uint32 count);
static void performance_test_single_linked_list_node_insert_before(uint32 count);
static void performance_test_single_linked_list_node_previous(uint32 count);
static void performance_test_single_linked_list_node_remove(uint32 count);
static void performance_test_single_linked_list_node_remove_and_destroy(uint32 count);
static void performance_test_single_linked_list_serialize(uint32 count);
static void performance_test_single_linked_list_struct_field(uint32 count);
static void performance_test_skip_linked_list_create(uint32 count);
static void performance_test_skip_linked_list_destroy(uint32 count);
static void performance_test_skip_linked_list_initial(uint32 count);
static void performance_test_skip_linked_list_iterate(uint32 count);
static void performance_test_skip_linked_list_key_contains_p(uint32 count);
static void performance_test_skip_linked_list_length(uint32 count);
static void performance_test_skip_linked_list_merge(uint32 count);
static void performance_test_skip_linked_list_node_by_index(uint32 count);
static void performance_test_skip_linked_list_node_create(uint32 count);
static void performance_test_skip_linked_list_node_find_key(uint32 count);
static void performance_test_skip_linked_list_node_initial(uint32 count);
static void performance_test_skip_linked_list_node_insert(uint32 count);
static void performance_test_skip_linked_list_node_remove(uint32 count);
static void performance_test_skip_linked_list_node_remove_and_destroy(uint32 count);
static void performance_test_skip_linked_list_struct_field(uint32 count);

#endif
