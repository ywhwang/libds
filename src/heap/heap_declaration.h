#ifndef HEAP_DECLARATION_H
#define HEAP_DECLARATION_H


bool maximal_heap_empty_p(struct maximal_heap *heap);
bool maximal_heap_full_p(struct maximal_heap *heap);
bool min_max_heap_empty_p(struct min_max_heap *heap);
bool min_max_heap_empty_p_internal(struct min_max_heap *heap);
bool min_max_heap_full_p(struct min_max_heap *heap);
bool minimal_heap_empty_p(struct minimal_heap *heap);
bool minimal_heap_full_p(struct minimal_heap *heap);
static inline bool binary_heap_child_exist_p(struct binary_heap *heap, uint32 index);
static inline bool binary_heap_depth_even_p(struct binary_heap *heap, uint32 index);
static inline bool binary_heap_depth_odd_p(struct binary_heap *heap, uint32 index);
static inline bool binary_heap_empty_p(struct binary_heap *heap);
static inline bool binary_heap_full_p(struct binary_heap *heap);
static inline bool binary_heap_index_legal_p(struct binary_heap *heap, uint32 index);
static inline bool binary_heap_maximal_ordered_p(struct binary_heap *heap, uint32 index, sint64 nice, uint32 *tgt_index);
static inline bool binary_heap_maximal_percolate_down(struct binary_heap *heap, uint32 index, sint64 nice, uint32 *tgt_index);
static inline bool binary_heap_min_max_down_ordered_p(struct binary_heap *heap, uint32 index, sint64 nice, uint32 *tgt_index);
static inline bool binary_heap_min_max_up_ordered_p(struct binary_heap *heap, uint32 index, sint64 nice, uint32 *tgt_index);
static inline bool binary_heap_minimal_ordered_p(struct binary_heap *heap, uint32 index, sint64 nice, uint32 *tgt_index);
static inline bool binary_heap_minimal_percolate_down(struct binary_heap *heap, uint32 index, sint64 nice, uint32 *tgt_index);
static inline bool binary_heap_nice_legal_p(sint64 nice);
static inline bool binary_heap_ordered_p(struct binary_heap *heap, void *heap_order);
static inline bool binary_heap_structure_legal_p(struct binary_heap *heap);
static inline bool binary_heap_valid_ordered_func_ptr_p(void *func_ptr);
static inline bool leftist_heap_node_heap_ordered_p(struct leftist_heap *node);
static inline bool leftist_heap_node_npl_ordered_p(struct leftist_heap *node);
static inline bool leftist_heap_npl_optimize_validity_p(struct leftist_heap *node, sint32 expected);
static inline bool leftist_heap_structure_legal_p(struct leftist_heap *heap);
static inline bool leftist_heap_validity_p(struct leftist_heap *heap);
static inline bool min_max_heap_index_legal_p(struct min_max_heap *heap, uint32 index);
static inline bool min_max_heap_ordered_p(struct min_max_heap *heap);
static inline bool min_max_heap_structure_legal_p(struct min_max_heap *heap);
static inline sint32 leftist_heap_npl_internal(struct leftist_heap *node);
static inline sint32 leftist_heap_npl_internal_default(struct leftist_heap *node);
static inline struct binary_heap * binary_heap_create(uint32 capacity);
static inline struct heap_data * binary_heap_node_create(sint64 nice, void *val);
static inline struct heap_data * min_max_heap_remove_isolate(struct min_max_heap *heap, uint32 index);
static inline struct leftist_heap * leftist_heap_create_internal(void *val, sint32 npl, sint64 nice);
static inline struct leftist_heap * leftist_heap_merge_from_right(struct leftist_heap *heap, struct leftist_heap *merge);
static inline struct leftist_heap * leftist_heap_merge_internal(struct leftist_heap *heap, struct leftist_heap *merge);
static inline struct leftist_heap * leftist_heap_remove_min_internal(struct leftist_heap **heap);
static inline uint32 binary_heap_child_max_nice_index(struct binary_heap *heap, uint32 index);
static inline uint32 binary_heap_child_min_nice_index(struct binary_heap *heap, uint32 index);
static inline uint32 binary_heap_depth(uint32 index);
static inline uint32 binary_heap_gdp_randchild_max_nice_index(struct binary_heap *heap, uint32 index);
static inline uint32 binary_heap_gdp_randchild_min_nice_index(struct binary_heap *heap, uint32 index);
static inline uint32 binary_heap_reorder(struct binary_heap *heap, uint32 index, sint64 nice, void *heap_order);
static inline uint32 binary_heap_serial_big_nice_index(struct binary_heap *heap, uint32 index, uint32 count);
static inline uint32 binary_heap_serial_small_nice_index(struct binary_heap *heap, uint32 index, uint32 count);
static inline void * binary_heap_data_destroy(struct heap_data *data);
static inline void * binary_heap_remove_root(struct binary_heap *heap, void *order);
static inline void * binary_heap_root(struct binary_heap *heap);
static inline void * leftist_heap_get_min_internal(struct leftist_heap *heap);
static inline void * maximal_heap_remove_internal(struct maximal_heap *heap, uint32 index);
static inline void * min_max_heap_remove_internal(struct min_max_heap *heap, uint32 index);
static inline void * min_max_heap_remove_max_internal(struct min_max_heap *heap);
static inline void * minimal_heap_remove_internal(struct minimal_heap *heap, uint32 index);
static inline void binary_heap_capacity_extend(struct binary_heap *heap);
static inline void binary_heap_cleanup(struct binary_heap *heap);
static inline void binary_heap_destroy(struct binary_heap **heap);
static inline void binary_heap_insert(struct binary_heap *heap, void *val, sint64 nice, void *ordering);
static inline void binary_heap_node_create_by_index(struct binary_heap *heap, uint32 index, sint64 nice, void *val);
static inline void leftist_heap_destroy_internal(struct leftist_heap *heap);
static inline void leftist_heap_node_child_swap(struct leftist_heap *node);
static inline void leftist_heap_node_npl_update(struct leftist_heap *node);
static inline void leftist_heap_reorder_from_right(struct leftist_heap *heap);
static inline void maximal_heap_build_internal(struct maximal_heap *heap);
static inline void maximal_heap_nice_alter(struct maximal_heap *heap, uint32 index, sint64 new_nice);
static inline void min_max_heap_nice_alter(struct min_max_heap *heap, uint32 index, sint64 new_nice);
static inline void minimal_heap_build_internal(struct minimal_heap *heap);
static inline void minimal_heap_nice_alter(struct minimal_heap *heap, uint32 index, sint64 new_nice);
struct doubly_linked_list * min_max_heap_remove(struct min_max_heap *heap, uint32 index);
struct leftist_heap * leftist_heap_create(void);
struct leftist_heap * leftist_heap_insert(struct leftist_heap *heap, void *val, sint64 nice);
struct leftist_heap * leftist_heap_merge(struct leftist_heap *heap, struct leftist_heap *merge);
struct leftist_heap * leftist_heap_node_create(void *val, sint32 nlp, sint64 nice);
struct leftist_heap * leftist_heap_remove_min(struct leftist_heap **heap);
struct maximal_heap * maximal_heap_build(struct heap_data **hd_array, uint32 size);
struct maximal_heap * maximal_heap_create(uint32 capacity);
struct min_max_heap * min_max_heap_create(uint32 capacity);
struct minimal_heap * minimal_heap_build(struct heap_data **hd_array, uint32 size);
struct minimal_heap * minimal_heap_create(uint32 capacity);
uint32 min_max_heap_depth(struct min_max_heap *heap, uint32 index);
void * leftist_heap_get_min(struct leftist_heap *heap);
void * maximal_heap_get_max(struct maximal_heap *heap);
void * maximal_heap_remove(struct maximal_heap *heap, uint32 index);
void * maximal_heap_remove_max(struct maximal_heap *heap);
void * min_max_heap_get_max(struct min_max_heap *heap);
void * min_max_heap_get_min(struct min_max_heap *heap);
void * min_max_heap_remove_max(struct min_max_heap *heap);
void * min_max_heap_remove_min(struct min_max_heap *heap);
void * minimal_heap_get_min(struct minimal_heap *heap);
void * minimal_heap_remove(struct minimal_heap *heap, uint32 index);
void * minimal_heap_remove_min(struct minimal_heap *heap);
void leftist_heap_destroy(struct leftist_heap **heap);
void leftist_heap_remove_min_and_destroy(struct leftist_heap **heap);
void maximal_heap_cleanup(struct maximal_heap *heap);
void maximal_heap_decrease_nice(struct maximal_heap *heap, uint32 index, uint32 offset);
void maximal_heap_destroy(struct maximal_heap **heap);
void maximal_heap_increase_nice(struct maximal_heap *heap, uint32 index, uint32 offset);
void maximal_heap_insert(struct maximal_heap *heap, void *val, sint64 nice);
void min_max_heap_cleanup(struct min_max_heap *heap);
void min_max_heap_decrease_nice(struct min_max_heap *heap, uint32 index, uint32 offset);
void min_max_heap_destroy(struct min_max_heap **heap);
void min_max_heap_increase_nice(struct min_max_heap *heap, uint32 index, uint32 offset);
void min_max_heap_insert(struct min_max_heap *heap, void *val, sint64 nice);
void minimal_heap_cleanup(struct minimal_heap *heap);
void minimal_heap_decrease_nice(struct minimal_heap *heap, uint32 index, uint32 offset);
void minimal_heap_destroy(struct minimal_heap **heap);
void minimal_heap_increase_nice(struct minimal_heap *heap, uint32 index, uint32 offset);
void minimal_heap_insert(struct minimal_heap *heap, void *val, sint64 nice);

#endif
