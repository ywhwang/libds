#ifndef HAVE_DATA_STRUCTURE_DEFINES_H
#define HAVE_DATA_STRUCTURE_DEFINES_H

/* Macro of struct field set and get.
   We _DO_ NOT use function here for the balance of performance
   and interface clean.
   _Attention_, _DO_ _NOT_ use const parameters for following macro. */
/* DOUBLY LINKED LIST */
#define RESULT_CHECK_doubly_linked_list_node(aim, ex, pass)            \
    do {                                                               \
        RESULT_CHECK_uint32((aim)->sid, (ex)->sid, (pass));            \
        RESULT_CHECK_pointer((aim)->val, (ex)->val, (pass));           \
        RESULT_CHECK_pointer((aim)->next, (ex)->next, (pass));         \
        RESULT_CHECK_pointer((aim)->previous, (ex)->previous, (pass)); \
    } while (false)

#define doubly_linked_list_node_val(node) \
    (assert(node), (node)->val)

#define doubly_linked_list_node_val_set(node, v) \
    (assert(node), (node)->val = (v))

#define doubly_linked_list_node_sid(node) \
    (assert(node), (node)->sid)

#define doubly_linked_list_node_sid_set(node, v) \
    (assert(node), (node)->sid = (v))

#define doubly_linked_list_node_next(node) \
    (assert(node), (node)->next)

#define doubly_linked_list_node_next_set(node, v) \
    (assert(node), (node)->next = (v))

#define doubly_linked_list_node_previous(node) \
    (assert(node), (node)->previous)

#define doubly_linked_list_node_previous_set(node, v) \
    (assert(node), (node)->previous = (v))


/* SINGLE LINKED LIST */
#define RESULT_CHECK_single_linked_list_node(aim, ex, pass)            \
    do {                                                               \
        RESULT_CHECK_uint32((aim)->sid, (ex)->sid, (pass));            \
        RESULT_CHECK_pointer((aim)->val, (ex)->val, (pass));           \
        RESULT_CHECK_pointer((aim)->next, (ex)->next, (pass));         \
    } while (false)

#define single_linked_list_node_val(node) \
    (assert(node), (node)->val)

#define single_linked_list_node_val_set(node, v) \
    (assert(node), (node)->val = (v))

#define single_linked_list_node_sid(node) \
    (assert(node), (node)->sid)

#define single_linked_list_node_sid_set(node, v) \
    (assert(node), (node)->sid = (v))

#define single_linked_list_node_next(node) \
    (assert(node), (node)->next)

#define single_linked_list_node_next_set(node, v) \
    (assert(node), (node)->next = (v))


/* ARRAY STACK */
#define RESULT_CHECK_array_stack(aim, ex, pass)                        \
    do {                                                               \
        RESULT_CHECK_uint32((aim)->sid, (ex)->sid, (pass))             \
        RESULT_CHECK_uint32((aim)->space.dim, (ex)->space.dim, (pass)) \
    } while (false)
    /* We do check sp, bp field here, they should not export to user */

#define array_stack_sid(stack) \
    (assert(stack), (stack)->sid)

#define array_stack_sid_set(stack, v) \
    (assert(stack), (stack)->sid = (v))

#define array_stack_space_dim(stack) \
    (assert(stack), (stack)->space.dim)

#define array_stack_space_dim_set(stack, v) \
    (assert(stack), (stack)->space.dim = (v))

/* LINKED STACK */
#define linked_stack_sid(stack) \
    (assert(stack), (stack)->sid)

#define linked_stack_sid_set(stack, v) \
    (assert(stack), (stack)->sid = (v))

/* ARRAY QUEUE */
#define array_queue_sid(queue) \
    (assert(queue), (queue)->sid)

#define array_queue_sid_set(queue, v) \
    (assert(queue), (queue)->sid = (v))

#define array_queue_rest(queue) \
    (assert(queue), (queue)->space.rest)

#define array_queue_dim(queue) \
    (assert(queue), (queue)->space.dim)

/* STACKED QUEUE */
#define stacked_queue_sid(queue) \
    (assert(queue), (queue)->sid)

