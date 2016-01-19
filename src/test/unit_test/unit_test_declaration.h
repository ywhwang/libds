#ifndef UNIT_TEST_DECLARATION_H
#define UNIT_TEST_DECLARATION_H


static inline bool utest_doubly_linked_list_node_legal_p(struct doubly_linked_list *node);
static inline bool utest_maximal_heap_ordered_p(struct maximal_heap *heap);
static inline bool utest_minimal_heap_ordered_p(struct minimal_heap *heap);
static inline bool utest_single_linked_list_node_legal_p(struct single_linked_list *node);
static inline bool utest_skip_linked_list_node_legal_p(struct skip_linked_list *node);
static inline void unit_test_execution_category(const struct test_layer_table *category, struct test_case_filter *filter);
static inline void unit_test_execution_implement(const struct test_layer_table *implement, struct test_case_filter *filter);
static inline void unit_test_execution_interface(const struct test_layer_table *interface, struct test_case_filter *filter);
static inline void unit_test_execution_start(struct test_extra_info *entry, char *content);
static inline void unit_test_result_print(char *name, bool passed);
static inline void utest_maximal_heap_decrease_nice(void);
static inline void utest_maximal_heap_increase_nice(void);
static inline void utest_minimal_heap_decrease_nice(void);
static inline void utest_minimal_heap_increase_nice(void);
static void unit_test_array_queue_capacity(void);
static void unit_test_array_queue_cleanup(void);
static void unit_test_array_queue_create(void);
static void unit_test_array_queue_destroy(void);
static void unit_test_array_queue_empty_p(void);
static void unit_test_array_queue_enter(void);
static void unit_test_array_queue_full_p(void);
static void unit_test_array_queue_iterate(void);
static void unit_test_array_queue_leave(void);
static void unit_test_array_queue_space_expand(void);
static void unit_test_array_queue_space_rest(void);
static void unit_test_array_queue_struct_field(void);
static void unit_test_array_stack_capacity(void);
static void unit_test_array_stack_cleanup(void);
static void unit_test_array_stack_create(void);
static void unit_test_array_stack_destroy(void);
static void unit_test_array_stack_empty_p(void);
static void unit_test_array_stack_full_p(void);
static void unit_test_array_stack_iterate(void);
static void unit_test_array_stack_pop(void);
static void unit_test_array_stack_push(void);
static void unit_test_array_stack_space_expand(void);
static void unit_test_array_stack_space_rest(void);
static void unit_test_array_stack_struct_field(void);
static void unit_test_avl_tree_balanced_p(void);
static void unit_test_avl_tree_create(void);
static void unit_test_avl_tree_destroy(void);
static void unit_test_avl_tree_initial(void);
static void unit_test_avl_tree_iterate(void);
static void unit_test_avl_tree_node_contains_p(void);
static void unit_test_avl_tree_node_create(void);
static void unit_test_avl_tree_node_find(void);
static void unit_test_avl_tree_node_find_max(void);
static void unit_test_avl_tree_node_find_min(void);
static void unit_test_avl_tree_node_initial(void);
static void unit_test_avl_tree_node_insert(void);
static void unit_test_avl_tree_node_remove(void);
static void unit_test_avl_tree_node_remove_and_destroy(void);
static void unit_test_avl_tree_struct_field(void);
static void unit_test_binary_search_tree_create(void);
static void unit_test_binary_search_tree_destroy(void);
static void unit_test_binary_search_tree_height(void);
static void unit_test_binary_search_tree_initial(void);
static void unit_test_binary_search_tree_iterate(void);
static void unit_test_binary_search_tree_node_contains_p(void);
static void unit_test_binary_search_tree_node_create(void);
static void unit_test_binary_search_tree_node_find(void);
static void unit_test_binary_search_tree_node_find_max(void);
static void unit_test_binary_search_tree_node_find_min(void);
static void unit_test_binary_search_tree_node_initial(void);
static void unit_test_binary_search_tree_node_insert(void);
static void unit_test_binary_search_tree_node_remove(void);
static void unit_test_binary_search_tree_node_remove_and_destroy(void);
static void unit_test_binary_search_tree_struct_field(void);
static void unit_test_doubly_end_queue_cleanup(void);
static void unit_test_doubly_end_queue_create(void);
static void unit_test_doubly_end_queue_destroy(void);
static void unit_test_doubly_end_queue_empty_p(void);
static void unit_test_doubly_end_queue_head_enter(void);
static void unit_test_doubly_end_queue_head_leave(void);
static void unit_test_doubly_end_queue_iterate(void);
static void unit_test_doubly_end_queue_length(void);
static void unit_test_doubly_end_queue_struct_field(void);
static void unit_test_doubly_end_queue_tail_enter(void);
static void unit_test_doubly_end_queue_tail_leave(void);
static void unit_test_leftist_heap_create(void);
static void unit_test_leftist_heap_destroy(void);
static void unit_test_leftist_heap_get_min(void);
static void unit_test_leftist_heap_insert(void);
static void unit_test_leftist_heap_merge(void);
static void unit_test_leftist_heap_node_create(void);
static void unit_test_leftist_heap_remove_min(void);
static void unit_test_leftist_heap_remove_min_and_destroy(void);
static void unit_test_leftist_heap_struct_field(void);
static void unit_test_linked_stack_capacity(void);
static void unit_test_linked_stack_cleanup(void);
static void unit_test_linked_stack_create(void);
static void unit_test_linked_stack_destroy(void);
static void unit_test_linked_stack_empty_p(void);
static void unit_test_linked_stack_full_p(void);
static void unit_test_linked_stack_iterate(void);
static void unit_test_linked_stack_pop(void);
static void unit_test_linked_stack_push(void);
static void unit_test_linked_stack_space_expand(void);
static void unit_test_linked_stack_space_rest(void);
static void unit_test_linked_stack_struct_field(void);
static void unit_test_open_addressing_hash_create(void);
static void unit_test_open_addressing_hash_destroy(void);
static void unit_test_open_addressing_hash_find(void);
static void unit_test_open_addressing_hash_insert(void);
static void unit_test_open_addressing_hash_load_factor_calculate(void);
static void unit_test_open_addressing_hash_rehashing(void);
static void unit_test_open_addressing_hash_remove(void);
static void unit_test_open_addressing_hash_struct_field(void);
static void unit_test_separate_chain_hash_create(void);
static void unit_test_separate_chain_hash_destroy(void);
static void unit_test_separate_chain_hash_find(void);
static void unit_test_separate_chain_hash_insert(void);
static void unit_test_separate_chain_hash_load_factor_calculate(void);
static void unit_test_separate_chain_hash_rehashing(void);
static void unit_test_separate_chain_hash_remove(void);
static void unit_test_separate_chain_hash_struct_field(void);
static void unit_test_splay_tree_create(void);
static void unit_test_splay_tree_destroy(void);
static void unit_test_splay_tree_height(void);
static void unit_test_splay_tree_initial(void);
static void unit_test_splay_tree_iterate(void);
static void unit_test_splay_tree_node_contains_p(void);
static void unit_test_splay_tree_node_create(void);
static void unit_test_splay_tree_node_find(void);
static void unit_test_splay_tree_node_find_max(void);
static void unit_test_splay_tree_node_find_min(void);
static void unit_test_splay_tree_node_initial(void);
static void unit_test_splay_tree_node_insert(void);
static void unit_test_splay_tree_node_remove(void);
static void unit_test_splay_tree_node_remove_and_destroy(void);
static void unit_test_splay_tree_struct_field(void);
static void unit_test_stacked_queue_capacity(void);
static void unit_test_stacked_queue_cleanup(void);
static void unit_test_stacked_queue_create(void);
static void unit_test_stacked_queue_destroy(void);
static void unit_test_stacked_queue_empty_p(void);
static void unit_test_stacked_queue_enter(void);
static void unit_test_stacked_queue_full_p(void);
static void unit_test_stacked_queue_iterate(void);
static void unit_test_stacked_queue_leave(void);
static void unit_test_stacked_queue_space_expand(void);
static void unit_test_stacked_queue_space_rest(void);
static void unit_test_stacked_queue_struct_field(void);
static void utest_skip_linked_list_find_key(void);
static void utest_skip_linked_list_insert(void);
static void utest_skip_linked_list_key_contains_p(void);
static void utest_skip_linked_list_merge(void);
static void utest_skip_linked_list_node_create(void);
static void utest_skip_linked_list_remove(void);
static void utest_skip_linked_list_remove_and_destroy(void);

#endif
