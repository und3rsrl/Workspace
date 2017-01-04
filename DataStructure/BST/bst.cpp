#include "bst.h"

Node *Add_Node(Node *root,int data)
{//verificam mai intai dacă există o rădăcină (dacă arborele a fost creat)
//Alocam memorie pentru noul nod si stabilim valorile pentru data,left_child,right_child.

    if(root==NULL)
    {   root=(Node *)malloc(sizeof(Node));
        root->data=data;
        root->left=root->right=NULL;
    }
    else if(data <= root->data)
    {
        root->left=Add_Node(root->left,data);//se aseaza in stanga parintelui daca este mai mic
    }
    else {
        root->right=Add_Node(root->right,data);//se aseaza in dreapta parintelui daca este mai mare
    }
    return root;
}

void Display(Node* root, int nivel)
{
	int i;
	if (root != 0)
	{
		Display(root->right, nivel + 1);
		for (i = 0; i <= nivel; i++)
			printf("      ");
		printf("%d\n", root->data);
		Display(root->left, nivel + 1);
	}
}

void preorder (Node *root)//RSD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        //se viziteaza radacina
    printf("\n%d",root->data);
    //se viziteaza copilul din stanga apoi cel din dreapta
    preorder(root->left);
    preorder(root->right);
}
}
void inorder(Node *root) //SRD
{
    //daca nu s-a ajuns la ultimul nod
    if(root!=NULL)
    {
        inorder(root->left);//se viziteaza copilul din stanga
        printf("\n%d",root->data);//se viziteaza radacina
        inorder(root->right);//se viziteaza copilul din dreapta
    }
}
void postorder(Node *root)
{
    if (root!=NULL)//daca nu s-a ajuns la ultimul nod
    {
        postorder(root->left);//se viziteaza copilul din dreapta
        postorder(root->right);//se viziteaza copilul din stanga
        printf("\n%d",root->data);//se viziteaza radacina
    }
}

Node* FindMin(Node* root)
{
	while(root->left != NULL) root = root->left;
	return root;
}
 Node* Delete( Node *root, int data) {
	if(root == NULL) return root;
	else if(data < root->data)
        root->left = Delete(root->left,data);

	else if (data > root->data)
        root->right = Delete(root->right,data);

	else {
		// Cazul 1:
		if(root->left == NULL && root->right == NULL) {
			free(root);
			root = NULL;
		}
		//Cazul 2:
		else if(root->left == NULL) {
			 Node *temp = root;
			root = root->right;
			free(temp);
		}
		else if(root->right == NULL) {
			Node *temp = root;
			root = root->left;
			free(temp);
		}
		// cazul 3:
		else {
			Node *temp = FindMin(root->right);//mergem in dreapta si cautam  nr minim
			root->data = temp->data;
			root->right = Delete(root->right,temp->data);
		}
	}
	return root;
}

void iterative_delete(Node *root, int number) {

    Node *iter = NULL,*tmp = NULL,*tmp2 = NULL,*parent = NULL;
    int lOr = -1;

    iter = root;
    parent = iter;
    while(iter->data != number) {
        if(iter->data > number) {
            parent = iter;
            iter = iter->left;
            lOr = 0;
        }
        else {
            parent = iter;
            iter = iter->right;
            lOr = 1;
        }
    }
    //Case 0
    if(iter->right == NULL && iter->left == NULL) {
        if(iter == root) {
            root = NULL;
            iter = NULL;

            free(root);
        }else {
        free(iter);
        if(lOr)
            parent->right = NULL;
        else
            parent->left = NULL;
        }
    }
    //Case 1
    else if(iter->right == NULL) {
        tmp = iter->left;
        iter->data = iter->left->data;
        iter->right = iter->left->right;
        iter->left = iter->left->right;
        free(tmp);
    }
    else if(iter->left == NULL) {
        tmp = iter->right;
        iter->data = tmp->data;
        iter->right = tmp->right;
        iter->left = tmp->left;
        free(tmp);
    }
    //Case 2&3
    else {
        tmp = iter->right;
        tmp2 = tmp;
        if(tmp->right == NULL && tmp->left == NULL) { // Case 2
            iter->data = tmp->data;
            iter->right = NULL;
            free(tmp);
        }
        else { // Case 3
            while(tmp->left != NULL) {
                tmp2 = tmp;
                tmp = tmp->left;
            }

            iter->data = tmp->data;
            tmp2->left = tmp->right;
            free(tmp);
        }
    }
}
