#pragma once
#include<iostream>
#include<string>
using namespace std;
class SHIPPER
{
private:
    char ShipperID[20];
    char ShipperName[25];
    char PhoneNumber[15];
public:
    SHIPPER();
    ~SHIPPER();
    SHIPPER(char*, char*, char*);
    int sosanh(char*);
    SHIPPER operator=(const SHIPPER&);
    friend ostream& operator<<(ostream&, const SHIPPER&);
};
