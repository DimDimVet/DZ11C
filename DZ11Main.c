#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define VOL 0 // 0, 1,2

void listStudent();
void listBook();
void listWork();

int main()
{
  printf("Start DZ11\n");
  listStudent();
}

#if VOL == 0
#pragma region
enum Gender
{
  Man,
  Woman
};
int sizeGender = 2;

enum NameLesson
{
  Mathematics,
  Literature,
  Physics,
  Chemistry
};
int sizeNameLesson = 4;

int Class[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
int GradeLesson[] = {1, 2, 3, 4, 5};

typedef struct
{
  char *lastName;
  char *name;
  char *middleName;
  enum Gender gender;
  int class;
  enum NameLesson nameLesson;
  int gradeLesson;
} itemStudent;
//
int count = 10;
void randomFullStruct(int count);
void printConsoleJournal(itemStudent *journalStudent, int count);

itemStudent journalStudent[];
//

void listStudent()
{
  if (1)
  {
    randomFullStruct(count);
  }
  printConsoleJournal(journalStudent, count);
}

void randomFullStruct(int count)
{
  char strLastName[20];
  char strName[20];
  char strMiddleName[20];

  srand(time(0));
  for (int i = 0; i < count; i++)
  {
    sprintf(strLastName, "%d", i);
    journalStudent[i].lastName = strLastName;
    sprintf(strName, "%d", i);
    journalStudent[i].name = strName;
    sprintf(strMiddleName, "%d", i);
    journalStudent[i].middleName = strMiddleName;

    journalStudent[i].gender = rand() % sizeGender;
    journalStudent[i].class = rand() % (sizeof(Class) / sizeof(Class[0])) + 1;
    journalStudent[i].nameLesson = rand() % sizeNameLesson;
    journalStudent[i].gradeLesson =
        rand() % (sizeof(GradeLesson) / sizeof(GradeLesson[0])) + 1;
  }
}

void printConsoleJournal(itemStudent journalStudent[], int count)
{
  printf("%s\n\n\n", journalStudent[1].lastName);

  char strGender[20];
  char strLesson[20];

  for (int j = 0; j < count; j++)
  {
    printf("%s\n", journalStudent[j].lastName);

    switch (journalStudent[j].gender)
    {
    case Man:
      sprintf(strGender, "Man");
      // break;
    case Woman:
      sprintf(strGender, "Woman");
      // break;
    default:
      break;
    }

    switch (journalStudent[j].nameLesson)
    {
    case Mathematics:
      sprintf(strLesson, "Mathematics");
      // break;
    case Literature:
      sprintf(strLesson, "Literature");
      // break;
    case Physics:
      sprintf(strLesson, "Physics");
      // break;
    case Chemistry:
      sprintf(strLesson, "Chemistry");
      // break;
    default:
      break;
    }

   // printf("%s %s %s\n", journalStudent[j].lastName, journalStudent[j].name,
    //       journalStudent[j].middleName);
            

    printf("Gender->%s Class->%d Lesson->%s GradeLesson->%d\n\n", strGender,
           journalStudent[j].class, strLesson, journalStudent[j].gradeLesson);
  }
}
#pragma endregion
#elif VOL == 1
void listBook() {}
#elif VOL == 2
void listWork() {}
#endif
