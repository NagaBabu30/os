#include <stdio.h>

struct Employee { int id; char name[50]; float salary; };

int main() {
    struct Employee emp;
    FILE *f = fopen("employees.dat", "ab");
    printf("ID: "); scanf("%d", &emp.id);
    printf("Name: "); scanf("%s", emp.name);
    printf("Salary: "); scanf("%f", &emp.salary);
    fwrite(&emp, sizeof(emp), 1, f);
    fclose(f);
    return 0;
}


