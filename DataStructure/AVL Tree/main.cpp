#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<time.h>

#include"AVL.h"

int main()
{
	int key,i;
	//char option;

	NodeAVL *root = NULL;
    /*
	FILE *fp = fopen ( "input.txt", "r" );

	if (!fp)
	{
		perror ( "Unable to open file" );
		exit(0);
	}

	while(!feof(fp))
	{
		fscanf(fp, "%c", &option);

		if( option == 'I' )
		{
			fscanf(fp, "%d", &key);
			root = insertAVLNode( root, key );
		}
		else if( option == 'D' )
		{
			fscanf(fp, "%d", &key);
			root = deleteAVLNode( root, key );
		}

	}

	fclose(fp);
	*/

	do{
    printf("\n1.Adauga un nod");
    printf("\n2.Sterge un nod");
	printf("\n3.Arbore");
    printf("\n\nOptiunea dumneavoastra: ");
    scanf("%d",&i);
   switch(i)
   {
   case 1:
    scanf("%d", &key);
    root = insertAVLNode(root, key, 1);
    break;
   case 2:
    printf("\nAlegeti nodul pe care doriti sa-l stergeti");
    scanf("%d", &key);
    root = deleteAVLNode(root, key, 1);
    break;
   case 3:
    displayAVLTree(root,10);
   }
}while(i);
	system("PAUSE");
	return 0;
}
