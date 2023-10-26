#include <stdio.h>
#include <string.h>

struct student {
    char name [20];
    char student_id [11]; //Assuming 10 digits.
    char mark [5];
};

int main () {
    struct student new_student;
    strcpy(new_student.name, "Mingxuan Zhang");
    strcpy(new_student.student_id, "sc23mz2");
    strcpy(new_student.mark, "90");
    printf("Student name:%s\n", new_student.name);
    printf("Student ID: %s\n", new_student.student_id);
    printf("Final mark:%s\n", new_student.mark);
    
    return 0;
}