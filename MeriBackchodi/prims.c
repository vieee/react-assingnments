#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <stdbool.h>
#include <limits.h>


typedef struct vertex
{
	int name;
	int score;
	int* array;
}VERTEX;

typedef struct edge 
{
	int source;
	int dest;
	int weight;
}EDGE;

typedef struct finalG
{
	int points;
	int** adjointMatrix;
}MST;

typedef struct heapM
{
	int* scores;
	int* owner;
	int* parent;
	int** adjMat;
	int count;
}HEAPM;


int leftChild(HEAPM* heap, int i) {
	int left = (2 * i + 1);
	if(left >= heap->count) 
		return -1;
	
	return left;
}

int rightChild(HEAPM* heap, int i) {
	int left = (2 * i + 2);
	if(left >= heap->count) 
		return -1;
	
	return left;
}

int parent(HEAPM* heap, int i) {
	if(i <= 0 || i >= heap->count) {
		return -1;
	}
	return (i-1)/2;
}

void printInitials(int* array, int num) {
	for (int i = 0; i < num; ++i)
	{
		if (array[i] > 0)
		{
			printf("%c  ", (i + 65));
		}
	}
	printf("\n");
}

void min_heapify(HEAPM* heap, int i) {
	int l = leftChild(heap, i);
	int r = rightChild(heap, i);
	int smallest, temp;

	if(l != -1 && heap->scores[l] < heap->scores[i])
	{
		smallest = l;
	}
	else
	{
		smallest = i;
	}


	if(r != -1 && heap->scores[r] < heap->scores[smallest])
	{
		smallest = r;
	}
	if(smallest != i) 
	{
		temp = heap->scores[i];
		heap->scores[i] = heap->scores[smallest];
		heap->scores[smallest] = temp;

		temp = heap->owner[i];
		heap->owner[i] = heap->owner[smallest];
		heap->owner[smallest] = temp;

		temp = heap->parent[i];
		heap->parent[i] = heap->parent[smallest];
		heap->parent[smallest] = temp;

		int* array = heap->adjMat[i];
		heap->adjMat[i] = heap->adjMat[smallest];
		heap->adjMat[smallest] = array;
	}
	min_heapify(heap, smallest);
	
}


void extractMin(HEAPM* heap, MST* mst) {
	int data;
	int maalik;
	int papa;
	if(heap->count == 0)
		return;
	
	data = heap->scores[0];
	maalik = heap->owner[0];
	papa = heap->parent[0];
	heap->scores[0] = heap->scores[heap->count - 1];
	heap->owner[0] = heap->owner[heap->count - 1];
	heap->parent[0] = heap->parent[heap->count - 1];
	heap->adjMat[0] = heap->adjMat[heap->count - 1];
	heap->count --;
	min_heapify(heap, 0);

	mst->adjointMatrix[papa][maalik - 1] = data;
	mst->adjointMatrix[maalik - 1][papa] = data;
	
	

}

void build_min_heap(HEAPM* heap) {
	int n = heap->count;
	for(int i=floor(n/2); i>=1; i--)
	{
		min_heapify(heap, i);
	}
}

void decreaseKey(HEAPM* heap, int i, int value, int newParent) {
	heap->scores[i] = value;
	heap->parent[i] = newParent;

	build_min_heap(heap);

}

bool checkTerm(HEAPM* heap, int vert) {
	for (int i = 0; i < heap->count; i++)
	{
		if(heap->owner[i] == (vert + 1))
			return true;
	}
	return false;
}

void Prims(HEAPM* heap, int count, MST* mst) {
	heap->scores[0] = 0;
	heap->owner[0] = 1;
	heap->parent[0] = 0;
	int minOwner;
	bool flag = false;
	for (int i = 1; i < count; ++i)
	{
		heap->scores[i] = INT_MAX;
		heap->parent[i] = -1;
		heap->owner[i] = (i+1);
	}
	

	while(heap->count != 0) {
		minOwner = heap->owner[0];
		if (flag == true)
		{
			extractMin(heap, mst);
		}
		flag = true;
		
		for (int i = 0; i < count && heap->adjMat[minOwner - 1][i] > 0; i++)
		{
			if(checkTerm(heap, i) && heap->adjMat[minOwner - 1][i] < heap->scores[i]) {
				heap->parent[i] = (minOwner - 1);
				decreaseKey(heap, i, heap->adjMat[minOwner - 1][i], minOwner);
			}
		}
		
		
	}




}



void main()
{
	int numTot;
	printf("Enter the number of vertices..\n");
	scanf("%d", &numTot);

	MST* tree1;
	tree1 = (MST*) malloc(sizeof(MST));
	tree1->points = numTot;
	tree1->adjointMatrix = (int**) malloc(numTot * sizeof(int*));
	for (int i = 0; i < numTot; i++)
	{
		tree1->adjointMatrix[i] = (int*) malloc(numTot * sizeof(int));
	}
	
	
	VERTEX* setVertex;
	setVertex = (VERTEX*) malloc(numTot * sizeof(VERTEX));
	for (int i = 0; i < numTot; ++i)
	{
		setVertex[i].name = (i+1);
		setVertex[i].score = 0;
		setVertex[i].array = (int*) calloc(numTot, sizeof(int));
	}

	printf("Enter the number of edges..\n");
	int edgeTot;
	scanf("%d", &edgeTot);

	EDGE* setEdge;
	setEdge = (EDGE*) malloc(edgeTot * sizeof(EDGE));
	for (int i = 0; i < edgeTot; ++i)
	{
		printf("Enter the start edge number %d..\n", (i+1));
		scanf("%d" ,&setEdge[i].source);
		printf("Enter the end edge number %d..\n", (i+1));
		scanf("%d" ,&setEdge[i].dest);
		printf("Enter the edge weight..\n");
		scanf("%d" ,&setEdge[i].weight);

		setVertex[(setEdge[i].source - 1)].array[setEdge[i].dest - 1] = setEdge[i].weight;
		setVertex[(setEdge[i].dest - 1)].array[setEdge[i].source - 1] = setEdge[i].weight;	

	}

	printf("The initial tree is...\n\n");
	for (int i = 0; i < numTot; ++i)
	{
		printf("%c -> ", (setVertex[i].name + 64));
		printInitials(setVertex[i].array, numTot);

	}
	printf("\n\n");


	HEAPM* heap;
	heap = (HEAPM*) malloc(sizeof(HEAPM));
	heap->scores = malloc(numTot * sizeof(int));
	heap->owner = malloc(numTot * sizeof(int));
	heap->parent = malloc(numTot * sizeof(int));
	heap->adjMat = malloc(numTot * sizeof(int*));
	for (int i = 0; i < numTot; i++)
	{
		heap->adjMat[i] = malloc(numTot * sizeof(int));
		for (int j = 0; j < numTot; j++)
		{
			heap->adjMat[i][j] = setVertex[i].array[j];
		}
		
	}
	
	heap->count = numTot;

	printf("Implementing the Prims Algorithm..:\n\n");
	Prims(heap, numTot, tree1);

	printf("Final Minimum-Spanning-Tree is..:\n");
	for (int i = 0; i < numTot; ++i)
	{
		printf("%c -> ", (i + 65));
		printInitials(tree1->adjointMatrix[i], numTot);

	}
	printf("\n\n");



}
