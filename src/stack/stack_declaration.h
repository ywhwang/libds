#ifndef STACK_DECLARATION_H
#define STACK_DECLARATION_H


bool array_stack_empty_p(struct array_stack *stack);
bool array_stack_full_p(struct array_stack *stack);
bool linked_stack_empty_p(struct linked_stack *stack);
bool linked_stack_full_p(struct linked_stack *stack);
static inline bool array_stack_empty_p_internal(struct array_stack *stack);
static inline bool array_stack_full_p_internal(struct array_stack *stack);
static inline bool linked_stack_empty_p_internal(struct linked_stack *stack);
static inline bool linked_stack_full_p_internal(struct linked_stack *stack);
static inline bool linked_stack_node_empty_p(struct linked_stack_space *node);
static inline bool linked_stack_node_full_p(struct linked_stack_space *node);
static inline struct linked_stack_space * linked_stack_node_create(uint32 dim);
static inline struct linked_stack_space * linked_stack_node_next(struct linked_stack_space *node);
static inline struct linked_stack_space * linked_stack_node_previous(struct linked_stack_space *node);
static inline struct linked_stack_space * linked_stack_node_remove(struct linked_stack_space *node);
static inline struct linked_stack_space * linked_stack_space_offset_reflect(struct doubly_linked_list *link);
static inline uint32 array_stack_rest_internal(struct array_stack *stack);
static inline uint32 linked_stack_node_capacity(struct linked_stack_space *node);
static inline uint32 linked_stack_node_rest(struct linked_stack_space *node);
static inline uint32 linked_stack_rest_internal(struct linked_stack *stack);
static inline void array_stack_resize_internal(struct array_stack *stack, uint32 dim);
static inline void linked_stack_node_initial(struct linked_stack_space *node, uint32 dim);
static inline void linked_stack_node_iterate(struct linked_stack_space *node, void (*handler)(void *));
static inline void linked_stack_resize_internal(struct linked_stack *stack, uint32 dim);
struct array_stack * array_stack_create(void);
struct linked_stack * linked_stack_create(void);
uint32 array_stack_capacity(struct array_stack *stack);
uint32 array_stack_rest(struct array_stack *stack);
uint32 linked_stack_capacity(struct linked_stack *stack);
uint32 linked_stack_rest(struct linked_stack *stack);
void * array_stack_pop(struct array_stack *stack);
void * linked_stack_pop(struct linked_stack *stack);
void array_stack_cleanup(struct array_stack *stack);
void array_stack_destroy(struct array_stack **stack);
void array_stack_iterate(struct array_stack *stack, void (*handler)(void *));
void array_stack_push(struct array_stack *stack, void *member);
void array_stack_resize(struct array_stack *stack, uint32 dim);
void linked_stack_cleanup(struct linked_stack *stack);
void linked_stack_destroy(struct linked_stack **stack);
void linked_stack_iterate(struct linked_stack *stack, void (*handler)(void *));
void linked_stack_push(struct linked_stack *stack, void *member);
void linked_stack_resize(struct linked_stack *stack, uint32 dim);

#endif
