#include <stdio.h>
#include <stdlib.h>
struct Process {
    int arrT;
    int BurstT;
    char name[3];
};

int max(int i, int j) {
    if(i >= j) {
        return i;
    } 
    return j;
}
int main() {
    struct Process process[] = {
        {0,4,"p1"},
        {1,2,"p1"},
        {3,4,"p1"},
    };
   
    int StartTime = 0;
    int *CompT = malloc(3 * sizeof(int));
    int *start = malloc(3 * sizeof(int));
    int *TAT = malloc(3 * sizeof(int));
    int *WT = malloc(3 * sizeof(int));
    for(int i = 0; i < sizeof(process) / sizeof(process[0]); i++) {

        start[i] = max(process->arrT, StartTime);
        StartTime += process[i].BurstT;
        
        CompT[i] = StartTime;
        TAT[i] = CompT[i] - process[i].arrT;
        WT[i] = TAT[i] - process[i].BurstT;

    }

    printf("Start Time : ");

    for(int i = 0; i < 3; i++) {
        printf("%d ", start[i]);
    }

    printf("\n");
    printf("============");
    printf("\n");


    printf("Completion Time : ");

    for(int i = 0; i < 3; i++) {
        printf("%d ", CompT[i]);
    }

    printf("\n");
    printf("============");
    printf("\n");

    printf("Turn Around Time : ");

    for(int i = 0; i < 3; i++) {
        printf("%d ", TAT[i]);
    }


    printf("\n");
    printf("============");
    printf("\n");

    printf("Waiting Time : ");

    for(int i = 0; i < 3; i++) {
        printf("%d ", WT[i]);
    }

    if(WT == NULL) {
        return 1;
    }
    free(WT);
    WT = NULL;

    if(TAT == NULL) {
        return 1;
    }
    free(TAT);
    TAT = NULL;

    if(CompT == NULL) {
        return 1;
    }
    free(CompT);
    CompT = NULL;

    
    if(start == NULL) {
        return 1;
    }
    free(start);
    start = NULL;

}
