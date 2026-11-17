#ifndef PRODUCT_H
#define PRODUCT_H
#include "../Data/structures.h"
int findProduct(int productID);
void displayProductList(void);
void addProduct(void);
void editProduct(void);
void deleteProduct(void);
double calculateProductPrice(double basePrice,int size,const char *crust,const char *topping);
#endif