#define stacked_queue_sid_set(queue, v) \
    (assert(queue), (queue)->sid = (v))

#define stacked_queue_dim(queue) \
    (assert(queue), (queue)->dim)

/* DOUBLY END QUEUE */
#define doubly_end_queue_sid(queue) \
    (assert(queue), (queue)->sid)

#define doubly_end_queue_sid_set(queue, v) \
    (assert(queue), (queue)->sid = (v))

/* BINARY SEARCH TREE */
#define binary_search_tree_node_nice(tree) \
    (assert(tree), (tree)->chain.nice)

#define binary_search_tree_node_nice_set(tree, v) \
    (assert(tree), (tree)->chain.nice = (v))

#define binary_search_tree_child_left(tree) \
    (assert(tree), (tree)->left)

#define binary_search_tree_child_left_set(tree, v) \
    (assert(tree), (tree)->left = (v))

#define binary_search_tree_child_right(tree) \
    (assert(tree), (tree)->right)

#define binary_search_tree_child_right_set(tree, v) \
    (assert(tree), (tree)->right = (v))

#define binary_search_tree_node_link(tree) \
    (assert(tree), ((tree)->chain).link)

/* AVL TREE */
#define avl_tree_node_nice(tree) \
    (assert(tree), (tree)->b_node.chain.nice)

#define avl_tree_node_nice_set(tree, v) \
    (assert(tree), (tree)->b_node.chain.nice = (v))

#define avl_tree_child_left(tree) \
    (assert(tree), (tree)->b_node.avl_left)

#define avl_tree_child_left_set(tree, v) \
    (assert(tree), (tree)->b_node.avl_left = (v))

#define avl_tree_child_right(tree) \
    (assert(tree), (tree)->b_node.avl_right)

#define avl_tree_child_right_set(tree, v) \
    (assert(tree), (tree)->b_node.avl_right = (v))

#define avl_tree_node_link(tree) \
    (assert(tree), (tree)->b_node.chain.link)

#define avl_tree_height(tree) \
    (assert(tree), (tree)->b_node.height)

#define avl_tree_height_set(tree, v) \
    (assert(tree), (tree)->b_node.height = (v))

/* NULL tree pointer is vaild here */
#define avl_tree_ptr_to_bin(tree) \
    ((struct binary_search_tree *)(tree))

#define avl_tree_ptr_to_avl(tree) \
    ((struct avl_tree *)(tree))

/* SPLAY TREE */
#define splay_tree_node_nice(tree) \
    (assert(tree), (tree)->b_node.chain.nice)

#define splay_tree_node_nice_set(tree, v) \
    (assert(tree), (tree)->b_node.chain.nice = (v))

#define splay_tree_child_left(tree) \
    (assert(tree), (tree)->b_node.splay_left)

#define splay_tree_child_left_set(tree, v) \
    (assert(tree), (tree)->b_node.splay_left = (v))

#define splay_tree_child_right(tree) \
    (assert(tree), (tree)->b_node.splay_right)

#define splay_tree_child_right_set(tree, v) \
    (assert(tree), (tree)->b_node.splay_right = (v))

#define splay_tree_node_link(tree) \
    (assert(tree), (tree)->b_node.chain.link)

/* NULL tree pointer is vaild here */
#define splay_tree_ptr_to_bin(tree) \
    ((struct binary_search_tree *)(tree))

#define splay_tree_ptr_to_splay(tree) \
    ((struct splay_tree *)(tree))

/* HASHING TABLE */
#define hashing_table_size(hash) \
    (assert(hash), (hash)->size)
#define hashing_table_load_factor(hash) \
    (assert(hash), (hash)->load_factor)
#define hashing_table_load_factor_set(hash, factor) \
    (assert(hash), (hash)->load_factor = (factor))

/* SEPARATE CHAIN HASHING */
#define separate_chain_hash_size(hash) \
    (assert(hash), hashing_table_size((hash)->table))
#define separate_chain_hash_load_factor(hash) \
    (assert(hash), hashing_table_load_factor((hash)->table))
#define separate_chain_hash_load_factor_set(hash, factor) \
    (assert(hash), hashing_table_load_factor_set((hash)->table, factor))

#endif
