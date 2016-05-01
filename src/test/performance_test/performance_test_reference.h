#ifndef HAVE_TEST_PERFORMANCE_SET_H
#define HAVE_TEST_PERFORMANCE_SET_H

static struct performance_test_reference performance_reference[] = {
    {"single_linked_list_initial",                       0x0u, 0x0u},
    {"single_linked_list_create",                        0x0u, 0x0u},
    {"single_linked_list_node_create",                   0x0u, 0x0u},
    {"single_linked_list_node_copy",                     0x0u, 0x0u},
    {"single_linked_list_previous",                      0x0u, 0x0u},
    {"single_linked_list_insert_before",                 0x0u, 0x0u},
    {"single_linked_list_insert_after",                  0x0u, 0x0u},
    {"single_linked_list_insert_ptr_before",             0x0u, 0x0u},
    {"single_linked_list_insert_ptr_after",              0x0u, 0x0u},
    {"single_linked_list_node_by_index",                 0x0u, 0x0u},
    {"single_linked_list_remove",                        0x0u, 0x0u},
    {"single_linked_list_remove_and_destroy",            0x0u, 0x0u},
    {"single_linked_list_contains_p",                    0x0u, 0x0u},
    {"single_linked_list_iterate",                       0x0u, 0x0u},
    {"single_linked_list_destroy",                       0x0u, 0x0u},
    {"single_linked_list_length",                        0x0u, 0x0u},
    {"single_linked_list_merge",                         0x0u, 0x0u},

    {"doubly_linked_list_initial",                       0x0u, 0x0u},
    {"doubly_linked_list_create",                        0x0u, 0x0u},
    {"doubly_linked_list_node_create",                   0x0u, 0x0u},
    {"doubly_linked_list_node_copy",                     0x0u, 0x0u},
    {"doubly_linked_list_insert_before",                 0x0u, 0x0u},
    {"doubly_linked_list_insert_after",                  0x0u, 0x0u},
    {"doubly_linked_list_insert_ptr_before",             0x0u, 0x0u},
    {"doubly_linked_list_insert_ptr_after",              0x0u, 0x0u},
    {"doubly_linked_list_node_by_index",                 0x0u, 0x0u},
    {"doubly_linked_list_remove",                        0x0u, 0x0u},
    {"doubly_linked_list_remove_and_destroy",            0x0u, 0x0u},
    {"doubly_linked_list_contains_p",                    0x0u, 0x0u},
    {"doubly_linked_list_iterate",                       0x0u, 0x0u},
    {"doubly_linked_list_destroy",                       0x0u, 0x0u},
    {"doubly_linked_list_length",                        0x0u, 0x0u},
    {"doubly_linked_list_merge",                         0x0u, 0x0u},

    {"skip_linked_list_create",                          0x0u, 0x0u},
    {"skip_linked_list_initial",                         0x0u, 0x0u},
    {"skip_linked_list_node_create",                     0x0u, 0x0u},
    {"skip_linked_list_destroy",                         0x0u, 0x0u},
    {"skip_linked_list_length",                          0x0u, 0x0u},
    {"skip_linked_list_key_contains_p",                  0x0u, 0x0u},
    {"skip_linked_list_insert",                          0x0u, 0x0u},
    {"skip_linked_list_find_key",                        0x0u, 0x0u},
    {"skip_linked_list_node_by_index",                   0x0u, 0x0u},
    {"skip_linked_list_remove",                          0x0u, 0x0u},
    {"skip_linked_list_remove_and_destroy",              0x0u, 0x0u},
    {"skip_linked_list_iterate",                         0x0u, 0x0u},
    {"skip_linked_list_merge",                           0x0u, 0x0u},

    {"array_stack_create",                               0x0u, 0x0u},
    {"array_stack_destroy",                              0x0u, 0x0u},
    {"array_stack_resize",                               0x0u, 0x0u},
    {"array_stack_rest",                                 0x0u, 0x0u},
    {"array_stack_full_p",                               0x0u, 0x0u},
    {"array_stack_capacity",                             0x0u, 0x0u},
    {"array_stack_push",                                 0x0u, 0x0u},
    {"array_stack_pop",                                  0x0u, 0x0u},
    {"array_stack_empty_p",                              0x0u, 0x0u},
    {"array_stack_cleanup",                              0x0u, 0x0u},
    {"array_stack_iterate",                              0x0u, 0x0u},

