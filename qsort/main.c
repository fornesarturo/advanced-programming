#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"

#define MAX_LENGTH_ORDER 20
#define STUDENTS_LENGTH 3


typedef struct s {
	char *name;
	int id;
} Student;

int cmp_student (const void *element1, const void *element2, int attribute) {
	Student *student1 = (Student *) element1;
	Student *student2 = (Student *) element2;
	switch(attribute) {
		case 0: // Name
				return strcmp(student1->name, student2->name);
		case 1: // Id
				return student1->id - student2->id;
	}
}

int cmp_names (const void *element1, const void *element2) {
	return cmp_student (element1, element2, 0);
}

int cmp_ids (const void *element1, const void *element2) {
	return cmp_student (element1, element2, 1);
}

int main(int argc, char **argv) {
	Student group[STUDENTS_LENGTH];
	Student key;
	Student * found_student;
	int i, needed_student;
	char order[MAX_LENGTH_ORDER];

	group[0].name = strdup("Juanito");
	group[0].id = 17;

	group[1].name = strdup("Pedro");
	group[1].id = 4;

	group[2].name = strdup("Mariana");
	group[2].id = 2;

	printf("Give me the order: ");
	scanf("%s", order);

	if (!strcmp(order, "name")) {
		qsort(group, STUDENTS_LENGTH, sizeof(Student), cmp_names);
	}

	if (!strcmp(order, "id")) {
		qsort(group, STUDENTS_LENGTH, sizeof(Student), cmp_ids);
	}

	for (i = 0; i < STUDENTS_LENGTH; i++) {
		printf("Student %s %d\n", group[i].name, group[i].id);
	}

	printf("Which is the id?: ");
	scanf("%d", &needed_student);
	key.id = needed_student;
	
	found_student = bsearch(&key, group, STUDENTS_LENGTH, sizeof(Student), cmp_ids);
	if (found_student != NULL) {
		printf("Student %s %d\n", found_student->name, found_student->id);
	} 
	else {
		printf("Student with id %d not found\n", needed_student);
	}
    return 0;
}
