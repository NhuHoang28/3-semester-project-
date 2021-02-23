#pragma once
#include<iostream>
#include<string>
using namespace std;
class BILLDETAIL
{
private:
    char BillID[15];
    char ProductID[15];
    float Prices;
    float Quantities;
    float Discount;
    float Total;
public:
    BILLDETAIL();
    BILLDETAIL(char*, char*, float, float, float, float);
   //BILLDETAIL(const char*, const char*, float, float, float, float);
    ~BILLDETAIL();
    int sosanhBillID(char*);
    float getTotal();
    int sosanh(char*);
    //BILLDETAIL operator=(const BILLDETAIL&);
    friend ostream& operator<<(ostream&, const BILLDETAIL&);
};