    {"linked_stack_create",                              0x0u, 0x0u},
    {"linked_stack_destroy",                             0x0u, 0x0u},
    {"linked_stack_resize",                              0x0u, 0x0u},
    {"linked_stack_rest",                                0x0u, 0x0u},
    {"linked_stack_full_p",                              0x0u, 0x0u},
    {"linked_stack_capacity",                            0x0u, 0x0u},
    {"linked_stack_push",                                0x0u, 0x0u},
    {"linked_stack_pop",                                 0x0u, 0x0u},
    {"linked_stack_empty_p",                             0x0u, 0x0u},
    {"linked_stack_cleanup",                             0x0u, 0x0u},
    {"linked_stack_iterate",                             0x0u, 0x0u},

    {"array_queue_struct_field",                         0x0u, 0x0u},
    {"array_queue_create",                               0x0u, 0x0u},
    {"array_queue_destroy",                              0x0u, 0x0u},
    {"array_queue_space_expand",                         0x0u, 0x0u},
    {"array_queue_space_rest",                           0x0u, 0x0u},
    {"array_queue_full_p",                               0x0u, 0x0u},
    {"array_queue_capacity",                             0x0u, 0x0u},
    {"array_queue_enter",                                0x0u, 0x0u},
    {"array_queue_leave",                                0x0u, 0x0u},
    {"array_queue_empty_p",                              0x0u, 0x0u},
    {"array_queue_cleanup",                              0x0u, 0x0u},
    {"array_queue_iterate",                              0x0u, 0x0u},

    {"stacked_queue_struct_field",                       0x0u, 0x0u},
    {"stacked_queue_create",                             0x0u, 0x0u},
    {"stacked_queue_destroy",                            0x0u, 0x0u},
    {"stacked_queue_space_expand",                       0x0u, 0x0u},
    {"stacked_queue_space_rest",                         0x0u, 0x0u},
    {"stacked_queue_full_p",                             0x0u, 0x0u},
    {"stacked_queue_capacity",                           0x0u, 0x0u},
    {"stacked_queue_enter",                              0x0u, 0x0u},
    {"stacked_queue_leave",                              0x0u, 0x0u},
    {"stacked_queue_empty_p",                            0x0u, 0x0u},
    {"stacked_queue_cleanup",                            0x0u, 0x0u},
    {"stacked_queue_iterate",                            0x0u, 0x0u},

    {"doubly_end_queue_struct_field",                    0x0u, 0x0u},
    {"doubly_end_queue_create",                          0x0u, 0x0u},
    {"doubly_end_queue_destroy",                         0x0u, 0x0u},
    {"doubly_end_queue_length",                          0x0u, 0x0u},
    {"doubly_end_queue_empty_p",                         0x0u, 0x0u},
    {"doubly_end_queue_head_enter",                      0x0u, 0x0u},
    {"doubly_end_queue_head_leave",                      0x0u, 0x0u},
    {"doubly_end_queue_tail_enter",                      0x0u, 0x0u},
    {"doubly_end_queue_tail_leave",                      0x0u, 0x0u},
    {"doubly_end_queue_cleanup",                         0x0u, 0x0u},
    {"doubly_end_queue_iterate",                         0x0u, 0x0u},

