k#include <stdio.h>
#include <stdbool.h>

void main(){

	int nR,nP,o=0,flag=1,flag_1 =0,flag_2=0;
	printf("What is the number of resources?\n");
	scanf("%d",&nR);
	printf("What is the number of processes?\n");
	scanf("%d",&nP);

	int Allocation[nP][nR],maxNeed[nP][nR],remainingNeed[nP][nR],avail[nR],work[nR],seq[nP];
	bool finish[nP];

	printf("Enter the amount of each resource available\n");
	for (int i = 0; i < nR; ++i)
		scanf("%d",&avail[i]);

	printf("Enter the allocation Matrix\n");
	for(int i = 0; i < nP; ++i){
		printf("For process %d:\n", i+1);
		for(int j = 0; j < nR; ++j)
			scanf("%d",&Allocation[i][j]);
	}

	printf("Enter the maxNeed matrix\n");
	for (int i = 0; i < nP; ++i){
		printf("For process %d:\n", i+1);
		for (int j = 0; j < nR; ++j)
			scanf("%d",&maxNeed[i][j]);
	}

	printf("The remainingNeed matrix is\n");
	for (int i = 0; i < nP; ++i){
		printf("For process %d:\t", i+1);
		for (int j = 0; j < nR; ++j)
			printf("%d  ", remainingNeed[i][j] = maxNeed[i][j] - Allocation[i][j]);
		printf("\n");
	}

	for (int i = 0; i < nR; ++i)
		work[i] =avail[i];
	
	for (int i = 0; i < nP; ++i)
		finish[i] = false;

	while(flag){
		int count = 0;

		for (int i = 0; i < nP; ++i){
			flag_1 = 0;
			if (finish[i] == false){
				for (int j = 0; j < nR; ++j){
					if (work[j] < remainingNeed[i][j]){
						flag_1 = 1;
						count++;
						break;
					}
				}
				if(flag_1!=1){
					for (int k = 0; k < nR; ++k)
						work[k] = work[k]+Allocation[i][k];
					finish[i] = true;
					seq[o]=(i + 1);
					o++;
				}
			}
			else {count++;}
		}
		if (count == nP)
			flag = 0;
	}

	for (int i = 0; i < nP; ++i){
		if (finish[i] == false){
			flag_2 = 1;
			break;
		}
	}

	if(flag_2 == 0){
		printf("safe state\n");
		for (int i = 0; i < nP; ++i)
			printf("P%d\t", seq[i]);
	}
	else
		printf("unsafe state\n");

		
}
