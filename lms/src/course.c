#include <stdio.h>
#include <stdlib.h>
#include "course.h"

#define COURSE_FILE "data/courses.dat"

int create_course(int instructor_id)
{
  Course c;
  c.id = rand() % 10000;
  c.instructor_id = instructor_id;

  printf("Course title: ");
  scanf(" %[^\n]", c.title);

  FILE *fp = fopen(COURSE_FILE, "ab");
  if (!fp)
    return 0;

  fwrite(&c, sizeof(Course), 1, fp);
  fclose(fp);
  return 1;
}

void list_courses()
{
  FILE *fp = fopen(COURSE_FILE, "rb");
  if (!fp)
  {
    printf("No courses found\n");
    return;
  }

  Course c;
  while (fread(&c, sizeof(Course), 1, fp))
  {
    printf("ID: %d | Title: %s | Instructor: %d\n",
           c.id, c.title, c.instructor_id);
  }
  fclose(fp);
}
