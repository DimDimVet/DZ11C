#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TASK 1 // 1, 2, 3

void listStudent();
void listBook();
void listWork();

int main()
{
  printf("Start DZ11\n");
#if TASK == 1
  listStudent();
#elif TASK == 2
//
#elif TASK == 3
//
#endif
}

#if TASK == 1
#pragma ListStudent
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

int count = 10;
itemStudent journalStudent[] = {};

void randomFullStruct(int count);
void printConsoleJournal(itemStudent *journalStudent, int count);
char *pressButton();
int *getNumber();

void listStudent()
{
  char zz[] = "1";
  // printf("%s",zz);
  char *str=pressButton();
  //*str = *pressButton();
   printf("+++%s\n",&str);
   int result =strcmp (str,"12");
   //printf("+-%d\n",result);
   free(str);
  // str = pressButton(str);
  // printf("==%s", str);
printf("+-%d,%s\n",result,str);
  if (result==NULL)
  {
    printf("++%s\n", str);
    randomFullStruct(count);
  }
  printConsoleJournal(journalStudent, count);
}

char *pressButton()
{
  char *pressButton = (char *)malloc(20 * sizeof(char));
  scanf("%s", &pressButton);
  printf("+%s\n", &pressButton);
  return pressButton;
}

void randomFullStruct(int count)
{
  char tempStr[250];
  int sizeStr;
  char *strLastName = "LastName";
  char *strName = "Name";
  char *strMiddleName = "MiddleName";

  srand(time(0));
  for (int i = 0; i < count; i++)
  {
    sizeStr = sprintf(tempStr, "%s%d", strLastName, i);
    journalStudent[i].lastName = (char *)malloc(sizeStr * sizeof(char));
    strcpy(journalStudent[i].lastName, tempStr);

    sizeStr = sprintf(tempStr, "%s%d", strName, i);
    journalStudent[i].name = (char *)malloc(sizeStr * sizeof(char));
    strcpy(journalStudent[i].name, tempStr);

    sizeStr = sprintf(tempStr, "%s%d", strMiddleName, i);
    journalStudent[i].middleName = (char *)malloc(sizeStr * sizeof(char));
    strcpy(journalStudent[i].middleName, tempStr);

    journalStudent[i].gender = rand() % sizeGender;
    journalStudent[i].class = rand() % (sizeof(Class) / sizeof(Class[0])) + 1;
    journalStudent[i].nameLesson = rand() % sizeNameLesson;
    journalStudent[i].gradeLesson =
        rand() % (sizeof(GradeLesson) / sizeof(GradeLesson[0])) + 1;
  }
}

void printConsoleJournal(itemStudent journalStudent[], int count)
{
  char strGender[20];
  char strLesson[20];

  for (int j = 0; j < count; j++)
  {
    switch (journalStudent[j].gender)
    {
    case Man:
      sprintf(strGender, "Man");
      break;
    case Woman:
      sprintf(strGender, "Woman");
      break;
    default:
      break;
    }

    switch (journalStudent[j].nameLesson)
    {
    case Mathematics:
      sprintf(strLesson, "Mathematics");
      break;
    case Literature:
      sprintf(strLesson, "Literature");
      break;
    case Physics:
      sprintf(strLesson, "Physics");
      break;
    case Chemistry:
      sprintf(strLesson, "Chemistry");
      break;
    default:
      break;
    }

    printf("%s %s %s\n", journalStudent[j].lastName, journalStudent[j].name,
           journalStudent[j].middleName);

    printf("Gender->%s Class->%d Lesson->%s GradeLesson->%d\n\n", strGender,
           journalStudent[j].class, strLesson, journalStudent[j].gradeLesson);
  }
}
#pragma endListStudent
#elif TASK == 2
void listBook() {}
#elif TASK == 3
void listWork() {}
#endif
