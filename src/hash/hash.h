#ifndef HAVE_HASH_H
#define HAVE_HASH_H

#define DEFAULT_CHAIN_HASH_SIZE 11u
#define DEFAULT_LOAD_FACTOR     72u /* Means 0.72 or 72% */

#define OPEN_ADDRESSING_HASH_LOAD_FACTOR 50u

extern void doubly_linked_list_destroy(struct doubly_linked_list **head);
extern struct doubly_linked_list * doubly_linked_list_node_create(void *val, uint32 sid);
extern void doubly_linked_list_insert_after(struct doubly_linked_list *list, void *val);
extern void doubly_linked_list_remove_and_destroy(struct doubly_linked_list **node);

#endif
