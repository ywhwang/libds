#ifndef HAVE_TREE_H
#define HAVE_TREE_H

enum ITER_ORDER {
    ORDER_START,
    ORDER_PRE,
    ORDER_IN,
    ORDER_POST,
    ORDER_END,
};

#define LEGAL_ORDER_P(x) ((x) > ORDER_START && (x) < ORDER_END) ? true : false

#ifdef DEBUG
    extern void * malloc_wrap(size_t size);
    extern void free_wrap(void *ptr);
#endif

extern void libds_log_print(enum log_level lvl, const char *msg);
extern void doubly_linked_list_initial(struct doubly_linked_list *);
extern struct doubly_linked_list * doubly_linked_list_join(struct doubly_linked_list *m, struct doubly_linked_list *n);
extern void doubly_linked_list_destroy(struct doubly_linked_list **head);
extern void doubly_linked_list_iterate(struct doubly_linked_list *head, void (*handler)(void *));

/* BINARY SEARCH TREE */
struct binary_search_tree * binary_search_tree_create(void);
struct binary_search_tree * binary_search_tree_node_create(void *val, sint64 nice);
void binary_search_tree_initial(struct binary_search_tree *root);
void binary_search_tree_node_initial(struct binary_search_tree *node, void *val, sint64 nice);
void binary_search_tree_destroy(struct binary_search_tree **root);
struct binary_search_tree * binary_search_tree_node_find(struct binary_search_tree *root, sint64 nice);
struct binary_search_tree * binary_search_tree_node_insert(struct binary_search_tree *root, struct binary_search_tree *node);
struct binary_search_tree * binary_search_tree_node_find_min(struct binary_search_tree *root);
struct binary_search_tree * binary_search_tree_node_find_max(struct binary_search_tree *root);
bool binary_search_tree_node_contain_p(struct binary_search_tree *root, struct binary_search_tree *node);
void binary_search_tree_node_remove(struct binary_search_tree **root, sint64 nice);
sint32 binary_search_tree_height(struct binary_search_tree *root);
void binary_search_tree_iterate(struct binary_search_tree *root, void (*handle)(void *), enum ITER_ORDER order);

static void inline binary_search_tree_node_destroy(struct binary_search_tree *node);
static inline void binary_search_tree_iterate_internal(struct binary_search_tree *root, void (*handle)(void *), enum ITER_ORDER order);
static inline bool binary_search_tree_node_child_doubly_p(struct binary_search_tree *node);
/* END OF BINARY SEARCH TREE */


/* AVL TREE */
struct avl_tree * avl_tree_create(void);
struct avl_tree * avl_tree_node_create(void *val, sint64 nice);
void avl_tree_initial(struct avl_tree *root);
void avl_tree_node_initial(struct avl_tree *node, void *val, sint64 nice);
void avl_tree_destroy(struct avl_tree **root);
struct avl_tree * avl_tree_node_find(struct avl_tree *root, sint64 nice);
struct avl_tree * avl_tree_node_find_min(struct avl_tree *root);
struct avl_tree * avl_tree_node_find_max(struct avl_tree *root);
bool avl_tree_balanced_p(struct avl_tree *root);
bool avl_tree_node_contain_p(struct avl_tree *root, struct avl_tree *node);
void avl_tree_iterate(struct avl_tree *root, void (*handle)(void *), enum ITER_ORDER order);
struct avl_tree * avl_tree_node_insert(struct avl_tree **root, struct avl_tree *node);
void avl_tree_node_remove(struct avl_tree **root, sint64 nice);

static inline void avl_tree_height_update(struct avl_tree *node);
static inline struct avl_tree * avl_tree_single_rotate_left(struct avl_tree *k1);
static inline struct avl_tree * avl_tree_single_rotate_right(struct avl_tree *k1);
static inline struct avl_tree * avl_tree_doubly_rotate_left(struct avl_tree *k1);
static inline struct avl_tree * avl_tree_doubly_rotate_right(struct avl_tree *k1);
static inline bool avl_tree_balanced_internal_p(struct avl_tree *node);
static inline sint32 avl_tree_height_internal(struct avl_tree *node);
static inline bool avl_tree_node_leaf_p(struct avl_tree *node);
static inline bool avl_tree_node_child_doubly_p(struct avl_tree *node);
static inline void avl_tree_node_remove_rotate_left(struct avl_tree **root, struct avl_tree *node);
static inline void avl_tree_node_remove_rotate_right(struct avl_tree **root, struct avl_tree *node);
static inline void avl_tree_node_insert_rotate_left(struct avl_tree **root, struct avl_tree *node);
static inline void avl_tree_node_insert_rotate_right(struct avl_tree **root, struct avl_tree *node);
static inline void avl_tree_node_child_lt_doubly_strip(struct avl_tree **pre, struct avl_tree *node);
static inline sint64 avl_tree_node_child_doubly_strip(struct avl_tree **pre, struct avl_tree *node);
static inline struct avl_tree * avl_tree_node_find_min_parent(struct avl_tree *root);
static inline struct avl_tree * avl_tree_node_find_max_parent(struct avl_tree *root);
static inline sint64 avl_tree_node_child_doubly_strip_from_max(struct avl_tree **pre, struct avl_tree *node);
static inline sint64 avl_tree_node_child_doubly_strip_from_min(struct avl_tree **pre, struct avl_tree *node);
/* END OF AVL TREE */

#endif
