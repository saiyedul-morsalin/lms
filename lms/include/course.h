#ifndef COURSE_H
#define COURSE_H

typedef struct
{
  int id;
  char title[100];
  int instructor_id;
} Course;

int create_course(int instructor_id);
void list_courses();

#endif
