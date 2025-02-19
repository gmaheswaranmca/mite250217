#include<stdio.h>
#include<stdlib.h>
struct Student {
    char name[255];
    int marks;
};

typedef struct Student Student_t;

void readStudents(Student_t* students, int length) {
    for(int I = 0; I < length; I++) {
        printf("Student %d Name:", I + 1);
        scanf("%s", students[I].name);
        printf("Student marks:");
        scanf("%d", &students[I].marks);
    }
}

void printStudents(Student_t* students, int length) {
    printf("Student Records:\n");
    for(int I = 0; I < length; I++) {
        printf("%s - %d\n", students[I].name, students[I].marks);
    }
}
int main() {
    
    int studentsCount; 

    printf("Enter number of students:");
    scanf("%d", &studentsCount);

    Student_t* students = NULL;//no-wild
    students = (Student_t*)malloc(sizeof(Student_t) * studentsCount);//Student_t students[1000];

    readStudents(students, studentsCount);
    printStudents(students, studentsCount);

    free(students);//dangling pointer
    students = NULL;//no dangling
    //printf("%s",students[0].name);
    return 0;
}