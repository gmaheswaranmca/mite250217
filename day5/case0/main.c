#include<stdio.h>
#include "Employee.h"
#include "stack.h"
void readEmployees(Employee emp[], int n);
void displayEmployees(Employee emp[], int n);
void displayEmployeesUsingStack(Employee emp[], int n);
void manageEmployees();
int main() {    
    manageEmployees(); 
    return 0;
}
void manageEmployees() {
    int employeeCount;    
    Employee employees[1000];    
    int choice;
    do {
        printf("Choices:\n");
        printf("1-Read Employees\n");
        printf("2-Display Employees\n");
        printf("3-Display Employees using Stack\n");
        printf("91-Exit\n");
        printf("Your Choice:");
        scanf("%d",&choice);
        switch(choice) {
            case 1: {                
                printf("Enter number of employees:");
                scanf("%d", &employeeCount);
                readEmployees(employees, employeeCount);
            }  break;
            case 2: {
                displayEmployees(employees, employeeCount);    
            } break;
            case 3: {
                displayEmployeesUsingStack(employees, employeeCount);    
            } break;
            case 91: {
                printf("Thank you for using app...\n");
            } break;
        }
    } while(choice != 91);
}
void readEmployees(Employee emp[], int n) {
    printf("Enter details (ID, Name, Salary, Department):\n");
    for(int I = 0; I < n; I++) {
        scanf("%d%s%f%s", &emp[I].id, emp[I].name, 
                          &emp[I].salary, emp[I].department);
    }
}
void displayEmployees(Employee emp[], int n) {
    printf("--------------------------------------------------------------------\n");
    printf("|%5s|%-20s|%8s|%10s|\n", "ID", "Name", "Salary", "Department");
    printf("--------------------------------------------------------------------\n");
    for(int I = 0; I < n; I++) {
        printf("|%5d|%-20s|%8.2f|%10s|\n", emp[I].id, emp[I].name, 
                                emp[I].salary, emp[I].department);
    }
    printf("--------------------------------------------------------------------\n");
}

void displayEmployeesUsingStack(Employee emp[], int n) {
    Stack stk;
    StackInit(&stk);
    for(int I = 0; I < n; I++) {
        StackPush(&stk, emp[I]);
    }
    printf("--------------------------------------------------------------------\n");
    printf("|%5s|%-20s|%8s|%10s|\n", "ID", "Name", "Salary", "Department");
    printf("--------------------------------------------------------------------\n");
    while(!StackEmpty(&stk)) {
        Employee employee = StackTop(&stk); 
        printf("|%5d|%-20s|%8.2f|%10s|\n", employee.id, employee.name, 
            employee.salary, employee.department);
        StackPop(&stk);
    }
    printf("--------------------------------------------------------------------\n");
}