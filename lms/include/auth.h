#ifndef AUTH_H
#define AUTH_H

typedef enum
{
  STUDENT,
  INSTRUCTOR,
  ADMIN
} Role;

typedef struct
{
  int id;
  char username[50];
  char password[50];
  Role role;
} User;

// API
User register_user();
User login_user();
int save_user(User u);
int load_users(User *users, int max);

#endif
