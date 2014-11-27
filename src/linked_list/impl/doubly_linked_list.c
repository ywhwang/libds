/*
 * _RETURN_ one new node linked list.
 *   If no memory available, it never return, export an error and exit.
 */
struct doubly_linked_list *
dlinked_list_create(void)
{
    struct doubly_linked_list *head;

    head = malloc_ds(sizeof(*head));
    if (!head) {
        pr_log_err("Fail to get memory from system.\n");
    } else {
        dlinked_list_initial(head);
    }

    return head;
}

/*
 * Init single node linked list.
 *   If NULL _ARGV_, nothing will be done.
 */
void
dlinked_list_initial(struct doubly_linked_list *head)
{
    if (head) {
        head->index = 0u;
        head->next = head;
        head->previous = head;
    }

    return;
}

/*
 * _RETURN_ one linked list from given int array.
 *          If invalid _ARGV_, _RETURN_ NULL.
 */
struct doubly_linked_list *
dlinked_list_generate(sint32 *val, uint32 size)
{
    struct doubly_linked_list *head;
    register struct doubly_linked_list *node;
    register int *iterator;

    head = NULL;
    if (val && size > 0) {
        iterator = val;
        node = dlinked_list_create();
        node->index = (uint32)(*iterator++);
        head = node;

        while (iterator < val + size) {
            dlinked_list_append_node(node, *iterator++);
            node = node->next;
        }
    }

    return head;
}

/*
 * Append one node of given value after the given node.
 *   If NULL _ARGV_, nothing will be done.
 *   If uninitialized or destroyed, export warning, nothing else will be done.
 */
void
dlinked_list_append_node(struct doubly_linked_list *node, uint32 value)
{
    struct doubly_linked_list *next;

    if (node) {
        if (!node->next || !node->previous) {
            pr_log_warn("Uninitialized or destroyed doubly linked list node.\n");
        } else {
            next = dlinked_list_create();
            next->index = value;
            dlinked_list_insert_after(node, next);
        }
    }

    return;
}

/*
 * _RETURN_ the next node of linked list.
 *   If NULL _ARGV_, _RETURN_ NULL.
 *   If uninitialized or destroyed _ARGV_, _RETURN_ NULL.
 */
struct doubly_linked_list *
dlinked_list_next_node(struct doubly_linked_list *node)
{
    struct doubly_linked_list *next;

    next = NULL;
    if (!node->next || !node->previous) {
        pr_log_warn("Uninitialized or destroyed doubly linked list node.\n");
    } else if (node && node->next && node->previous) {
        next = node->next;
    }

    return next;
}

/*
 * _RETURN_ the previous node of linked list.
 *   If NULL _ARGV_, _RETURN_ NULL.
 *   If uninitialized or destroyed _ARGV_, _RETURN_ NULL.
 */
struct doubly_linked_list *
dlinked_list_previous_node(struct doubly_linked_list *node)
{
    struct doubly_linked_list *previous;

    previous = NULL;
    if (node && node->next && node->previous) {
        previous = node->previous;
    } else if (!node->next || !node->previous) {
        pr_log_warn("Uninitialized or destroyed doubly linked list node.\n");
    }

    return previous;
}

/*
 * Insert one existed node after another given node.
 * _ARGV_, cur current given node.
 *         node inserted node.
 *         If either of _ARGV_ is NULL, nothing will be done.
 */
void
dlinked_list_insert_after(struct doubly_linked_list *cur,
    struct doubly_linked_list *node)
{
    if (cur && node)
    {
        cur->next->previous = node;
        node->next = cur->next;
        cur->next = node;
        node->previous = cur;
    }

    return;
}

/*
 * Insert one existed node before another given node.
 * _ARGV_, cur current given node.
 *         node inserted node.
 *         If either of _ARGV_ is NULL, nothing will be done.
 */
void
dlinked_list_insert_before(struct doubly_linked_list *cur,
    struct doubly_linked_list *node)
{
    struct doubly_linked_list *prev;

    if (cur && node)
    {
        prev = cur->previous;
        dlinked_list_insert_after(prev, node);
    }

    return;
}

/*
 * Destroy the whole doubly linked list, set head to NULL.
 *   If NULL _ARGV_, nothing will be done.
 */
void
dlinked_list_destroy(struct doubly_linked_list **head)
{
    register struct doubly_linked_list *node;
    register struct doubly_linked_list *next;

    if (head && *head) {
        /*
         * Do not call dlinked_list_remove_node for
         * the consider of performance drop.
         */
        next = (*head)->next;
        while (*head != (node = next)) {
            next = node->next;
            free_ds(node);
        }

        free_ds(node);
        *head = NULL;
    }

    return;
}

