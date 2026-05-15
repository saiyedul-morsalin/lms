#include "auth.h" // ← REQUIRED
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define USER_FILE "data/users.dat"

int save_user(User u)
{
  FILE *fp = fopen(USER_FILE, "ab");
  if (!fp)
  {
    perror("Failed to open file");
    return 0;
  }

  fwrite(&u, sizeof(User), 1, fp);
  fclose(fp);
  return 1;
}

int load_users(User *users, int max)
{
  FILE *fp = fopen(USER_FILE, "rb");
  if (!fp)
    return 0;

  int count = 0;
  while (count < max && fread(&users[count], sizeof(User), 1, fp))
  {
    count++;
  }

  fclose(fp);
  return count;
}

User register_user()
{
  User u;

  printf("Username: ");
  scanf("%49s", u.username);

  printf("Password: ");
  scanf("%49s", u.password);

  int role_input;
  printf("Role (0=Student,1=Instructor,2=Admin): ");
  scanf("%d", &role_input);

  if (role_input < 0 || role_input > 2)
  {
    printf("Invalid role\n");
    u.id = -1;
    return u;
  }

  u.role = (Role)role_input;
  u.id = rand();

  save_user(u);
  return u;
}

User login_user()
{
  User users[100];
  int count = load_users(users, 100);

  char username[50], password[50];

  printf("Username: ");
  scanf("%49s", username);

  printf("Password: ");
  scanf("%49s", password);

  for (int i = 0; i < count; i++)
  {
    if (strcmp(users[i].username, username) == 0 &&
        strcmp(users[i].password, password) == 0)
    {
      return users[i];
    }
  }

  User invalid = {.id = -1};
  return invalid;
}
