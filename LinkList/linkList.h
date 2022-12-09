#ifndef LINKLIST_H
# define LINKLIST_H

// declare other header files to include


// Declare Structures to use
typedef struct ListNode
{
    int value;
    struct ListNode * next;
}   ListNode;

typedef struct LinkedList
{
    ListNode * head;
} List;


// Functions
void llist_init(LinkedList * list);
void llist_print(LinkedList * list);
void llist_add(LinkedList * list, int value);
int llist_exists(LinkedList * list, int value);
int llist_remove(LinkedList * list, int value);
int llist_get_ith(LinkedList * list, int ith, int *value);
int llist_remove_ith(LinkedList * list, int ith);
int llist_number_elements(LinkedList * list);
int llist_save(LinkedList * list, char * file_name);
int llist_read(LinkedList * list, char * file_name);
void llist_sort(LinkedList * list, int ascending);
void llist_clear(LinkedList *list);

int llist_remove_first(LinkedList * list, int * value);
int llist_remove_last(LinkedList * list, int * value);
void llist_insert_first(LinkedList * list, int value);
void llist_insert_last(LinkedList * list, int value);





#endif