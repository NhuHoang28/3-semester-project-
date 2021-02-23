#pragma once
#include<iostream>
#include<string>
using namespace std;

class PRODUCT
{
   private:
        char ProductID[15];
        char ProductName[25];
        char ResourcesFirm[30];
        char Size[2];
        float ExistingQuantities;
        float WholesalePrice;
   public:
        PRODUCT();
        ~PRODUCT();
        PRODUCT(char*, char*, char*, char*,float,float);
        void setSL(float x);
        int sosanh(char*);
        float getWholesalePrice();
        float getExistingQuantities();
        PRODUCT operator=(const PRODUCT&);
        friend ostream& operator<<(ostream&, const PRODUCT&);
};
