#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void reverse(int *number, int n, int *temp) {
    int j = 0;
    for(int i = n - 1; i >= 0; i--) {
       temp[i] = number[j];  
        j++;
    }

        printf("Reversed : ");
    for(int i = 0; i < n; i++) {
        printf("%d", temp[i]);
    }
}
bool palindrome(int *number, int n, int *temp) {
    bool checker = true; 
    int i = 0;
    for(int j = 0; j < n; j++) {
        if(number[j] != temp[i]) {
           checker = false; 
        }
        i++;
    }

    return checker;
}
int main() {

    int n = 0;
    printf("Enter Size : ");
    scanf("%d", &n);

    int *number = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) {
        printf("Enter Number : ");
        scanf("%d", &number[i]);
    }

    int *temp = malloc(n * sizeof(int));
    
   reverse(number, n, temp); 

    if(palindrome(number, n, temp)) {
        printf("True");

    }else {
        printf("False");
    }



    if(temp == NULL) {
        return 1;
    }
    free(temp);
    temp = NULL;
    //----------------------------------------
    if(number == NULL) {
        return 1;
    }
    free(number);
    number = NULL;

}
