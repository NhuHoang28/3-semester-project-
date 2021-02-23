#pragma once
#include<iostream>
#include<string>
using namespace std;
class BILL
{
private:
    char BillID[15];
    char CustomerID[15];
    char ShipperID[15];
    char PurchasingDate[15];
    char DeliveryDate[15];
    char DeliveryPlace[80];
    float Discount;
    float DeliveryFees;
    float Total;
public:
    BILL();
    BILL(char*, char*, char*, char*, char*, char*, float, float, float);
    ~BILL();
    int sosanh(char*);
    void setTotal(float);
    void setDeliveryPlace(char*);
    void copy(BILL*);
    float getTotal();
    friend ostream& operator<<(ostream&, const BILL&);
};
