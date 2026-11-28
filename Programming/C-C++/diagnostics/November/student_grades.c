#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

void display(Student *student_info, int studentCapacity) {
    for(int i = 0; i < studentCapacity; i++) {
        printf("=================================\n");
        printf("student #%d ID : %d\n", i + 1, student_info[i].ID);
        printf("student #%d NAME : %s\n", i + 1, student_info[i].NAME);
        printf("student #%d GRADE : %.2f\n", i + 1, student_info[i].GRADE);
    }
};

void highest(Student *student_info, int studentCapacity) {
    float temp = student_info[0].GRADE;
    int StudentID = 0;
    for(int i = 0; i < studentCapacity; i++) {
        if(student_info[i].GRADE > temp) {
            temp = student_info[i].GRADE;
            StudentID = i;

        }

    }

    printf("Student #%d\n NAME : %s\nGrades : %.2f\nID : %d\n",StudentID + 1, student_info[StudentID].NAME,student_info[StudentID].GRADE,student_info[StudentID].ID );
}
void lowest(Student *student_info, int studentCapacity) {
    float temp = student_info[0].GRADE;
    int StudentID = 0;
    for(int i = 0; i < studentCapacity; i++) {
        if(student_info[i].GRADE < temp) {
            temp = student_info[i].GRADE;
            StudentID = student_info[i-1].ID;

        }

    }

    printf("Student #%d\n NAME : %s\nGrades : %.2f\nID : %d\n",StudentID + 1, student_info[StudentID].NAME,student_info[StudentID].GRADE,student_info[StudentID].ID );
}
int main() {
    
    int studentCapacity;

    printf("Enter Class Size : ");
    scanf("%d", &studentCapacity);
    if(studentCapacity <= 0) {
        printf("Invalid class size\n");
        return 0.0f;
    }
    getchar();
    Student *student_info = malloc(studentCapacity * sizeof(Student));

    for(int i = 0; i < studentCapacity; i++) {
        student_info[i].ID = i + 1;
        printf("Enter Student #%d Name: ", i + 1);

        if(fgets(student_info[i].NAME, sizeof(student_info[i].NAME), stdin) == NULL) {
            i--;
            break;
        }

        student_info[i].NAME[strcspn(student_info[i].NAME, "\n")] = '\0';

        printf("Enter Student #%d Grade : ", i + 1);
        scanf(" %f", &student_info[i].GRADE);
    getchar();
    }

    float StudentAverage = average(student_info, studentCapacity);
    
    display(student_info, studentCapacity);

    printf("The total Grade average of the student is : %.2f\n", StudentAverage);
    highest(student_info,studentCapacity);
    lowest(student_info,studentCapacity);
    if(student_info == NULL) return 1;

    free(student_info);
    student_info = NULL;
    return 0;
}
