#ifndef TREE_DECLARATION_H
#define TREE_DECLARATION_H


bool avl_tree_balanced_p(struct avl_tree *tree);
bool avl_tree_node_contains_p(struct avl_tree *tree, struct avl_tree *node);
bool binary_search_tree_node_contains_p(struct binary_search_tree *tree, struct binary_search_tree *node);
bool splay_tree_node_contains_p(struct splay_tree *tree, struct splay_tree *node);
sint32 binary_search_tree_height(struct binary_search_tree *tree);
sint32 splay_tree_height(struct splay_tree *tree);
sint64 binary_indexed_tree_range_sum(struct binary_indexed_tree *tree, uint32 nmbr_s, uint32 nmbr_e);
sint64 binary_indexed_tree_sum(struct binary_indexed_tree *tree, uint32 number);
static inline bool avl_tree_balanced_internal_p(struct avl_tree *tree);
static inline bool avl_tree_doubly_rotate_left_precondition_p(struct binary_search_tree *k1);
static inline bool avl_tree_doubly_rotate_right_precondition_p(struct binary_search_tree *k1);
static inline bool avl_tree_height_optimize_validity_p(struct avl_tree *tree, sint32 expected);
static inline bool avl_tree_height_sync_with_calculated_p(struct avl_tree *node, sint32 left, sint32 right);
static inline bool avl_tree_left_optimize_validity_p(struct avl_tree *node, void *expected);
static inline bool avl_tree_node_balanced_default_p(struct avl_tree *node);
static inline bool avl_tree_node_balanced_optimize_validity_p(struct avl_tree *node, bool expected);
static inline bool avl_tree_node_balanced_p(struct avl_tree *node);
static inline bool avl_tree_ptr_to_avl_optimize_validity_p(struct binary_search_tree *node, void *expected);
static inline bool avl_tree_right_optimize_validity_p(struct avl_tree *node, void *expected);
static inline bool avl_tree_single_rotate_left_precondition_p(struct binary_search_tree *k1);
static inline bool avl_tree_single_rotate_right_precondition_p(struct binary_search_tree *k1);
static inline bool binary_indexed_tree_number_legal_p(struct binary_indexed_tree *tree, uint32 number);
static inline bool binary_indexed_tree_structure_legal_p(struct binary_indexed_tree *tree);
static inline bool binary_search_tree_child_doubly_p(struct binary_search_tree *node);
static inline bool binary_search_tree_node_child_doubly_p(struct binary_search_tree *node);
static inline bool binary_search_tree_node_contains_p_internal(struct binary_search_tree *tree, struct binary_search_tree *node);
static inline bool binary_search_tree_node_leaf_p(struct binary_search_tree *node);
static inline sint32 avl_tree_height_internal(struct avl_tree *tree);
static inline sint32 avl_tree_height_internal_default(struct avl_tree *node);
static inline sint32 binary_search_tree_height_internal(struct binary_search_tree *tree);
static inline sint64 binary_indexed_tree_sum_internal(struct binary_indexed_tree *tree, uint32 number);
static inline struct avl_tree * avl_tree_left(struct avl_tree *node);
static inline struct avl_tree * avl_tree_ptr_to_avl(struct binary_search_tree *node);
static inline struct avl_tree * avl_tree_right(struct avl_tree *node);
static inline struct binary_search_tree * avl_tree_balance_child_doubly_strip(struct binary_search_tree *node);
static inline struct binary_search_tree * avl_tree_balance_child_doubly_strip_from_max(struct binary_search_tree *node);
static inline struct binary_search_tree * avl_tree_balance_child_doubly_strip_from_min(struct binary_search_tree *node);
static inline struct binary_search_tree * avl_tree_balance_doubly_rotate_left(struct binary_search_tree *k1);
static inline struct binary_search_tree * avl_tree_balance_doubly_rotate_right(struct binary_search_tree *k1);
static inline struct binary_search_tree * avl_tree_balance_single_rotate_left(struct binary_search_tree *k1);
static inline struct binary_search_tree * avl_tree_balance_single_rotate_right(struct binary_search_tree *k1);
static inline struct binary_search_tree * avl_tree_node_insert_internal(struct binary_search_tree **tree, struct binary_search_tree *node);
static inline struct binary_search_tree * avl_tree_node_remove_internal(struct binary_search_tree **tree, sint64 nice);
static inline struct binary_search_tree * binary_search_tree_create_internal(void);
static inline struct binary_search_tree * binary_search_tree_left_child_find_max(struct binary_search_tree *tree);
static inline struct binary_search_tree * binary_search_tree_node_child_doubly_strip(struct binary_search_tree **pre, struct binary_search_tree *node);
static inline struct binary_search_tree * binary_search_tree_node_create_internal(void *val, sint64 nice);
static inline struct binary_search_tree * binary_search_tree_node_find_internal(struct binary_search_tree *tree, sint64 nice);
static inline struct binary_search_tree * binary_search_tree_node_find_max_internal(struct binary_search_tree *tree);
static inline struct binary_search_tree * binary_search_tree_node_find_min_internal(struct binary_search_tree *tree);
static inline struct binary_search_tree * binary_search_tree_node_insert_internal(struct binary_search_tree *tree, struct binary_search_tree *node);
static inline struct binary_search_tree * binary_search_tree_node_remove_internal(struct binary_search_tree **tree, sint64 nice);
static inline struct binary_search_tree * binary_search_tree_right_child_find_min(struct binary_search_tree *tree);
static inline struct binary_search_tree * splay_tree_node_find_internal(struct binary_search_tree **tree, sint64 nice, struct binary_search_tree *root);
static inline struct binary_search_tree * splay_tree_node_find_max_internal(struct binary_search_tree **tree, struct binary_search_tree *root);
static inline struct binary_search_tree * splay_tree_node_find_min_internal(struct binary_search_tree **tree, struct binary_search_tree *root);
static inline struct binary_search_tree * splay_tree_node_insert_internal(struct binary_search_tree **tree, struct binary_search_tree *node, struct binary_search_tree *root);
static inline struct binary_search_tree ** binary_search_tree_node_find_ptr_to_max(struct binary_search_tree **tree);
static inline struct binary_search_tree ** binary_search_tree_node_find_ptr_to_min(struct binary_search_tree **tree);
static inline void avl_tree_balance_insert_rotate_left(struct binary_search_tree **tree, struct binary_search_tree *node);
static inline void avl_tree_balance_insert_rotate_right(struct binary_search_tree **tree, struct binary_search_tree *node);
static inline void avl_tree_balance_remove_rotate_left(struct binary_search_tree **tree, struct binary_search_tree *node);
static inline void avl_tree_balance_remove_rotate_right(struct binary_search_tree **tree, struct binary_search_tree *node);
static inline void avl_tree_destroy_internal(struct avl_tree *tree);
static inline void avl_tree_height_update(struct avl_tree *tree);
static inline void avl_tree_node_destroy(struct avl_tree *node);
static inline void binary_indexed_tree_add_internal(struct binary_indexed_tree *tree, uint32 number, sint64 val);
static inline void binary_search_tree_destroy_internal(struct binary_search_tree **tree);
static inline void binary_search_tree_initial_internal(struct binary_search_tree *tree);
static inline void binary_search_tree_iterate_internal(struct binary_search_tree *tree, void (*handle)(void *), enum ITER_ORDER order);
static inline void binary_search_tree_node_chain_copy(struct collision_chain *tgt, struct collision_chain *node);
static inline void binary_search_tree_node_chain_swap(struct collision_chain *m, struct collision_chain *n);
static inline void binary_search_tree_node_child_clean(struct binary_search_tree *node);
static inline void binary_search_tree_node_child_lt_doubly_strip(struct binary_search_tree **pre, struct binary_search_tree *node);
static inline void binary_search_tree_node_collision_chain_copy(struct collision_chain *tgt, struct collision_chain *node);
static inline void binary_search_tree_node_collision_chain_swap(struct collision_chain *m_node, struct collision_chain *n_node);
static inline void binary_search_tree_node_destroy(struct binary_search_tree *node);
static inline void binary_search_tree_node_initial_internal(struct binary_search_tree *node, void *val, sint64 nice);
static inline void splay_tree_balance_splaying_left(struct binary_search_tree **tree, struct binary_search_tree *root, struct binary_search_tree *target);
static inline void splay_tree_balance_splaying_right(struct binary_search_tree **tree, struct binary_search_tree *root, struct binary_search_tree *target);
static inline void splay_tree_destroy_internal(struct splay_tree *tree);
static inline void splay_tree_node_destroy(struct splay_tree *node);
static void inline splay_tree_balance_doubly_splaying_left(struct binary_search_tree **tree);
static void inline splay_tree_balance_doubly_splaying_right(struct binary_search_tree **tree);
static void inline splay_tree_balance_root_splaying_left(struct binary_search_tree **tree);
static void inline splay_tree_balance_root_splaying_right(struct binary_search_tree **tree);
static void inline splay_tree_balance_single_splaying_left(struct binary_search_tree **tree);
static void inline splay_tree_balance_single_splaying_right(struct binary_search_tree **tree);
struct avl_tree * avl_tree_create(void);
struct avl_tree * avl_tree_node_create(void *val, sint64 nice);
struct avl_tree * avl_tree_node_find(struct avl_tree *tree, sint64 nice);
struct avl_tree * avl_tree_node_find_max(struct avl_tree *tree);
struct avl_tree * avl_tree_node_find_min(struct avl_tree *tree);
struct avl_tree * avl_tree_node_insert(struct avl_tree **tree, struct avl_tree *node);
struct avl_tree * avl_tree_node_remove(struct avl_tree **tree, sint64 nice);
struct avl_tree * avl_tree_ptr_binary_to_avl(struct binary_search_tree *node);
struct binary_indexed_tree * binary_indexed_tree_create(sint64 *data, uint32 size);
struct binary_search_tree  * binary_search_tree_node_find_min(struct binary_search_tree *tree);
struct binary_search_tree * binary_search_tree_create(void);
struct binary_search_tree * binary_search_tree_node_create(void *val, sint64 nice);
struct binary_search_tree * binary_search_tree_node_find(struct binary_search_tree *tree, sint64 nice);
struct binary_search_tree * binary_search_tree_node_find_max(struct binary_search_tree *tree);
struct binary_search_tree * binary_search_tree_node_insert(struct binary_search_tree *tree, struct binary_search_tree *node);
struct binary_search_tree * binary_search_tree_node_remove(struct binary_search_tree **tree, sint64 nice);
struct splay_tree * splay_tree_create(void);
struct splay_tree * splay_tree_node_create(void *val, sint64 nice);
struct splay_tree * splay_tree_node_find(struct splay_tree **tree, sint64 nice);
struct splay_tree * splay_tree_node_find_max(struct splay_tree **tree);
struct splay_tree * splay_tree_node_find_min(struct splay_tree **tree);
struct splay_tree * splay_tree_node_insert(struct splay_tree **tree, struct splay_tree *node);
struct splay_tree * splay_tree_node_remove(struct splay_tree **tree, sint64 nice);
struct splay_tree * splay_tree_node_remove_internal(struct splay_tree **tree, sint64 nice);
struct splay_tree * splay_tree_ptr_container_of(struct binary_search_tree *node);
void avl_tree_destroy(struct avl_tree **tree);
void avl_tree_initial(struct avl_tree *tree);
void avl_tree_iterate(struct avl_tree *tree, void (*handle)(void *), enum ITER_ORDER order);
void avl_tree_node_initial(struct avl_tree *node, void *val, sint64 nice);
void avl_tree_node_remove_and_destroy(struct avl_tree **tree, sint64 nice);
void binary_indexed_tree_add(struct binary_indexed_tree *tree, uint32 number, sint64 val);
void binary_indexed_tree_destroy(struct binary_indexed_tree **tree);
void binary_indexed_tree_sub(struct binary_indexed_tree *tree, uint32 number, sint64 val);
void binary_search_tree_destroy(struct binary_search_tree **tree);
void binary_search_tree_initial(struct binary_search_tree *tree);
void binary_search_tree_iterate(struct binary_search_tree *tree, void (*handle)(void *), enum ITER_ORDER order);
void binary_search_tree_node_initial(struct binary_search_tree *node, void *val, sint64 nice);
void binary_search_tree_node_remove_and_destroy(struct binary_search_tree **tree, sint64 nice);
void splay_tree_destroy(struct splay_tree **tree);
void splay_tree_initial(struct splay_tree *tree);
void splay_tree_iterate(struct splay_tree *tree, void (*handle)(void *), enum ITER_ORDER order);
void splay_tree_node_initial(struct splay_tree *node, void *val, sint64 nice);
void splay_tree_node_remove_and_destroy(struct splay_tree **tree, sint64 nice);

#endif
