#include <stdlib.h>
#include <stdio.h>

typedef struct node
{
	int minX;
	int maxY;
}WT;

void swap(int *xp, int *yp) 
{ 
    int temp = *xp; 
    *xp = *yp; 
    *yp = temp; 
} 

int atMaxChocolate(WT* arr, int numSamples) {
	int maxChoc = arr[0].maxY;
	for(int i=0; i<numSamples; i++) {
		if(maxChoc > arr[i].maxY) {
			maxChoc = arr[i].maxY;
		}
	}
	return maxChoc;
}  

WT* sorting(WT* arr, int numSamples) {
	int i, j, min_idx; 
    for (i = 0; i < numSamples-1; i++) 
    { 
        min_idx = i; 
        for (j = i+1; j < numSamples; j++) 
          if ((float)(arr[j].minX/arr[j].maxY ) < (float)(arr[min_idx].minX/arr[min_idx].maxY))
            min_idx = j; 

        swap(&arr[min_idx].minX, &arr[i].minX); 
        swap(&arr[min_idx].maxY, &arr[i].maxY);
    }
    return arr;
}

int main(int argc, char const *argv[])
{
	int weightSack;
	int numSamples;
	printf("Enter the number of samples..\n");
	scanf("%d", &numSamples);
	WT* sacky = malloc(numSamples * sizeof(WT));
	for(int i=0; i<numSamples; i++) {
		printf("Enter the minimum chocolates for the %dth student\n", (i+1));
		scanf("%d", &sacky[i].minX);
		printf("Enter the minimum chocolates for the %dth student\n", (i+1));
		scanf("%d", &sacky[i].maxY);
	}

	sacky = sorting(sacky, numSamples);
	



	return 0;
}