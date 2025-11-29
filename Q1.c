#include <stdio.h>
#include <string.h>

struct Student{
    char name[50];
    int roll;
    float marks[3];
    float percentage;
    char grade[3];
};

void searchGrade(int, struct Student *s);

int main()
{
    struct Student s[100];
    int n;
    float totalMarks, classTotal=0;
    
    printf("Enter number of students: ");
    scanf("%d", &n);
    
    for(int i=0; i<n; i++){
        
        printf("\nEnter name for student %d: ", i+1);
        scanf(" %[^\n]", s[i].name);
        
        printf("Roll number: ");
        scanf("%d", &s[i].roll);
        
        printf("Marks\n");
        totalMarks=0;
        for(int j=0; j<3; j++){
            printf("Subject %d: ", j+1);
            scanf("%f", &s[i].marks[j]);
            totalMarks+=s[i].marks[j];
        }
        
        s[i].percentage=totalMarks/3.0;
        classTotal+=s[i].percentage;
        
        if(s[i].percentage>=90 && s[i].percentage<=100)
            strcpy(s[i].grade, "A+");
        else if(s[i].percentage>=80 && s[i].percentage<=89)
            strcpy(s[i].grade, "A");
        else if(s[i].percentage>=70 && s[i].percentage<=79)
            strcpy(s[i].grade, "B+");
        else if(s[i].percentage>=60 && s[i].percentage<=69)
            strcpy(s[i].grade, "B");
        else if(s[i].percentage>=50 && s[i].percentage<=59)
            strcpy(s[i].grade, "C");
        else if(s[i].percentage<50)
            strcpy(s[i].grade, "F");
    }
    
    searchGrade(n, s);
    
    float classAvg=classTotal/n;
    printf("\nClass Average: %.2f", classAvg);
    
    printf("\nStudents Above Average:\n");
    for(int i=0; i<n; i++){
        if(s[i].percentage > classAvg)
            printf("%s\n", s[i].name);
    }
    
    printf("\nStudents Below Average:\n");
    for(int i=0; i<n; i++){
        if(s[i].percentage < classAvg)
            printf("%s\n", s[i].name);
    }

    return 0;
}

void searchGrade(int n, struct Student *s){
    char searchingGrade[3];
    printf("\nEnter grade to search: ");
    scanf("%s", searchingGrade);
    
    printf("\nStudents with grade %s:", searchingGrade);
    for(int i=0; i<n; i++){
        if(strcmp(s[i].grade, searchingGrade) == 0)
            printf("\n%s Roll %d", s[i].name, s[i].roll);
    }
}
