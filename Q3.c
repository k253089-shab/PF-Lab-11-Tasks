#include <stdio.h>
#include <string.h>

struct Date {
    int day, month, year;
};

struct Employee {
    int id;
    char name[50];
    char department[20];
    char designation[20];
    float salary;
    char phone[15];
    char email[40];
    struct Date joiningDate;
};

int calculateExperience(struct Employee e) {
    int currentYear = 2025;
    return currentYear - e.joiningDate.year;
}

void salaryByDepartment(struct Employee e[], int n) {
    float total;
    int count;

    char depts[5][20] = {"IT", "HR", "Finance", "Marketing", "Operations"};

    for(int d = 0; d < 5; d++) {
        total = 0;
        count = 0;

        for(int i = 0; i < n; i++) {
            if(strcmp(e[i].department, depts[d]) == 0) {
                total += e[i].salary;
                count++;
            }
        }

        if(count > 0)
            printf("\n%s Dept Avg Salary: %.2f", depts[d], total / count);
    }
}

void annualAppraisal(struct Employee *e) {
    float percent;
    printf("Enter performance increment percentage (5-15): ");
    scanf("%f", &percent);

    if(percent < 5 || percent > 15) {
        printf("Invalid percentage!\n");
        return;
    }

    e->salary += e->salary * (percent / 100.0);
    printf("Updated Salary: %.2f\n", e->salary);
}

void searchEmployees(struct Employee e[], int n) {
    int choice, exp;

    printf("\n1. Search by Department");
    printf("\n2. Search by Designation");
    printf("\n3. Search by Experience");
    printf("\nEnter choice: ");
    scanf("%d", &choice);

    if(choice == 1) {
        char dept[20];
        printf("Enter department: ");
        scanf("%s", dept);

        for(int i = 0; i < n; i++)
            if(strcmp(e[i].department, dept) == 0)
                printf("\n%s  %s  %.2f", e[i].name, e[i].designation, e[i].salary);
    }

    else if(choice == 2) {
        char desig[20];
        printf("Enter designation: ");
        scanf("%s", desig);

        for(int i = 0; i < n; i++)
            if(strcmp(e[i].designation, desig) == 0)
                printf("\n%s  %s  %.2f", e[i].name, e[i].department, e[i].salary);
    }

    else if(choice == 3) {
        printf("Enter minimum experience (years): ");
        scanf("%d", &exp);

        for(int i = 0; i < n; i++)
            if(calculateExperience(e[i]) >= exp)
                printf("\n%s  %s  %d yrs", e[i].name, e[i].designation,
                       calculateExperience(e[i]));
    }
}

void promotionEligible(struct Employee e[], int n) {
    printf("\nEligible for Promotion (> 3 years):\n");

    for(int i = 0; i < n; i++) {
        if(calculateExperience(e[i]) > 3) {
            printf("\n%s  %s  %d years",
                   e[i].name,
                   e[i].designation,
                   calculateExperience(e[i]));
        }
    }
}

int main() {
    struct Employee e[100];
    int n, choice, id;

    printf("Enter number of employees: ");
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        printf("\nEmployee %d\n", i + 1);

        printf("ID: ");
        scanf("%d", &e[i].id);

        printf("Name: ");
        scanf(" %[^\n]", e[i].name);

        printf("Department (IT/HR/Finance/Marketing/Operations): ");
        scanf("%s", e[i].department);

        printf("Designation (Intern/Junior/Senior/Manager/Director): ");
        scanf("%s", e[i].designation);

        printf("Salary: ");
        scanf("%f", &e[i].salary);

        printf("Phone: ");
        scanf("%s", e[i].phone);

        printf("Email: ");
        scanf("%s", e[i].email);

        printf("Joining Date (dd mm yyyy): ");
        scanf("%d %d %d",
              &e[i].joiningDate.day,
              &e[i].joiningDate.month,
              &e[i].joiningDate.year);
    }

    while(1) {
        printf("\n\n1. Department-wise Salary Stats");
        printf("\n2. Annual Appraisal");
        printf("\n3. Search Employees");
        printf("\n4. Promotion Eligible List");
        printf("\n5. Exit");
        printf("\nEnter choice: ");
        scanf("%d", &choice);

        if(choice == 1)
            salaryByDepartment(e, n);

        else if(choice == 2) {
            printf("Enter employee index: ");
            scanf("%d", &id);
            annualAppraisal(&e[id]);
        }

        else if(choice == 3)
            searchEmployees(e, n);

        else if(choice == 4)
            promotionEligible(e, n);

        else
            break;
    }

    return 0;
}
