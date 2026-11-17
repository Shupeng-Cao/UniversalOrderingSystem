#include <stdio.h>
#include <string.h>
#include "../Data/data.h"
#include "user.h"

int findUser(int id)
{
    int i;
    for (i = 0; i < userCount; i++)
        if (users[i].userID == id && users[i].active)
            return i;
    return -1;
}

int registerUser(void)
{
    User u;
    int i, maxID = 1000;

    if (userCount >= MAX_USERS)
    {
        puts("User list is full.");
        return -1;
    }
    for (i = 0; i < userCount; i++)
        {
            if (users[i].userID > maxID)
            {
                maxID = users[i].userID;
            }
        }

    u.userID = maxID + 1;

    printf("Name: ");
    scanf(" %49[^\n]", u.name);
    printf("Telephone: ");
    scanf(" %19s", u.telephone);
    printf("Password: ");
    scanf(" %19s", u.password);

    u.balance = 0;
    u.active = 1;
    
    users[userCount] = u;
    userCount++;
    saveUsers();
    printf("Registered. Your account number is %d.\n", u.userID);
    return u.userID;
}

int loginUser(void)
{
    int id, index;
    char password[20];
    printf("Account number: ");
    if (scanf("%d", &id) != 1)
        return -1;
    printf("Password: ");
    scanf(" %19s", password);
    index = findUser(id);
    if (index >= 0 && strcmp(users[index].password, password) == 0)
        return index;
    puts("Invalid account number or password.");
    return -1;
}
void displayUser(int n)
{
    if (n >= 0 && n < userCount)
        printf("\nAccount: %d\nName: %s\nTelephone: %s\nBalance: $%.2f\n", users[n].userID, users[n].name, users[n].telephone, users[n].balance);
}
void displayUserList(void)
{
    int i;
    puts("\n--- Customers ---");
    for (i = 0; i < userCount; i++)
        if (users[i].active)
            printf("%d | %s | %s | $%.2f\n", users[i].userID, users[i].name, users[i].telephone, users[i].balance);
}
void editUser(int n)
{
    if (n < 0 || n >= userCount || !users[n].active)
        return;
    printf("New name: ");
    scanf(" %49[^\n]", users[n].name);
    printf("New telephone: ");
    scanf(" %19s", users[n].telephone);
    saveUsers();
    puts("Customer updated.");
}
void deleteUser(int n)
{
    if (n < 0 || n >= userCount || !users[n].active)
        return;
    users[n].active = 0;
    saveUsers();
    puts("Customer deactivated.");
}
