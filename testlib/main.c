#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "dict.h"

typedef struct a {
    char * name;
    int semester;
} Student;

int main(int argc, char **argv) {
    Dictionary *students;
    int error_code;

    Student st;
    Student * new_student;
    char matricula[100];
    st.name = strdup("Angel Perez");
    st.semester = 6;

    students = init_dict(100, &error_code);
    upsert_dict(students, "0101", (void *) &st, sizeof(Student), &error_code);

    st.name = strdup("Jesus Lopez");
    st.semester = 4;

    upsert_dict(students, "0202", (void *) &st, sizeof(Student), &error_code);

    printf("What is the id?: ");
    scanf("%s", matricula);
    new_student = (Student *) get_dict(students, matricula, sizeof(Student), &error_code);
    if (new_student == NULL) {
        printf("No such student.\n");
        return 0;
    } else {
        printf("Name: %s, Semester: %d\n", new_student->name, new_student->semester);
        return 0;
    }
    return 0;
}
