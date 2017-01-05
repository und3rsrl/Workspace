///\file linked_lists.c
///\brief C library implementation for simple and double linked lists
///
/// Created by Alexandru Chiurtu on 11/04/2016

#include "linked_lists.h"
#include "stdlib.h"

/// Simple Linked Lists


simple_list *simple_list_create() {
    
    ///\brief Creating and allocating memory for a simple linked list.
    
    return calloc(1,sizeof(simple_list));
}


void init_simple_list(simple_list *list) {
    
    ///\brief Initialize the list head.
    ///\param *list An simple linked list
    
    list->head = NULL;
    list->head = (simple_listNode *)malloc(sizeof(simple_listNode));
    list->head->next = NULL;
}


void display_simple(simple_listNode *head) {
    
    ///\brief Display a simple linked list.
    ///\param head Head of a simple linked list.
    ///
    /// It displays list's elements if the list is not empty,
    /// Else it prints a message that tell the list is empty.
    
    if(head->next != NULL){
        simple_listNode *current;
        int iter = 0;
        current = head;
        printf("Lista contine urmatoarele elemte: \n");
        while (current->next != NULL) {
            iter++;
            current = current->next;
            printf("%d. %d,\n", iter, current->value);
        }
    } else {
        printf("Lista este goala");
    }
    printf("\n");
}


void addFirst_simple(simple_listNode *head, int value) {
    
    ///\brief Add an element in front of a simple_list.
    ///\param head Head of a simple linked list.
    ///\param value An integer that receive the value to be added.
    ///
    /// It adds the element in front of the list and prints a message with the value added.
    
    simple_listNode *new_item;
    new_item = (simple_listNode *) malloc(sizeof(simple_listNode));
    new_item->next = head->next;
    new_item->value = value;
    head->next = new_item;
    //printf("Valoare %d a fost adaugata.\n", value);
}

void addLast_simple(simple_listNode *head, int value) {
    
    ///\brief Add an element at the end of a simple_list.
    ///\param head Head of a simple linked list.
    ///\param value An integer that receive the value to be added.
    ///
    /// It adds the element at the end of the list and prints a message with the value added.

    
    simple_listNode *new_item,*current = head;
    new_item = (simple_listNode *) malloc(sizeof(simple_listNode));
    while(current->next != NULL)
        current = current->next;
    new_item->value = value;
    new_item->next = NULL;
    current->next = new_item;
    
}


void addPoz_simple(simple_listNode *head, int value, int poz) {
    
    ///\brief Add an element at the position specified in a simple_list.
    ///\param head Head of a simple linked list.
    ///\param value An integer that receive the value to be added.
    ///\param value An integer that receive the position where the value to be added.
    ///
    /// It adds the element at the end of the list and prints a message with the value added.
    
    int iter = 0;
    simple_listNode *current = head, *new_item;
    
    if(poz == 1)
        addFirst_simple(head, value);
    else if(poz == count_simple(head) + 1)
        addLast_simple(head, value);
    else {
        while (iter != poz - 1) {
            current = current->next;
            iter++;
        }
        new_item = (simple_listNode *)malloc(sizeof(simple_listNode));
        new_item->next = current->next;
        new_item->value = value;
        current->next = new_item;
        
    }
}


void deletePoz_simple(simple_listNode *head,int poz) {
    
    ///\brief Remove an element at the position specified in a simple_list.
    ///\param head Head of a simple linked list.
    ///\param value An integer that receive the position of the element to be deleted.
    ///
    /// It deletes the element at the position specified of the list and prints a message with the value deleted.
    
    int iter = 0;
    simple_listNode *deletedItem, *current = head;
    poz = poz - 1;
    
    while(iter < poz) {
        current = current->next;
        iter++;
    }
    
    deletedItem = current->next;
    current->next = deletedItem->next;
    printf("Elementul de pe pozitia %d cu valoarea %d a fost sters. \n", poz+1,deletedItem->value);
    free(deletedItem);
}


int count_simple(simple_listNode *head) {
    
    ///\brief Count the number of elements in a simple_list.
    ///\param head Head of a simple linked list.
    ///
    /// It counts the number of elements in a list and print the number of elements obtained.
    
    simple_listNode *current;
    int count = 0;
    
    current = head;
    
    
    while (current->next != NULL) {
        count++;
        current = current->next;
    }
    
    
    return count;
}


void merge_simple(simple_list *list1, simple_list *list2) {
    
    ///\brief Merge two simple_lists.
    ///\param list1 This parameter takes the adress of the first list.
    ///\param list2 This parameter takes the adress of the second list.
    ///
    /// It takes two simple lists as parameters and merge them into single one.

    simple_listNode *temp;
    
    if (list1->head->next == NULL) {
        list1 = list2;
        return;
    }
    
    if(list2->head->next == NULL) {
        return;
    }
    
    if(list1->head->next == NULL && list2->head->next == NULL) {
        printf("Ambele liste sunt goale");
        return;
        
    }
    
    temp=list1->head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=list2->head->next;
    
    free(list2->head);
}



/// Double Linked Lists

double_list *double_list_create() {
    
    ///\brief Creating and allocating memory for a double_linked_list.
    
    return calloc(1,sizeof(double_list));
}



void init_double_list(double_list *list) {
    
    ///\brief Initialize the double_linked_list's head.
    ///\param *list An simple linked list
    
    list->head = NULL;
    list->head = (double_listNode *)malloc(sizeof(double_listNode));
    list->head->next = NULL;
    list->head->prev = NULL;
}