    {"binary_search_tree_struct_field",                  0x0u, 0x0u},
    {"binary_search_tree_create",                        0x0u, 0x0u},
    {"binary_search_tree_node_create",                   0x0u, 0x0u},
    {"binary_search_tree_initial",                       0x0u, 0x0u},
    {"binary_search_tree_node_initial",                  0x0u, 0x0u},
    {"binary_search_tree_destroy",                       0x0u, 0x0u},
    {"binary_search_tree_node_find",                     0x0u, 0x0u},
    {"binary_search_tree_node_find_min",                 0x0u, 0x0u},
    {"binary_search_tree_node_find_max",                 0x0u, 0x0u},
    {"binary_search_tree_height",                        0x0u, 0x0u},
    {"binary_search_tree_node_contains_p",               0x0u, 0x0u},
    {"binary_search_tree_node_insert",                   0x0u, 0x0u},
    {"binary_search_tree_node_remove",                   0x0u, 0x0u},
    {"binary_search_tree_node_remove_and_destroy",       0x0u, 0x0u},
    {"binary_search_tree_iterate",                       0x0u, 0x0u},

    {"avl_tree_struct_field",                            0x0u, 0x0u},
    {"avl_tree_create",                                  0x0u, 0x0u},
    {"avl_tree_node_create",                             0x0u, 0x0u},
    {"avl_tree_initial",                                 0x0u, 0x0u},
    {"avl_tree_node_initial",                            0x0u, 0x0u},
    {"avl_tree_destroy",                                 0x0u, 0x0u},
    {"avl_tree_node_find",                               0x0u, 0x0u},
    {"avl_tree_node_find_min",                           0x0u, 0x0u},
    {"avl_tree_node_find_max",                           0x0u, 0x0u},
    {"avl_tree_node_contains_p",                         0x0u, 0x0u},
    {"avl_tree_balanced_p",                              0x0u, 0x0u},
    {"avl_tree_node_insert",                             0x0u, 0x0u},
    {"avl_tree_node_remove",                             0x0u, 0x0u},
    {"avl_tree_node_remove_and_destroy",                 0x0u, 0x0u},
    {"avl_tree_iterate",                                 0x0u, 0x0u},

    {"splay_tree_struct_field",                          0x0u, 0x0u},
    {"splay_tree_create",                                0x0u, 0x0u},
    {"splay_tree_node_create",                           0x0u, 0x0u},
    {"splay_tree_initial",                               0x0u, 0x0u},
    {"splay_tree_node_initial",                          0x0u, 0x0u},
    {"splay_tree_destroy",                               0x0u, 0x0u},
    {"splay_tree_node_contains_p",                       0x0u, 0x0u},
    {"splay_tree_node_find",                             0x0u, 0x0u},
    {"splay_tree_node_find_min",                         0x0u, 0x0u},
    {"splay_tree_node_find_max",                         0x0u, 0x0u},
    {"splay_tree_height",                                0x0u, 0x0u},
    {"splay_tree_node_insert",                           0x0u, 0x0u},
    {"splay_tree_node_remove",                           0x0u, 0x0u},
    {"splay_tree_node_remove_and_destroy",               0x0u, 0x0u},
    {"splay_tree_iterate",                               0x0u, 0x0u},

    {"binary_indexed_tree_create",                       0x0u, 0x0u},
    {"binary_indexed_tree_destroy",                      0x0u, 0x0u},
    {"binary_indexed_tree_add",                          0x0u, 0x0u},
    {"binary_indexed_tree_sub",                          0x0u, 0x0u},
    {"binary_indexed_tree_sum",                          0x0u, 0x0u},
    {"binary_indexed_tree_range_sum",                    0x0u, 0x0u},

    {"separate_chain_hash_struct_field",                 0x0u, 0x0u},
    {"separate_chain_hash_create",                       0x0u, 0x0u},
    {"separate_chain_hash_destroy",                      0x0u, 0x0u},
    {"separate_chain_hash_load_factor_calculate",        0x0u, 0x0u},
    {"separate_chain_hash_insert",                       0x0u, 0x0u},
    {"separate_chain_hash_remove",                       0x0u, 0x0u},
    {"separate_chain_hash_find",                         0x0u, 0x0u},
    {"separate_chain_hash_rehashing",                    0x0u, 0x0u},

