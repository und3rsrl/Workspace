#ifndef _AVL_H_
#define _AVL_H_

#include<stdio.h>
#include<stdlib.h>

struct NodeAVL{
	int key;
	int echi;
	NodeAVL *left, *right;
};

int max( int a, int b);
int maxPathLength(NodeAVL *p);
void computeBalanceFactor (NodeAVL *p);
NodeAVL* leftRot (NodeAVL *p);
NodeAVL* rightRot (NodeAVL *p);
NodeAVL* doubleLeftRot (NodeAVL *p);
NodeAVL* doubleRightRot (NodeAVL *p);
NodeAVL* balance (NodeAVL *p,int level);
NodeAVL* insertAVLNode (NodeAVL *p, int x,int level);
NodeAVL* deleteAVLNode (NodeAVL *p, int x,int level);
void displayAVLTree (NodeAVL *p, int level);

#endif
