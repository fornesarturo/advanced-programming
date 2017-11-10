include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "students.h"

typedef struct s {
  char name[100];
  int id;
} Student;

/*
int main(int argc, char **argv) {
  Student pAvanzada[10];
  strcpy(pAvanzada[0].name, "Juan");
  pAvanzada[0].id = 45;

  strcpy(pAvanzada[1].name, "Francisco");
  pAvanzada[1].id = 10;

  strcpy(pAvanzada[5].name, "Alan");
  pAvanzada[5].id = 25;

  strcpy(pAvanzada[4].name, "Eduardo");
  pAvanzada[4].id = 30;

  assert(argc == 2);
  FILE *myFile;
  myFile = fopen(argv[1], "wb");
  assert(myFile != NULL);

  fwrite(pAvanzada, sizeof(Student), 10, myFile);
  fclose(myFile);

  return 0;
}

*/

// read students
int main(int argc, char **argv) {
  assert(argc == 3);
  FILE *myFile;
  myFile = fopen(argv[1], "rb");
  assert(myFile != NULL);

  Student myStudent;
  int record = atoi(argv[2]);
  long offset = sizeof(Student) * record;
  fseek(myFile,offset,SEEK_SET);
  fread(&myStudent,sizeof(Student),1,myFile);
  fclose(myFile);
  printf("Student at %d is: name %s, id %d \n",record,myStudent.name,myStudent.id);
  return 0;
}


// update
/*
int main(int argc, char **argv) {
  assert(argc == 3);
  FILE *myFile;
  myFile = fopen(argv[1], "r+b");
  assert(myFile != NULL);

  Student myStudent;
  int record = atoi(argv[2]);
  long offset = sizeof(Student) * record;
  fseek(myFile,offset,SEEK_SET);
  fread(&myStudent,sizeof(Student),1,myFile);
  printf("Student at %d is: name %s, id %d \n",record,myStudent.name,myStudent.id);
  printf("New name:");
  scanf("%s", myStudent.name);
  printf("New id:");
  scanf("%d", &myStudent.id);
  fseek(myFile,offset,SEEK_SET);
  fwrite(&myStudent,sizeof(Student),1,myFile);
  fclose(myFile);
  return 0;
}
*/

// add record

/*
int main(int argc, char **argv) {
  assert(argc == 2);
  FILE *myFile;
  myFile = fopen(argv[1], "a+b");
  assert(myFile != NULL);

  Student myStudent;
  printf("New name:");
  scanf("%s", myStudent.name);
  printf("New id:");
  scanf("%d", &myStudent.id);

  fwrite(&myStudent,sizeof(Student),1,myFile);
  fclose(myFile);
  return 0;
}
*/
