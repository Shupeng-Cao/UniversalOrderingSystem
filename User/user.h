#ifndef USER_H
#define USER_H
#include "../Data/structures.h"
int findUser(int userID);
int findUserByUsername(const char username[]);
int registerUser(void);
int loginUser(void);
void displayUserList(void);
void editUser(int userIndex);
void deleteUser(int userIndex);
void displayUser(int userIndex);
#endif
