#include <stdio.h>
#include "auth.h"
#include "course.h"
#include "utils.h"

int main()
{
  int choice;
  User current_user;

  while (1)
  {
    printf("\n=== LMS ===\n");
    printf("1. Register\n2. Login\n3. Exit\nChoice: ");
    choice = get_int();

    if (choice == 1)
    {
      register_user();
    }
    else if (choice == 2)
    {
      current_user = login_user();

      if (current_user.id == -1)
      {
        printf("Login failed\n");
        continue;
      }

      printf("Login successful\n");

      while (1)
      {
        printf("\n1. Create Course\n2. List Courses\n3. Logout\nChoice: ");
        int c = get_int();

        if (c == 1)
        {
          if (current_user.role == INSTRUCTOR || current_user.role == ADMIN)
            create_course(current_user.id);
          else
            printf("Permission denied\n");
        }
        else if (c == 2)
        {
          list_courses();
        }
        else
        {
          break;
        }
      }
    }
    else
    {
      break;
    }
  }

  return 0;
}
