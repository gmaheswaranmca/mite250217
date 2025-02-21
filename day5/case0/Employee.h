#ifndef EMPLOYEE_HEADER
#define EMPLOYEE_HEADER
struct Employee_t {
    int id;
    char name[255];
    float salary;
    char department[50];
};
typedef struct Employee_t Employee;
#endif

