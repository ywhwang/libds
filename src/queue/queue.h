#ifndef HAVE_QUEUE_H
#define HAVE_QUEUE_H

#define DEFAULT_QUEUE_SPACE_SIZE   1024
#define EXPAND_QUEUE_SPACE_MIN     32
#define REST_INVALID               0xffffffff
#define CAPACITY_INVALID           0xffffffff

extern bool array_stack_full_p(struct array_stack *stack);
extern bool array_stack_empty_p(struct array_stack *stack);
extern void array_stack_iterate(struct array_stack *stack, void (*handler)(void *));
extern void array_stack_cleanup(struct array_stack *stack);
extern void array_stack_destroy(struct array_stack **stack);
extern void array_stack_resize(struct array_stack *stack, uint32 dim);
extern void array_stack_push(struct array_stack *stack, void *member);
extern void doubly_linked_list_initial(struct doubly_linked_list *);
extern void doubly_linked_list_insert_ptr_before(struct doubly_linked_list *list, struct doubly_linked_list *node);
extern void doubly_linked_list_insert_ptr_after(struct doubly_linked_list *list, struct doubly_linked_list *node);
extern void * array_stack_pop(struct array_stack *stack);
extern uint32 array_stack_capacity(struct array_stack *stack);
extern uint32 array_stack_rest(struct array_stack *stack);
extern struct array_stack * array_stack_create(void);
extern struct doubly_linked_list * doubly_linked_list_remove(struct doubly_linked_list **node);

#endif
