#ifndef LINKED_LIST_DECLARATION_H
#define LINKED_LIST_DECLARATION_H

bool doubly_linked_list_contains_p(struct doubly_linked_list *list, struct doubly_linked_list *node);
bool single_linked_list_contains_p(struct single_linked_list *list, struct single_linked_list *node);
bool skip_linked_list_key_contains_p(struct skip_linked_list *list, sint32 key);
static inline bool doubly_linked_list_contains_p_internal(struct doubly_linked_list *list, struct doubly_linked_list *node);
static inline bool single_linked_list_contains_p_internal(struct single_linked_list *list, struct single_linked_list *node);
static inline bool skip_linked_list_key_contains_p_internal(struct skip_linked_list *list, sint32 key);
static inline bool skip_linked_list_node_exist_on_level(struct skip_linked_list *list, struct skip_linked_list *node, uint32 level);
static inline bool skip_linked_list_ordering_p(struct skip_linked_list *list);
static inline struct doubly_linked_list * doubly_linked_list_node_create_internal(void *val);
static inline struct doubly_linked_list * doubly_linked_list_remove_internal(struct doubly_linked_list **node);
static inline struct single_linked_list * single_linked_list_node_remove_internal_default(struct single_linked_list **node);
static inline struct single_linked_list * single_linked_list_node_remove_internal_optimize( struct single_linked_list **node);
static inline struct single_linked_list * single_linked_list_previous_internal(struct single_linked_list *node);
static inline struct skip_linked_list * skip_linked_list_insert_before_head(struct skip_linked_list *list, struct skip_linked_list *tgt);
static inline struct skip_linked_list * skip_linked_list_node_find_key_internal(struct skip_linked_list *list, sint32 key, uint32 lvl);
static inline struct skip_linked_list * skip_linked_list_node_insert_internal(struct skip_linked_list **list, struct skip_linked_list *tgt);
static inline struct skip_linked_list * skip_linked_list_node_remove_head(struct skip_linked_list *list);
static inline struct skip_linked_list * skip_linked_list_node_remove_internal(struct skip_linked_list **list, sint32 key);
static inline struct skip_linked_list * skip_linked_list_node_remove_with_previous_list(struct skip_linked_list *tgt, struct skip_linked_list **pre_list, uint32 lvl);
static inline uint32 doubly_linked_list_length_internal(struct doubly_linked_list *list);
static inline uint32 single_linked_list_length_internal(struct single_linked_list *list);
static inline uint32 skip_linked_list_length_internal(struct skip_linked_list *list);
static inline void doubly_linked_list_initial_internal(struct doubly_linked_list *list, void *val);
static inline void doubly_linked_list_insert_after_internal(struct doubly_linked_list *list, void *val);
static inline void doubly_linked_list_insert_before_internal(struct doubly_linked_list *list, void *val);
static inline void doubly_linked_list_insert_ptr_after_internal(struct doubly_linked_list *list, struct doubly_linked_list *node);
static inline void doubly_linked_list_insert_ptr_before_internal(struct doubly_linked_list *list, struct doubly_linked_list *node);
static inline void single_linked_list_insert_after_internal(struct single_linked_list *list, void *val, uint32 sid);
static inline void skip_linked_list_insert_update_with_lvl(struct skip_linked_list *tgt, struct skip_linked_list **prev_list, uint32 lvl);
static inline void skip_linked_list_node_clean(struct skip_linked_list *list);
static inline void skip_linked_list_node_remove_on_level(struct skip_linked_list *list, struct skip_linked_list *removed, uint32 level);
struct doubly_linked_list * doubly_linked_list_create(void);
struct doubly_linked_list * doubly_linked_list_merge(struct doubly_linked_list *m, struct doubly_linked_list *n);
struct doubly_linked_list * doubly_linked_list_node_by_index(struct doubly_linked_list *list, uint32 index);
struct doubly_linked_list * doubly_linked_list_node_copy(struct doubly_linked_list *node);
struct doubly_linked_list * doubly_linked_list_node_create(void *val);
struct doubly_linked_list * doubly_linked_list_remove(struct doubly_linked_list **node);
struct single_linked_list * single_linked_list_create(void);
struct single_linked_list * single_linked_list_merge(struct single_linked_list *m, struct single_linked_list *n);
struct single_linked_list * single_linked_list_node_by_index(struct single_linked_list *list, uint32 index);
struct single_linked_list * single_linked_list_node_copy(struct single_linked_list *node);
struct single_linked_list * single_linked_list_node_create(void *val, uint32 sid);
struct single_linked_list * single_linked_list_node_remove(struct single_linked_list **node);
struct single_linked_list * single_linked_list_previous(struct single_linked_list *node);
struct skip_linked_list * skip_linked_list_create(void);
struct skip_linked_list * skip_linked_list_merge(struct skip_linked_list *m, struct skip_linked_list *n);
struct skip_linked_list * skip_linked_list_node_by_index(struct skip_linked_list *list, uint32 index);
struct skip_linked_list * skip_linked_list_node_create(void *val, sint32 key);
struct skip_linked_list * skip_linked_list_node_find_key(struct skip_linked_list *list, sint32 key);
struct skip_linked_list * skip_linked_list_node_insert(struct skip_linked_list **list, struct skip_linked_list *tgt);
struct skip_linked_list * skip_linked_list_node_remove(struct skip_linked_list **list, sint32 key);
uint32 doubly_linked_list_length(struct doubly_linked_list *list);
uint32 single_linked_list_length(struct single_linked_list *list);
uint32 skip_linked_list_length(struct skip_linked_list *list);
void doubly_linked_list_destroy(struct doubly_linked_list **list);
void doubly_linked_list_initial(struct doubly_linked_list *list);
void doubly_linked_list_insert_after(struct doubly_linked_list *list, void *val);
void doubly_linked_list_insert_before(struct doubly_linked_list *list, void *val);
void doubly_linked_list_insert_ptr_after(struct doubly_linked_list *list, struct doubly_linked_list *node);
void doubly_linked_list_insert_ptr_before(struct doubly_linked_list *list, struct doubly_linked_list *node);
void doubly_linked_list_iterate(struct doubly_linked_list *list, void (*handler)(void *));
void doubly_linked_list_remove_and_destroy(struct doubly_linked_list **node);
void single_linked_list_destroy(struct single_linked_list **list);
void single_linked_list_initial(struct single_linked_list *list);
void single_linked_list_insert_after(struct single_linked_list *list, void *val);
void single_linked_list_insert_before(struct single_linked_list *list, void *val);
void single_linked_list_iterate(struct single_linked_list *list, void (*handler)(void *));
void single_linked_list_node_initial(struct single_linked_list *list, void *val, uint32 sid);
void single_linked_list_node_remove_and_destroy(struct single_linked_list **node);
void single_linked_list_serialize(struct single_linked_list *list);
void skip_linked_list_destroy(struct skip_linked_list **list);
void skip_linked_list_initial(struct skip_linked_list *list);
void skip_linked_list_iterate(struct skip_linked_list *list, void (*handler)(void *));
void skip_linked_list_node_initial(struct skip_linked_list *list, void *val, sint32 key);
void skip_linked_list_node_remove_and_destroy(struct skip_linked_list **list, sint32 key);

#endif
