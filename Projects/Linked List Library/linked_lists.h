//
//  linked_lists.h
//  Project V0.1
//
//  Created by Alexandru Chiurtu on 27/03/16.
//  Copyright © 2016 Alexandru Chiurtu. All rights reserved.
//

#ifndef linked_lists_h
#define linked_lists_h

#include <stdio.h>

//SIMPLE LINKED LISTS

typedef struct simple_listNode{
    int value;
    struct simple_listNode *next;
}simple_listNode;

typedef struct simple_list{
    simple_listNode *head;
}simple_list;

simple_list *simple_list_create();
void init_simple_list(simple_list *list);
void deleteFirst_simple(simple_listNode *head);
void display_simple(simple_listNode *head);
void addFirst_simple (simple_listNode *head, int value);
void addLast_simple(simple_listNode *head, int value);
void addPoz_simple(simple_listNode *head, int value, int poz);
void deletePoz_simple(simple_listNode *head, int poz);
int count_simple(simple_listNode *head);
void merge_simple(simple_list *list1, simple_list *list2);


//DOUBLE LINKED LISTS

typedef struct double_listNode {
    struct double_listNode *prev;
    int value;
    struct double_listNode *next;
}double_listNode;

typedef struct double_list{
    double_listNode *head;
}double_list;

double_list *double_list_create();
void init_double_list(double_list *list);
void addFirst_double(double_listNode *head, int value);
void addLast_double(double_listNode *head, int value);
void addPoz_double(double_listNode *head, int value, int poz);
void deletePoz_double(double_listNode *head,int poz);
int count_double(double_listNode *head);
void display_double(double_listNode *head);
void display_double_back(double_listNode *head);
void merge_double(double_list *list1, double_list *list2);


#endif /* linked_lists_h */
