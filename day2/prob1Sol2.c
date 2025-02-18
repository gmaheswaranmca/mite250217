#include<stdio.h>
void inputMarks(int* marks, int n) {
    printf("Enter marks:");
    for(int I = 0; I < n; I++) {
        scanf("%d", &marks[I]);
    }
}

float calculateAverage(int *marks, int n) {
    float average;
    int sum = 0;
    for(int I = 0; I < n; I++) {
        sum += marks[I];
    }
    average = (float)sum / (float)n;
    return average;
}

int main() {
    int marks[1000];
    int n;
    printf("Enter number of students:");
    scanf("%d", &n);

    inputMarks(marks, n);
    float average = calculateAverage(marks, n);
    printf("Average marks:%.2f\n", average);
    return 0;
}