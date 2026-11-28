#include <stdio.h>
#include <stdlib.h>
typedef struct  {
    int ID;
    char NAME[64];
    float GRADE;
}Student;

float average(Student *student_info, int studentCapacity) {
    float totalsum = 0;

    for(int i = 0; i < studentCapacity; i++) {
        totalsum += student_info[i].GRADE;
    }

    
    return (totalsum / studentCapacity) ;
}
int main() {
    
    int studentCapacity;

    printf("Enter Class Size : ");
    scanf("%d", &studentCapacity);
    Student *student_info = malloc(studentCapacity * sizeof(Student));

    for(int i = 0; i < studentCapacity; i++) {
        student_info[i].ID = i + 1;
        printf("Enter Student #%d Name: ", i + 1);

        if(fgets(student_info[i].NAME, 64, stdin) == NULL) {
            i--;
            break;
        }


        while (getchar() != '\n');
        printf("Enter Student #%d Grade : ", i + 1);
        scanf(" %f", &student_info[i].GRADE);
    }

    float StudentAverage = average(student_info, studentCapacity);

    printf("The total Grade average of the student is : %.2f", StudentAverage);

    return 0;
}
