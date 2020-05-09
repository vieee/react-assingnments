#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    int test_case;
    printf("Enter the number of test cases..: ");
    scanf("%d", &test_case);
    while(test_case-- > 0) {
        int N;
        printf("Enter the number of toll booths in the way..: ");
        scanf("%d", &N);
        int* A = (int*) malloc(N * sizeof(int));
        int* B = (int*) malloc(N * sizeof(int));
        int* Atrav = (int*) malloc((N-1) * sizeof(int));
        int* Btrav = (int*) malloc((N-1) * sizeof(int));
        printf("Enter the costs of toll in Iron Man's path..: \n");
        for (int i = 0; i < N; i++) {
            scanf("%d", (A+i));
        }
        printf("Enter the costs of toll in Captain America's path..: \n");
        for (int i = 0; i < N; i++) {
            scanf("%d", (B+i));
        }
        printf("Enter the costs of toll in Iron Man's path to change routes..: \n");
        for (int i = 0; i < (N-1); i++) {
            scanf("%d", (Atrav+i));
        }
        printf("Enter the costs of toll in Captain America's path to change routes..: \n");
        for (int i = 0; i < (N-1); i++) {
            scanf("%d", (Btrav+i));
        }
        int* Aroute = (int*) malloc(N * sizeof(int));
        int* Broute = (int*) malloc(N * sizeof(int));
        int* line1 = (int*) malloc((N-1) * sizeof(int));
        int* line2 = (int*) malloc((N-1) * sizeof(int));
        Aroute[0] = A[0];
        Broute[0] = B[0];


        for (int i = 1; i < N; i++) {
            if(Aroute[i - 1] <= Broute[i - 1] + Btrav[i - 1]) {
                Aroute[i] = Aroute[i - 1] + A[i];
                line1[i - 1] = 1;
            }
            else {
                Aroute[i] = Broute[i - 1] + Btrav[i - 1] + A[i];
                line1[i - 1] = 2;
            }

            if(Broute[i - 1] <= Aroute[i - 1] + Atrav[i - 1]) {
                Broute[i] = Broute[i - 1] + B[i];
                line2[i - 1] = 2;
            }
            else {
                Broute[i] = Aroute[i - 1] + Atrav[i - 1] + B[i];
                line2[i - 1] = 1;
            }
        }
        int finale, last;
        if(Aroute[N - 1] > Broute[N - 1]) {
            last = 2;
            finale = Broute[N - 1];
        }
        else {
            last = 1;
            finale = Aroute[N - 1];
        }
        printf("The least toll incurral possible is..:- %d\n The path is..\n", finale);
        printf("%d station -> %dth line\n",N, last);
        for (int i = N-2; i >= 0; i--) {
            if(last == 1) {
            printf("%d station -> %dth line\n",i+1, line1[i]);
            last = line1[i];
        }
        else {
            printf("%d station -> %dth line\n",i+1, line2[i]);
            last = line2[i];
        }
        }
        
    }
    return 0;
}
