#include<stdio.h>
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
    Student_t students[1000];
    int studentsCount; 

    printf("Enter number of students:");
    scanf("%d", &studentsCount);

    readStudents(students, studentsCount);
    printStudents(students, studentsCount);

    return 0;
}