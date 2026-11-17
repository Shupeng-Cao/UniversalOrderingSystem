#include <stdio.h>
#include <string.h>
#include "data.h"

User users[MAX_USERS];
Product products[MAX_PRODUCTS];
Order orders[MAX_ORDERS];
int userCount = 0, productCount = 0, orderCount = 0;

static void defaultProducts(void)
{
    if (productCount == 0)
    {
        products[0].productID = 1;
        strcpy(products[0].name, "ClassicCheese");
        products[0].basePrice = 8.00;
        products[0].available = 1;

        products[1].productID = 2;
        strcpy(products[1].name, "Pepperoni");
        products[1].basePrice = 10.00;
        products[1].available = 1;

        products[2].productID = 3;
        strcpy(products[2].name, "Vegetarian");
        products[2].basePrice = 9.00;
        products[2].available = 1;

        productCount = 3;
        saveProducts();
    }
}

void loadData(void)
{
    FILE *fp;

    fp = fopen("users.txt", "r");
    if (fp != NULL)
    {
        while (userCount < MAX_USERS &&
               fscanf(fp, "%d %49s %19s %19s %lf %d",
                      &users[userCount].userID,
                      users[userCount].name,
                      users[userCount].telephone,
                      users[userCount].password,
                      &users[userCount].balance,
                      &users[userCount].active) == 6)
        {
            userCount++;
        }
        fclose(fp);
    }

    fp = fopen("products.txt", "r");
    if (fp != NULL)
    {
        while (productCount < MAX_PRODUCTS &&
               fscanf(fp, "%d %49s %lf %d",
                      &products[productCount].productID,
                      products[productCount].name,
                      &products[productCount].basePrice,
                      &products[productCount].available) == 4)
        {
            productCount++;
        }
        fclose(fp);
    }

    fp = fopen("orders.txt", "r");
    if (fp != NULL)
    {
        while (orderCount < MAX_ORDERS &&
               fscanf(fp, "%d %d %d %49s %29s %d %29s %d %lf %d",
                      &orders[orderCount].orderID,
                      &orders[orderCount].userID,
                      &orders[orderCount].productID,
                      orders[orderCount].productName,
                      orders[orderCount].crust,
                      &orders[orderCount].size,
                      orders[orderCount].topping,
                      &orders[orderCount].quantity,
                      &orders[orderCount].unitPrice,
                      &orders[orderCount].status) == 10)
        {
            orderCount++;
        }
        fclose(fp);
    }

    defaultProducts();
}

void saveUsers(void)
{
    FILE *fp;
    int i;

    fp = fopen("users.txt", "w");
    if (fp == NULL)
        return;

    for (i = 0; i < userCount; i++)
    {
        fprintf(fp, "%d %s %s %s %.2f %d\n",
                users[i].userID,
                users[i].name,
                users[i].telephone,
                users[i].password,
                users[i].balance,
                users[i].active);
    }
    fclose(fp);
}

void saveProducts(void)
{
    FILE *fp;
    int i;

    fp = fopen("products.txt", "w");
    if (fp == NULL)
        return;

    for (i = 0; i < productCount; i++)
    {
        fprintf(fp, "%d %s %.2f %d\n",
                products[i].productID, products[i].name,
                products[i].basePrice, products[i].available);
    }
    fclose(fp);
}

void saveOrders(void)
{
    FILE *fp;
    int i;

    fp = fopen("orders.txt", "w");
    if (fp == NULL)
        return;

    for (i = 0; i < orderCount; i++)
    {
        fprintf(fp, "%d %d %d %s %s %d %s %d %.2f %d\n",
                orders[i].orderID, orders[i].userID,
                orders[i].productID, orders[i].productName,
                orders[i].crust, orders[i].size,
                orders[i].topping, orders[i].quantity,
                orders[i].unitPrice, orders[i].status);
    }
    fclose(fp);
}

void saveAllData(void)
{
    saveUsers();
    saveProducts();
    saveOrders();
}
