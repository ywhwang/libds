#ifndef HAVE_LINKED_LIST_H
#define HAVE_LINKED_LIST_H

#define SKIP_LIST_BOTTOM_IDX  0
#define SKIP_LIST_MAX_LVL     LEVEL_LIMIT
#define SKIP_LIST_MAX_LVL_IDX SKIP_LIST_MAX_LVL - 1

#if defined DEBUG
static inline bool skip_linked_list_ordering_p(struct skip_linked_list *list);

#endif

extern uint32 random_uint32_with_limit(uint32 lmt);

/* doubly linked list, Circular. */
struct doubly_linked_list * doubly_linked_list_create(void);
struct doubly_linked_list * doubly_linked_list_node_create(void *val, uint32 sid);
void doubly_linked_list_node_initial(struct doubly_linked_list *head, void *val, uint32 sid);
void doubly_linked_list_initial(struct doubly_linked_list *);
struct doubly_linked_list * doubly_linked_list_generate(uint32 *sid, uint32 size);
struct doubly_linked_list * doubly_linked_list_node_copy(struct doubly_linked_list *node);
void doubly_linked_list_node_append(struct doubly_linked_list *node, uint32 sid);
void doubly_linked_list_node_insert_after(struct doubly_linked_list *cur, struct doubly_linked_list *node);
void doubly_linked_list_node_insert_before(struct doubly_linked_list *cur, struct doubly_linked_list *node);
void doubly_linked_list_destroy(struct doubly_linked_list **head);
uint32 doubly_linked_list_length(struct doubly_linked_list *head);
struct doubly_linked_list * doubly_linked_list_node_by_index(struct doubly_linked_list *head, uint32 index);
void doubly_linked_list_node_exchange(struct doubly_linked_list *fir, struct doubly_linked_list *sec);
bool doubly_linked_list_contains_p(struct doubly_linked_list *tar, struct doubly_linked_list *node);
void doubly_linked_list_serialize(struct doubly_linked_list *head);
struct doubly_linked_list * doubly_linked_list_node_remove(struct doubly_linked_list **node);
struct doubly_linked_list * doubly_linked_list_node_lazy_remove(struct doubly_linked_list *node);
void doubly_linked_list_iterate(struct doubly_linked_list *head, void (*handler)(void *));
struct doubly_linked_list * doubly_linked_list_merge(struct doubly_linked_list *m, struct doubly_linked_list *n);
/* END of doubly linked list, Circular. */


/* single linked list, Circular. */
static inline void single_linked_list_node_insert_after_internal(struct single_linked_list *cur, struct single_linked_list *node);
static inline void single_linked_list_node_insert_before_internal(struct single_linked_list *cur, struct single_linked_list *node);
static inline bool single_linked_list_contains_p_internal(struct single_linked_list *list, struct single_linked_list *node);
static inline uint32 single_linked_list_length_internal(struct single_linked_list *list);
static inline struct single_linked_list * single_linked_list_node_previous_internal(struct single_linked_list *node);
static inline struct single_linked_list * single_linked_list_node_lazy_remove_internal(struct single_linked_list *node);

void single_linked_list_initial(struct single_linked_list *head);
void single_linked_list_node_initial(struct single_linked_list *head, void *val, uint32 sid);
void single_linked_list_node_append(struct single_linked_list *node, uint32 value);
void single_linked_list_node_insert_after(struct single_linked_list *cur, struct single_linked_list *node);
void single_linked_list_node_insert_before(struct single_linked_list *cur, struct single_linked_list *node);
void single_linked_list_destroy(struct single_linked_list **head);
void single_linked_list_node_exchange(struct single_linked_list *fir, struct single_linked_list *sec);
void single_linked_list_serialize(struct single_linked_list *head);
void single_linked_list_iterate(struct single_linked_list *head, void (*handler)(void *));
bool single_linked_list_contains_p(struct single_linked_list *tar, struct single_linked_list *node);
uint32 single_linked_list_length(struct single_linked_list *head);
struct single_linked_list * single_linked_list_create(void);
struct single_linked_list * single_linked_list_node_create(void *val, uint32 sid);
struct single_linked_list * single_linked_list_node_copy(struct single_linked_list *node);
struct single_linked_list * single_linked_list_node_previous(struct single_linked_list *node);
struct single_linked_list * single_linked_list_node_by_index(struct single_linked_list *head, uint32 index);
struct single_linked_list * single_linked_list_node_remove(struct single_linked_list **node);
struct single_linked_list * single_linked_list_node_lazy_remove(struct single_linked_list *node);
struct single_linked_list * single_linked_list_merge(struct single_linked_list *m, struct single_linked_list *n);
/* END of single linked list, Circular. */


/* skip linked list, _NOT_ Circular. */
void skip_linked_list_initial(struct skip_linked_list *list);
void skip_linked_list_node_initial(struct skip_linked_list *list, void *val, sint32 key);
void skip_linked_list_destroy(struct skip_linked_list **list);
void skip_linked_list_node_remove_and_destroy(struct skip_linked_list **list, sint32 key);
void skip_linked_list_iterate(struct skip_linked_list *list, void (*handler)(void *));
bool skip_linked_list_contains_p(struct skip_linked_list *list, struct skip_linked_list *tgt);
uint32 skip_linked_list_length(struct skip_linked_list *list);
struct skip_linked_list * skip_linked_list_create(void);
struct skip_linked_list * skip_linked_list_node_create(void *val, sint32 key);
struct skip_linked_list * skip_linked_list_node_find_key(struct skip_linked_list *list, sint32 key);
struct skip_linked_list * skip_linked_list_node_insert(struct skip_linked_list **list, struct skip_linked_list *tgt);
struct skip_linked_list * skip_linked_list_node_by_index(struct skip_linked_list *list, uint32 index);
struct skip_linked_list * skip_linked_list_node_remove(struct skip_linked_list **list, sint32 key);
struct skip_linked_list * skip_linked_list_merge(struct skip_linked_list *m, struct skip_linked_list *n);

static inline bool skip_linked_list_contains_p_internal(struct skip_linked_list *list, struct skip_linked_list *tgt);
static inline void skip_linked_list_insert_update_with_lvl(struct skip_linked_list *tgt, struct skip_linked_list **prev_list, uint32 lvl);
static inline void skip_linked_list_node_clean(struct skip_linked_list *list);
static inline uint32 skip_linked_list_node_level(struct skip_linked_list *list);
static inline struct skip_linked_list * skip_linked_list_node_find_key_internal(struct skip_linked_list *list, sint32 key, uint32 lvl);
static inline struct skip_linked_list * skip_linked_list_insert_before_head(struct skip_linked_list *list, struct skip_linked_list *tgt);
static inline struct skip_linked_list * skip_linked_list_node_remove_with_previous_list(struct skip_linked_list *tgt, struct skip_linked_list **pre_list, uint32 lvl);
static inline struct skip_linked_list * skip_linked_list_node_remove_head(struct skip_linked_list *list);
static inline struct skip_linked_list * skip_linked_list_node_remove_internal(struct skip_linked_list **list, sint32 key);
/* END of skip linked list, _NOT_ Circular. */

#endif
