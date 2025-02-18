#include<stdio.h>
void readDetails(float* p_salary, int* p_score, int* p_experience) {
    printf("Enter Salary:");
    scanf("%f", p_salary);

    printf("Enter Credit Score:");
    scanf("%d", p_score);

    printf("Enter Experience:");
    scanf("%d", p_experience); 
}

int isEligible(float salary, int score, int experience) {
    return ((salary >= 30000) && (score >= 750) && (experience >= 2));
}

void doTask() {
    float salary;
    int score;
    int experience;
    readDetails(&salary, &score, &experience);
    if(isEligible(salary, score, experience)) {
        printf("Loan Approved\n");
    }
    else {
        printf("Loan Rejected\n");
    }
}

int main() {
    int choice;
    do {
        doTask();        
        printf("Are you sure to continue(1-continue, 0-exit)?");
        scanf("%d", &choice);
    }while(1 == choice);

    return 0;
}