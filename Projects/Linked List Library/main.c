//
//  main.c
//  PT_Project
//
//  Created by Alexandru Chiurtu on 20/05/16.
//  Copyright © 2016 Alexandru Chiurtu. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "linked_lists.h"

int main(int argc, const char * argv[]) {



    FILE *test1, *test2, *deletePoz, *addPoz;
    int buffer, poz, value;

    // Simple Linked List
    //      Tests

    printf("SIMPLE LINKED LIST  TEST\n");
    printf("\n\n");

    // Test 1 - Inserting test
    printf("Test 1 - Inserting test\n");
    printf("\n\n");
    //Users/alexandruchiurtu/Desktop/Workspace/Linked_Lists Project/Linked_Lists Project/test.txt
    test1 = fopen("test.txt", "r");
    //Users/alexandruchiurtu/Desktop/Workspace/Linked_Lists Project/Linked_Lists Project/test1.txt
    test2 = fopen("test1.txt", "r");

    // Create, read elements from file and test addFirst_simple() function
    printf("LIST 1:\n");
    printf("\n\n");
    simple_list list1 = *simple_list_create();
    init_simple_list(&list1);

    while (fscanf(test1, "%d", &buffer) != EOF) {
        addFirst_simple(list1.head, buffer);
    }


    display_simple(list1.head);
    printf("\n");
    count_simple(list1.head);
    printf("\n");

    printf("\n\n");
    // Create, read elements from file and test addLast_simple() function
    printf("LIST 2:\n");
    printf("\n\n");
    simple_list list2 = *simple_list_create();
    init_simple_list(&list2);

    while (fscanf(test2, "%d", &buffer) != EOF) {
        addLast_simple(list2.head, buffer);
    }

    display_simple(list2.head);
    printf("\n");
    count_simple(list2.head);
    printf("\n");


    fclose(test1);
    fclose(test2);

    // TEST 2 - Delete and Insert at given position
    printf("\n\n");
    printf("TEST 2 - Delete and Insert at given position\n");
    printf("\n\n");
    // Add at given position test
    //Users/alexandruchiurtu/Desktop/Workspace/Linked_Lists Project/Linked_Lists Project/addPoz.txt
    addPoz = fopen("addPoz.txt", "r");

    while (fscanf(addPoz, "%d %d", &poz, &value) != EOF) {
        addPoz_simple(list1.head, value, poz);
    }

    fclose(addPoz);

    display_simple(list1.head);

    // Delete at given position test
    //Users/alexandruchiurtu/Desktop/Workspace/Linked_Lists Project/Linked_Lists Project/deletePoz.txt
    deletePoz = fopen("deletePoz.txt", "r");

    while (fscanf(deletePoz, "%d", &poz) != EOF) {
        deletePoz_simple(list1.head, poz);
    }

    fclose(deletePoz);

    //display_simple(list1.head);
    // TEST 3 - Merging two list
    printf("\n\n");
    printf("TEST 3 - Merging two list\n");
    printf("\n\n");
    merge_simple(&list1, &list2);
    display_simple(list1.head);


    // Double Linked List
    //      Tests
    printf("DOUBLE LINKED LIST  TEST\n");
    printf("\n\n");
    // Test 1 - Inserting test
    printf("Test 1 - Inserting test\n");
    printf("\n\n");
    //Users/alexandruchiurtu/Desktop/Workspace/Linked_Lists Project/Linked_Lists Project/test.txt
    test1 = fopen("test.txt", "r");
    //Users/alexandruchiurtu/Desktop/Workspace/Linked_Lists Project/Linked_Lists Project/test1.txt
    test2 = fopen("test1.txt", "r");

    // Create, read elements from file and test addFirst_simple() function
    printf("LIST 1:\n");
    printf("\n\n");
    double_list list3 = *double_list_create();
    init_double_list(&list3);

    while (fscanf(test1, "%d", &buffer) != EOF) {
        addFirst_double(list3.head, buffer);
    }


     display_double(list3.head);
     printf("\n");
     count_double(list3.head);
     printf("\n");


    // Create, read elements from file and test addLast_simple() function
    printf("LIST 2:\n");
    printf("\n\n");
    double_list list4 = *double_list_create();
    init_double_list(&list4);

    while (fscanf(test2, "%d", &buffer) != EOF) {
        addLast_double(list4.head, buffer);
    }


     display_double_back(list4.head);
     printf("\n");
     count_double(list4.head);
     printf("\n");


    fclose(test1);
    fclose(test2);

    // TEST 2 - Delete and Insert at given position
    printf("\n\n");
    printf("TEST 2 - Delete and Insert at given position\n");
    printf("\n\n");
    // Add at given position test
    addPoz = fopen("addPoz.txt", "r");

    while (fscanf(addPoz, "%d %d", &poz, &value) != EOF) {
        addPoz_double(list3.head, value, poz);
    }

    fclose(addPoz);


    display_double(list3.head);

    // Delete at given position test

    deletePoz = fopen("deletePoz.txt", "r");

    while (fscanf(deletePoz, "%d %d", &poz, &value) != EOF) {
        deletePoz_double(list3.head, poz);
    }

    fclose(deletePoz);

    display_double(list3.head);

    // TEST 3 - Merging two list
    printf("\n\n");
    printf("TEST 3 - Merging two list\n");
    printf("\n\n");
    merge_double(&list3, &list4);
    display_double(list3.head);
    display_double_back(list3.head);


    return 0;
}
