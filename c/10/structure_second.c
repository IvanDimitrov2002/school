#include <stdio.h>
#include <string.h>

typedef struct{
    char name[128];
    // struct human_t;
    unsigned int employes;
    float budget;
} company_t;

typedef struct {
    unsigned int age;
    char name[256];
    char sex;
    char subject[64];
    unsigned int number_of_attended_classes;
    unsigned int number_of_jobs;
    company_t company[10]; 
} teacher_t;

void print_company (company_t company){
    printf("\n%s %u %.2f\n", company.name, company.employes, company.budget);
}

void print_teacher(teacher_t teacher){
    printf("%s %c %u ", teacher.name, teacher.sex, teacher.age);
    printf("%s %u ", teacher.subject, teacher.number_of_attended_classes);
    for(int i=0;i<teacher.number_of_jobs;i++){
        print_company(teacher.company[i]);
    }
}

int main(){
    company_t elsys;
    strcpy(elsys.name, "Elsys");
    elsys.employes = 5;
    elsys.budget = 1000;
    company_t spge;
    strcpy(spge.name, "SPGE");
    spge.employes = 3;
    spge.budget = 2000;
    teacher_t ee_teacher;
    strcpy(ee_teacher.name, "Penka");
    ee_teacher.sex = 'F';
    ee_teacher.age = 37;
    strcpy(ee_teacher.subject, "EE");
    ee_teacher.number_of_attended_classes = 36;
    ee_teacher.number_of_jobs = 2;
    ee_teacher.company[0] = elsys;    
    ee_teacher.company[1] = spge;    
    print_teacher(ee_teacher);
    return 0;
}