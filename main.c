#include <stdio.h>
#include <string.h>
#include "Data/data.h"
#include "User/user.h"
#include "UI/manager_ui.h"
#include "UI/customer_ui.h"
int main(void)
{
    int choice, n;
    char username[20], password[20];
    loadData();
    puts("=====================================\n       PIZZA ORDERING SYSTEM\n=====================================");
    do
    {
        puts("\n1 Manager login\n2 Customer login\n3 Customer registration\n0 Exit");
        printf("Choice: ");
        if (scanf("%d", &choice) != 1)
        {
            puts("Invalid input.");
            break;
        }
        switch (choice)
        {
        case 1:
            printf("Manager username: ");
            scanf(" %19s", username);
            printf("Manager password: ");
            scanf(" %19s", password);
            if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
                managerMenu();
            else
                puts("Incorrect manager login.");
            break;

        case 2:
            n = loginUser();
            if (n >= 0)
                customerMenu(n);
            break;

        case 3:
            registerUser();
            break;

        case 0:
            puts("Goodbye!");
            break;

        default:
            puts("Invalid choice.");
        }
    } while (choice != 0);
    saveAllData();
    return 0;
}