    {"open_addressing_hash_struct_field",                0x0u, 0x0u},
    {"open_addressing_hash_create",                      0x0u, 0x0u},
    {"open_addressing_hash_destroy",                     0x0u, 0x0u},
    {"open_addressing_hash_load_factor_calculate",       0x0u, 0x0u},
    {"open_addressing_hash_insert",                      0x0u, 0x0u},
    {"open_addressing_hash_remove",                      0x0u, 0x0u},
    {"open_addressing_hash_find",                        0x0u, 0x0u},
    {"open_addressing_hash_rehashing",                   0x0u, 0x0u},

    {"minimal_heap_create",                              0x0u, 0x0u},
    {"minimal_heap_destroy",                             0x0u, 0x0u},
    {"minimal_heap_empty_p",                             0x0u, 0x0u},
    {"minimal_heap_full_p",                              0x0u, 0x0u},
    {"minimal_heap_cleanup",                             0x0u, 0x0u},
    {"minimal_heap_get_min",                             0x0u, 0x0u},
    {"minimal_heap_insert",                              0x0u, 0x0u},
    {"minimal_heap_remove_min",                          0x0u, 0x0u},
    {"minimal_heap_remove",                              0x0u, 0x0u},
    {"minimal_heap_decrease_nice",                       0x0u, 0x0u},
    {"minimal_heap_increase_nice",                       0x0u, 0x0u},
    {"minimal_heap_build",                               0x0u, 0x0u},

    {"maximal_heap_create",                              0x0u, 0x0u},
    {"maximal_heap_destroy",                             0x0u, 0x0u},
    {"maximal_heap_empty_p",                             0x0u, 0x0u},
    {"maximal_heap_full_p",                              0x0u, 0x0u},
    {"maximal_heap_cleanup",                             0x0u, 0x0u},
    {"maximal_heap_get_max",                             0x0u, 0x0u},
    {"maximal_heap_insert",                              0x0u, 0x0u},
    {"maximal_heap_remove_max",                          0x0u, 0x0u},
    {"maximal_heap_remove",                              0x0u, 0x0u},
    {"maximal_heap_decrease_nice",                       0x0u, 0x0u},
    {"maximal_heap_increase_nice",                       0x0u, 0x0u},
    {"maximal_heap_build",                               0x0u, 0x0u},

    {"min_max_heap_create",                              0x0u, 0x0u},
    {"min_max_heap_destroy",                             0x0u, 0x0u},
    {"min_max_heap_empty_p",                             0x0u, 0x0u},
    {"min_max_heap_full_p",                              0x0u, 0x0u},
    {"min_max_heap_cleanup",                             0x0u, 0x0u},
    {"min_max_heap_get_min",                             0x0u, 0x0u},
    {"min_max_heap_get_max",                             0x0u, 0x0u},
    {"min_max_heap_insert",                              0x0u, 0x0u},
    {"min_max_heap_depth",                               0x0u, 0x0u},
    {"min_max_heap_remove_min",                          0x0u, 0x0u},
    {"min_max_heap_remove_max",                          0x0u, 0x0u},
    {"min_max_heap_remove",                              0x0u, 0x0u},
    {"min_max_heap_decrease_nice",                       0x0u, 0x0u},
    {"min_max_heap_increase_nice",                       0x0u, 0x0u},

    {"leftist_heap_struct_field",                        0x0u, 0x0u},
    {"leftist_heap_create",                              0x0u, 0x0u},
    {"leftist_heap_node_create",                         0x0u, 0x0u},
    {"leftist_heap_destroy",                             0x0u, 0x0u},
    {"leftist_heap_get_min",                             0x0u, 0x0u},
    {"leftist_heap_insert",                              0x0u, 0x0u},
    {"leftist_heap_merge",                               0x0u, 0x0u},
    {"leftist_heap_remove_min",                          0x0u, 0x0u},
    {"leftist_heap_remove_min_and_destroy",              0x0u, 0x0u},

    {"insertion_sort",                                   0x0u, 0x0u},
    {"shell_sort",                                       0x0u, 0x0u},
    {"heap_sort",                                        0x0u, 0x0u},
    {"merge_sort",                                       0x0u, 0x0u},
    {NULL,                                               0x0u, 0x0u},
};

#endif
