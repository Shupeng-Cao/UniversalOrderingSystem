#ifndef DATA_H
#define DATA_H
#include "structures.h"
extern User users[MAX_USERS];
extern Product products[MAX_PRODUCTS];
extern Order orders[MAX_ORDERS];
extern int userCount, productCount, orderCount;
void loadData(void);
void saveUsers(void);
void saveProducts(void);
void saveOrders(void);
void saveAllData(void);
#endif
