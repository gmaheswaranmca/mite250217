#include<stdio.h>
#include<string.h>
void readEmployee(int* p_id, char* name, float* p_salary, int* p_attendance) {
    printf("Enter id:");
    scanf("%d", p_id);

    printf("Enter name:");
    scanf("%s", name);

    printf("Enter salary:");
    scanf("%f", p_salary);
    
    printf("Enter number of days worked:");
    scanf("%d", p_attendance);
}

float calculateBonus(float salary, int attendance) {
    float bonus = 0.0f;
    if(attendance > 25) {
        bonus = (salary / 100.0f) * 5.0f;
    } else if(attendance < 10) {
        bonus = (-1.0f * ((salary / 100.0f) * 50.0f));
    }
    return bonus;
}

void categorizeEmployee(char* category, int attendance) {
    if(attendance > 25) {
        strcpy(category, "Excellent");
    } else if(attendance < 15) {
        strcpy(category, "Need Improvement");
    }
}

void printPayroll(int id, char* name, float salary, 
                 float bonus, float gross_salary,
                 char* category) {
    printf("Payroll Details:\n");
    printf("\tId: %d\n", id);
    printf("\tName: %s\n", name);
    printf("\tBasic Salary: %.2f\n", salary);
    if(bonus > 0) {
        printf("\tBonus: %.2f\n", bonus);
    }
    printf("\tFinal Salary: %.2f\n", gross_salary);
    printf("\tEmployee Performance Category: %s\n", category);
}
int main() {
    int id;
    char name[255];
    float salary;
    int attendance;

    //read employee     - 1
    readEmployee(&id, name, &salary, &attendance);

    //process payroll
    float bonus = 0.0f;
    float gross_salary = 0.0f;
    char category[50] = "Good";
    
    //  calculate bonus         -2
    bonus = calculateBonus(salary, attendance);
    //  final salary 
    gross_salary = (salary + bonus);
    //  categorize employee      -3
    categorizeEmployee(category, attendance);

    //display payroll details      -4
    printPayroll(id, name, salary, 
                 bonus, gross_salary, category);
    return 0;
} 
