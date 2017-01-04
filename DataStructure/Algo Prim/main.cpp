#include "Prim.h"
#include "Graph.h"

int main(){
//-----------------------------------------Loading and Printing the Graph------------------------------
	graph *G;

	FILE* f;
	f = fopen("cost.txt", "r");
	G = loadGraph(f);

	printf("\n Edges and Costs: \n");

	for(int i = 0; i < G->noOfEdges; i++){
		printf("[%d <-> %d] --- cost = %d \n", G->pEdge[i].source , G->pEdge[i].destination, G->pEdge[i].weight);
	}
	printf("\n");
//------------------------------------------------END---------------------------------------------------
//-----------------------------------------------PRIM---------------------------------------------------

	int V[50][50], Q[50], H[50], n = G->noOfVertices, r = 0, k=0;			//----|  Data for Prim's Alg
	// ce reprezinta???

    for(int i = 1; i <= n; i++) {

        k = prim(V, Q, H, n, i, G);

        printf("For vertex no. %d we have:\n", i);

        displayMST(H, n);

        printf("\n MST cost = %d \n\n", k);

    }
//-----------------------------------------------END------------------------------------------------------
//---------------------------------------------Kruskall---------------------------------------------------
/*
	int p, m, L[20];										//----|  Data for Kruskall's Alg

	krusk(n, m, L, G);
//-----------------------------------------------END-----------------------------------------------------
*/
	system("pause");

}