/*
 * _RETURN_ Length of given linked list.
 *   If NULL linked list, _RETURN_ 0.
 */
uint32
dlinked_list_length(struct doubly_linked_list *head)
{
    uint32 length;
    register struct doubly_linked_list *node;

    length = 0;
    if (head) {
        node = head;
        do {
            length++;
            node = node->next;
        } while (node != head);
    }

    return length;
}

/*
 * _RETURN_ the node of index by given head node.
 *   If invalid _ARGV_, nothing will done, _RETURN_ NULL.
 */
struct doubly_linked_list *
dlinked_list_get_node_by_index(struct doubly_linked_list *head, uint32 index)
{
    register struct doubly_linked_list *node;

    node = NULL;
    if (head) {
        if (index <= dlinked_list_length(head)) {
            node = head;
            while (index > 0) {
                node = node->next;
                index--;
            }
        }
    }

    return node;
}

/*
 * Print doubly linked list
 *   If invalid head, nothing will be done.
 */
void
dlinked_list_print(FILE *fd, char *msg, struct doubly_linked_list *head)
{
    register struct doubly_linked_list *iterator;
    char *default_msg = "Default doubly linked list";

    if (head) {
        fprintf(fd, "[%s]:\n", msg);
        if (!msg) {
            msg = default_msg;
        }

        iterator = head;
        do {
            fprintf(fd, "%d ->\n", iterator->index);
            iterator = iterator->next;
        } while (iterator != head);
    }
    fprintf(fd, "NULL\n");

    return;
}

/*
 * Exchange two node of linked list.
 *   If either _ARGV_ is NULL, nothing will be done.
 *   If the same node, nothing will be done.
 */
void
dlinked_list_exchange_node(struct doubly_linked_list *fir,
    struct doubly_linked_list *sec)
{
    struct doubly_linked_list *prev_fir;
    struct doubly_linked_list *prev_sec;

    if (fir && sec) {
        if (dlinked_list_is_contains(fir, sec) && (fir != sec)) {
            prev_fir = fir->previous;
            prev_sec = sec->previous;

            dlinked_list_lazy_remove_node(fir);
            dlinked_list_lazy_remove_node(sec);
            dlinked_list_insert_after(prev_fir, sec);
            dlinked_list_insert_after(prev_sec, fir);
        }
    }

    return;
}

/*
 * _RETURN_ true if _ARGV_ node in the list of _ARGV_ tar, else false.
 *   If either of _ARGV_ is NULL, return false.
 */
bool
dlinked_list_is_contains(struct doubly_linked_list *tar,
    struct doubly_linked_list *node)
{
    register struct doubly_linked_list *iter;
    bool contains;

    contains = false;
    if (tar && node) {
        iter = tar;
        do {
            if (iter == node) {
                contains = true;
                break;
            }
            iter = iter->next;
        } while (iter != tar);
    }

    return contains;
}

/*
 * Serialize the given linked list.
 *   If NULL, nothing will be done.
 */
void
dlinked_list_serialize(struct doubly_linked_list *head)
{
    struct doubly_linked_list *node;
    uint32 index;

    if (head) {
        index = 0;
        node = head;
        do {
            node->index = index++;
            node = node->next;
        } while (node != head);
    }

    return;
}

/*
 * Remove the given node.
 * _RETURN_ the next node.
 *   If only one node of linked list, _RETURN_ NULL.
 *   If NULL _ARGV_, _RETURN_ NULL
 */
struct doubly_linked_list *
dlinked_list_remove_node(struct doubly_linked_list *node)
{
    struct doubly_linked_list *next;

    next = NULL;
    if (node) {
        dlinked_list_lazy_remove_node(node);
        if (node->next != node) {
            next = node->next;
        }
        free_ds(node);
    }

    return next;
}

/*
 * Remove the given node without free the memory.
 *   If only one node of linked list, nothing will be done.
 */
void
dlinked_list_lazy_remove_node(struct doubly_linked_list *node)
{
    if (node) {
        node->previous->next = node->next;
        node->next->previous = node->previous;
    }

    return;
}

/*
 * Iterate each node by given function handler.
 *   If NULL _ARGV_, nothing will be done.
 */
void
dlinked_list_iterate(struct doubly_linked_list *head,
    void (*handler)(struct doubly_linked_list *))
{
    register struct doubly_linked_list *node;

    if (head && handler) {
        node = head;
        do {
            (*handler)(node);
            node = node->next;
        } while (node != head);
    }

    return;
}