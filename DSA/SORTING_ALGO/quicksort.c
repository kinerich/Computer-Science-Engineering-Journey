#include <stdio.h>
#include <stdlib.h>

int partition(int *lists, int start, int end) {
    int i = -1;
    for(int j = 0; j < end; j++) {
        if(lists[j] <= lists[end]) {
            i++;
            int temp = lists[j];
            lists[j] = lists[i];
            lists[i] = temp;
        }
    }
    int temp = lists[end];
    lists[end] = lists[i+1];
    lists[i+1] = temp;

    return i + 1;
}

void quicksort(int *lists, int start, int end) {
    if(start >= end) return;

   int pivot = partition(lists, start, end);

   quicksort(lists, start, pivot - 1);
   quicksort(lists, pivot + 1, end);
}



int main() {
    int size = 0;
    printf("Enter Size : ");
    scanf("%d", &size);
    
    int *lists = malloc(size * sizeof(int));

     
    for(int i = 0; i < size; i++) {
        printf("Enter number : ");
        scanf("%d", &lists[i]);
    }

    for(int i = 0; i < size; i++) {
        printf("%d ", lists[i]);
    }

    printf("\n");

    quicksort(lists, 0, size - 1);

    printf("========================\n");

    for(int i = 0; i < size; i++) {
        printf("%d ", lists[i]);
    }
    
    printf("\n");

    if(lists == NULL) return 1;
    free(lists);
    lists = NULL;
    
    return 0;
};
