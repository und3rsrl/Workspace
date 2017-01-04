#include <stdio.h>
#include <stdlib.h>
#include "bst.h"

int main()
{
    Node *root=NULL;
    int i,n,x,value;
    FILE *f;
    f = fopen("numere.txt", "r");
    do{
        printf("\n1.Adauga un nod");
        printf("\n2.Sterge un nod");
        printf("\n3.Preorder");
        printf("\n4.Inorder");
        printf("\n5.Postorder");
        printf("\n6.Arborescenta");
        printf("\n7.Citeste arbore din fisier");
        printf("\n8.Sterge un nod iterativ.");
        printf("\n\nOptiunea dumneavoastra: ");
        scanf("%d",&i);
       switch(i)
       {
           case 1:
            scanf("%d",&n);
           root= Add_Node(root,n);
            break;
           case 2:
            printf("\nAlegeti nodul pe care doriti sa-l stergeti");
            scanf("%d",&x);
            root=Delete(root,x);
            break;
           case 3:
            preorder(root);
            break;
           case 4:
            inorder(root);
            break;
           case 5:
            postorder(root);
            break;
           case 6:
               Display(root, 0);
               break;
           case 7:
                while(fscanf(f, "%d", &value) != EOF){
                    root = Add_Node(root,value);
                }
                break;
           case 8:
                printf("\nAlegeti nodul pe care doriti sa-l stergeti");
                scanf("%d",&x);
                iterative_delete(root,x);
        }
    }while(i);
    return 0;
}
