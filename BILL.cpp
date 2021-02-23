#include "BILL.h"
#include <string.h>
#include <iostream>
#include<iomanip>
using namespace std;

BILL::BILL() {
    strcpy_s(BillID, "");
    strcpy_s(CustomerID, "");
    strcpy_s(ShipperID, "");
    strcpy_s(PurchasingDate, "");
    strcpy_s(DeliveryDate, "");
    strcpy_s(DeliveryPlace, "");
    this->Discount = 0;
    this->DeliveryFees = 0;
    this->Total = 0;
}
BILL::BILL(char* BillID, char* CustomerID, char* ShipperID, char* PurchasingDate, char* DeliveryDate, char* DeliveryPlace, float Discount, float DeliveryFees, float Total )
{
    strcpy_s(this->CustomerID, CustomerID);
    strcpy_s(this->BillID, BillID);
    strcpy_s(this->ShipperID, ShipperID);
    strcpy_s(this->PurchasingDate, PurchasingDate);
    strcpy_s(this->DeliveryDate, DeliveryDate);
    strcpy_s(this->DeliveryPlace, DeliveryPlace);
    this->Discount = Discount;
    this->DeliveryFees = DeliveryFees;
    this->Total = Total;
}
BILL::~BILL()
{
}
int BILL::sosanh(char* x)
{
    if (!strcmp(this->BillID, x)) return 1;
    return 0;
}

void BILL::setTotal(float sum)
{
    this->Total = sum;
}

void BILL::setDeliveryPlace(char* Del)
{
   strcpy_s( this->DeliveryPlace ,Del);
}

void  BILL::copy(BILL* X)
{
    strcpy_s(this->CustomerID, X->CustomerID);
    strcpy_s(this->BillID, X->BillID);
    strcpy_s(this->ShipperID, X->ShipperID);
    strcpy_s(this->PurchasingDate, X->PurchasingDate);
    strcpy_s(this->DeliveryDate, X->DeliveryDate);
    strcpy_s(this->DeliveryPlace, X->DeliveryPlace);
    this->Discount = X->Discount;
    this->DeliveryFees = X->DeliveryFees;
    this->Total = X->Total;
}
float BILL::getTotal()
{
    return this->Total;
}
ostream& operator<<(ostream& o, const BILL& X)
{
    o << "\tBillID           \t:" << X.BillID << endl;
    o << "\tCustomerID       \t:" << X.CustomerID << endl;
    o << "\tShipperID          \t:" << X.ShipperID << endl;
    o << "\tPurchasingDate      \t:" << X.PurchasingDate << endl;
    o << "\tDeliveryDate     \t:" << X.DeliveryDate << endl;
    o << "\tDeliveryPlace    \t:" << X.DeliveryPlace << endl;
    o << "\tDiscount        \t:" << X.Discount << endl;
    o << "\tDeliveryFees     \t:" << X.DeliveryFees << endl;
    o << "\tTotal           \t:" << X.Total << endl;
    return o;
}