void addFirst_double(double_listNode *head, int value) {
    
    ///\brief Add an element in front of a double_list.
    ///\param head Head of a double_linked_list.
    ///\param value An integer that receive the value to be added.
    ///
    /// It adds the element in front of the list and prints a message with the value added.

    
    double_listNode *new_item;
    new_item = (double_listNode *) malloc(sizeof(double_listNode));
    new_item->next = head->next;
    if(head->next != NULL)
        head->next->prev = new_item;
    new_item->prev = head;
    new_item->value = value;
    head->next = new_item;
    
}


void addLast_double(double_listNode *head, int value) {
    
    ///\brief Add an element at the end of a double_list.
    ///\param head Head of a double_linked_list.
    ///\param value An integer that receive the value to be added.
    ///
    /// It adds the element at the end of the list and prints a message with the value added.
    
    double_listNode *new_item,*current = head;
    new_item = (double_listNode *) malloc(sizeof(double_listNode));
    while(current->next != NULL)
        current = current->next;
    new_item->value = value;
    new_item->next = NULL;
    new_item->prev = current;
    current->next = new_item;

}


void addPoz_double(double_listNode *head, int value, int poz) {
    
    ///\brief Add an element at the position specified in a double_list.
    ///\param head Head of a double_linked_list.
    ///\param value An integer that receive the value to be added.
    ///\param value An integer that receive the position where the value to be added.
    ///
    /// It adds the element at the end of the list and prints a message with the value added.
    
    
    int iter = 0;
    double_listNode *current = head, *new_item;
    
    if(poz == 1)
        addFirst_double(head, value);
    else if(poz == count_double(head) + 1)
        addLast_double(head, value);
    else {
        while(iter != poz - 1) {
            current = current->next;
            iter++;
        }
        
        new_item = (double_listNode *)malloc(sizeof(double_listNode));
        new_item = current->next;
        current->next->prev = new_item;
        current->next = new_item;
        new_item->prev = current;
        new_item->value = value;
        
        
    }
    
    new_item = (double_listNode *)malloc(sizeof(double_listNode));
    new_item->next = current->next;
    current->next = new_item;
    new_item->prev = current;
    if(new_item->next != NULL)
        new_item->next->prev = new_item;
    new_item->value = value;
}


void deletePoz_double(double_listNode *head,int poz) {
    
    ///\brief Remove an element at the position specified in a double_list.
    ///\param head Head of a double_linked_list.
    ///\param value An integer that receive the position of the element to be deleted.
    ///
    /// It deletes the element at the position specified of the list and prints a message with the value deleted.

    
    int iter = 0;
    double_listNode *deletedItem, *current = head;
    poz = poz - 1;
    
    while(iter < poz) {
        current = current->next;
        iter++;
    }
    
    deletedItem = current->next;
    current->next = deletedItem->next;
    if (deletedItem->next != NULL)
        deletedItem->next->prev = current;
    printf("Elementul de pe pozitia %d cu valoare %d a fost sters. \n", poz+1,deletedItem->value);
    free(deletedItem);
}


int count_double(double_listNode *head) {
    
    ///\brief Count the number of elements in a double_list.
    ///\param head Head of a double_linked_list.
    ///
    /// It counts the number of elements in a list and print the number of elements obtained.
    
    double_listNode *current;
    int count = 0;
    
    current = head;
    
    
    while (current->next != NULL) {
        count++;
        current = current->next;
    }
    
    
    return count;
}



void display_double(double_listNode *head) {
    
    ///\brief Display a double_linked_list.
    ///\param head Head of a double_linked_list.
    ///
    /// It displays list's elements if the list is not empty,
    /// Else it prints a message that tell the list is empty.

    
    if(head->next != NULL){
        double_listNode *current;
        int iter = 0;
        current = head;
        printf("Lista contine urmatoarele elemte: \n");
        while (current->next != NULL) {
            iter++;
            current = current->next;
            printf("%d. %d,\n", iter, current->value);
        }
    } else {
        printf("Lista este goala");
    }
    printf("\n");
}


void display_double_back(double_listNode *head) {
    
    ///\brief Display a double_linked_list from end to begin.
    ///\param head Head of a double_linked_list.
    ///
    /// It displays list's elements if the list is not empty,
    /// Else it prints a message that tell the list is empty.
    
    if(head->next != NULL){
        double_listNode *current;
        current = head;
        printf("Lista contine urmatoarele elemte: \n");
        while (current->next != NULL) {
            current = current->next;
        }
        while (current->prev != NULL) {
            printf("%d,\n", current->value);
            current = current->prev;
        }
    } else {
        printf("Lista este goala");
    }
    printf("\n");
}

void merge_double(double_list *list1, double_list *list2) {
    
    ///\brief Merge two double_lists.
    ///\param list1 This parameter takes the adress of the first list.
    ///\param list2 This parameter takes the adress of the second list.
    ///
    /// It takes two double lists as parameters and merge them into single one.
    
    double_listNode *temp;
    
    if (list1->head->next == NULL) {
        list1 = list2;
        return;
    }
    
    if(list2->head->next == NULL) {
        return;
    }
    
    if(list1->head->next == NULL && list2->head->next == NULL) {
        printf("Ambele liste sunt goale");
        return;
        
    }
    
    temp=list1->head;
    while(temp->next!=NULL)
        temp=temp->next;
    temp->next=list2->head->next;
    list2->head->prev = temp;
    
    free(list2->head);
}

