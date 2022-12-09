#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>


// Declare Structures to use
typedef struct ListNode
{
    int value;
    struct ListNode * next;
}   ListNode;

typedef struct LinkedList
{
    ListNode * head;
} LinkedList;


// Functions
void llist_init(LinkedList * list)
{
    list -> head = NULL;
}


void llist_print(LinkedList * list)
{
    ListNode * curr = list -> head;
    if (curr == NULL) {
        printf("This Linkedlist is empty\n");
        return;
    }

    printf("{");
    while (curr != NULL)
    {
        printf("%d", curr->value);
        curr = curr->next;
        if (curr != NULL) printf(", ");
    }
    printf("}\n");
}

// Add to the beginning of the Linked List
void llist_add(LinkedList * list, int value)
{
    ListNode * toAdd = (ListNode *)malloc(sizeof(ListNode));
    toAdd -> value = value;

    // add 
    toAdd -> next = list -> head;
    list -> head = toAdd;
}


// return true (1) if value exist in ll
int llist_exists(LinkedList * list, int value)
{
    ListNode * curr = list -> head;
    while (curr != NULL)
    {
        if (curr->value == value) return 1;
        curr = curr -> next;
    }
    return 0;
}


// Remove with the value
int llist_remove(LinkedList * list, int value) {
	ListNode * curr = list->head; // start from the headnode
	
    // i) if the first Node is the one
    if (curr->value == value)
    {
        list -> head = curr -> next;
        free(curr);
        return 0;
    }
    
    // ii) otherwise
    while (curr->next != NULL)
    {
        if (curr->next -> value == value)
        {
            curr->next = curr -> next -> next;
            free(curr->next);
            return 0;
        }
        curr = curr -> next;
    }
}


// It stores in *value the value that correspond to the ith entry.
// It returns 1 if success or 0 if there is no ith entry.
int llist_get_ith(LinkedList * list, int ith, int *value)
{
    int ind = 0;
    ListNode * curr = list -> head;
    while (curr != NULL)
    {
        if (ind == ith)
        {
            *value = curr->value; // save as value
            return 1;
        }
        ind++;
        curr = curr->next;
    }
    return 0;
}


// Remove by index
int llist_remove_ith(LinkedList * list, int ith) {
    ListNode * curr = list -> head;

    // if first node
	if (ith == 0)
    {   
        list->head = curr->next;
        free(curr);
        return 0;
    }

    // Otherwise
    while (ith > 1)
    {
        curr = curr->next;
        ith--;
    }
    
    ListNode * aft = curr->next;
    curr->next = curr->next->next;
    free(aft);
	return 0;
}


int llist_number_elements(LinkedList * list)
{
    if (list->head == NULL) return 0;
    ListNode * curr = list -> head;

    int total = 0;
    while(curr != NULL)
    {
        total++;
        curr = curr->next;
    }
    return total;
}



int llist_save(LinkedList * list, char * file_name)
{
    FILE * f = fopen(file_name, "w+");
    if (f == NULL) return 0;
    ListNode * curr = list -> head;

    while (curr != NULL)
    {
        fprintf(f, "%d\n", curr->value);
        curr = curr->next;
    }

    fclose(f);
    return 0;
}


// It reads the list from the file_name indicated. If the list already has entries, 
// it will clear the entries.
int llist_read(LinkedList * list, char * file_name)
{
    FILE * f = fopen(file_name, "r");
    if (f == NULL)
    {
        return 0;
    }

    int toAddVal;
    while (fscanf(f, "%d", &toAddVal) != EOF)
    {
        llist_add(list, toAddVal);
    }
    return 1;
}

void llist_sort(LinkedList * list, int ascending)
{

}

void llist_clear(LinkedList *list)
{
    ListNode * curr = list -> head;
    while (curr != NULL)
    {
        ListNode * nxt = curr -> next;
        free(curr);
        curr = nxt;
    }

    list -> head = NULL;
}

// int llist_remove_first(LinkedList * list, int * value);
// int llist_remove_last(LinkedList * list, int * value);
// void llist_insert_first(LinkedList * list, int value);
// void llist_insert_last(LinkedList * list, int value);
void llist_reverse( LinkedList * list );



int main()
{
    LinkedList ll;
    llist_init(&ll);
    llist_print(&ll);

    // Add 1, 3, 2
    llist_add(&ll, 2);
    llist_add(&ll, 3);
    llist_add(&ll, 1);
    llist_print(&ll);


    // Check if it exists
    printf("\n");
    int check = 4;
    if (llist_exists(&ll,check))
    {
        printf("%d Exist\n", check);
    }
    else 
    {
        printf("%d Does not exist\n", check);
    }

    // Remove 
    // int remove = 2;
    // llist_remove(&ll, remove);
    // llist_print(&ll);

    // Entry Check
    printf("\n");
    int value;
    int ith = 4;
    if (llist_get_ith(&ll, ith, &value))
    {
        printf("%dth Entry's value is %d\n", ith, value);
    }
    else
    {
        printf("No ith entry exist\n");
    }
    llist_print(&ll);
    

    // Remove by index
    // int removeInd = 1;
    // llist_remove_ith(&ll, removeInd);
    // llist_print(&ll);

    // Num ele
    int ele = llist_number_elements(&ll);
    printf("Number of elements is %d\n", ele);

    // Write on File
    char * fileName = "ll.txt";
    llist_save(&ll, fileName);
    llist_print(&ll);

    // Read from File
    llist_read(&ll, fileName);
    llist_print(&ll);

    // // Clear 
    // llist_clear(&ll);
    // llist_print(&ll);


}