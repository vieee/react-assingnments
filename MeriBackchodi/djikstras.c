#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>


typedef struct Graph {
    int vertices;
    int edges;
    int** adjM;
}GRAPH;

typedef struct PriorityQueue {
    int* distances;
    int* vertices;
    int* parents;
    int count;
}HEAP;

int leftChild(HEAP* heap, int i) {
	int left = (2 * i + 1);
	if(left >= heap->count) 
		return -1;
	
	return left;
}

int rightChild(HEAP* heap, int i) {
	int left = (2 * i + 2);
	if(left >= heap->count) 
		return -1;
	
	return left;
}

int parent(HEAP* heap, int i) {
	if(i <= 0 || i >= heap->count) {
		return -1;
	}
	return (i-1)/2;
}

void printInitials(HEAP* array, int num) {
	for (int i = 0; i < num; ++i) 
    {
		printf("%c -> %d\n", (char) (array->vertices[i] + 1), array->distances[i]);
	}
}

void min_heapify(HEAP* heap, int i) {
	int l = leftChild(heap, i);
	int r = rightChild(heap, i);
	int smallest, temp;

	if(l != -1 && heap->distances[l] < heap->distances[i]) {
		smallest = l;
	}
	else {
		smallest = i;
	}

	if(r != -1 && heap->distances[r] < heap->distances[smallest]) {
		smallest = r;
	}
	if(smallest != i) {
		temp = heap->distances[i];
		heap->distances[i] = heap->distances[smallest];
		heap->distances[smallest] = temp;

		temp = heap->vertices[i];
		heap->vertices[i] = heap->vertices[smallest];
		heap->vertices[smallest] = temp;

		temp = heap->parents[i];
		heap->parents[i] = heap->parents[smallest];
		heap->parents[smallest] = temp;

	}
	min_heapify(heap, smallest);
	
}

int extractMin(HEAP* heap) {
	int data;
	int maalik;
	int papa;
	if(heap->count == 0)
		return -1;
	
	data = heap->distances[0];
	maalik = heap->vertices[0];
	papa = heap->parents[0];
	heap->distances[0] = heap->distances[heap->count - 1];
	heap->vertices[0] = heap->vertices[heap->count - 1];
	heap->parents[0] = heap->parents[heap->count - 1];
	heap->count --;
	min_heapify(heap, 0);


    return maalik;
}

void build_min_heap(HEAP* heap) {
	int n = heap->count;
	for(int i=floor(n/2); i>=1; i--)
	{
		min_heapify(heap, i);
	}
    
}


void Djikstras(GRAPH* graph, int source) {

    HEAP* heap = (HEAP*) malloc(sizeof(HEAP));
    heap->distances = (int*) malloc(graph->vertices * sizeof(int));
    heap->vertices = (int*) malloc(graph->vertices * sizeof(int));
    heap->parents = (int*) malloc(graph->vertices * sizeof(int));
    for (int i = 0; i < graph->vertices; i++)
    {
        heap->distances[i] = 100;
        heap->vertices[i] = i;
        heap->parents[i] = -1;
    }
    heap->count = graph->vertices;
    heap->distances[source] = 0;
    build_min_heap(heap);

    int v, w, new_distance;
    while (heap->count > 0) {
        v = extractMin(heap);
        for (int i = 0; i < heap->count && graph->adjM[v][i] > 0; i++)
        {
            new_distance = heap->distances[v] + graph->adjM[v][i];
            if (heap->distances[i] > new_distance && heap->vertices[i] == i) {
                heap->distances[i] = new_distance;
                heap->parents[i] = v;
                build_min_heap(heap);
            }
            

        }
        

    }
    
    printf("Finally the nearest distances from the source %c are..:-\n",(char)(source + 65));
    printInitials(heap, graph->vertices);
    



}

int main(int argc, char const *argv[])
{
    int VTot, ETot;
    int xHold, yHold, wHold;
	printf("Enter the number of vertices and edges respectively..\n");
	scanf("%d %d", &VTot, &ETot);

    GRAPH* initialTree = (GRAPH*) malloc(sizeof(GRAPH));
    initialTree->edges = ETot;
    initialTree->vertices = VTot;

    initialTree->adjM = (int**) malloc(VTot * sizeof(int*));
    for (int i = 0; i < VTot; i++)
    {
        initialTree->adjM[i] = (int*) calloc(VTot, sizeof(int));
    }
    printf("Enter the edges detailed up..(0 - %d) for %d vertices\n\n", VTot-1, VTot);
    for (int i = 0; i < ETot; i++)
    {
        printf("For %dth edge:-\n", (i+1));
        printf("Initial vertex..: ");
        scanf("%d", &xHold);
        printf("Final vertex..: ");
        scanf("%d", &yHold);
        printf("Edge Weight..: ");
        scanf("%d", &wHold);

        initialTree->adjM[xHold][yHold] = wHold;
        initialTree->adjM[yHold][xHold] = wHold;

    }
    printf("Enter the source vertex..\n");
    int num;
    scanf("%d", &num);
    Djikstras(initialTree, num);

    return 0;
}

