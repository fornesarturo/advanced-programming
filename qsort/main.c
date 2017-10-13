#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "qsort.h"

typedef struct s {
	char *name;
	int id;
} Student;

int cmp_names (const void *element1, const void *element2) {
	Student *student1 = (Student *) element1;
	Student *student2 = (Student *) element2;
	return strcmp(student1->name, student2->name);
}

int cmp_ids (const void *element1, const void *element2) {
	Student *student1 = (Student *) element1;
	Student *student2 = (Student *) element2;
	return student1->id - student2->id;
}

int main(int argc, char **argv) {
	Student group[3];
	int i;
	char order[20];

	group[0].name = strdup("Juanito");
	group[0].id = 17;

	group[1].name = strdup("Pedro");
	group[1].id = 4;

	group[2].name = strdup("Mariana");
	group[2].id = 2;

	printf("Give me the order: ");
	scanf("%s", order);

	if (!strcmp(order, "name")) {
		qsort(group, 3, sizeof(Student), cmp_names);
	}

	if (!strcmp(order, "id")) {
		qsort(group, 3, sizeof(Student), cmp_ids);
	}

	for (i = 0; i < 3; i++) {
		printf("Student %s %d\n", group[i].name, group[i].id);
	}

    return 0;
}
