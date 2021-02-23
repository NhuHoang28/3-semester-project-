#include "BILLDETAIL.h"
#include <string.h>
#include <iostream>
#include<iomanip>
using namespace std;

BILLDETAIL::BILLDETAIL() {
    strcpy_s(BillID, "");
    strcpy_s(ProductID, "");
    this->Prices = 0;
    this->Quantities = 0;
    this->Discount = 0;
    this->Total = 0;
}
BILLDETAIL::BILLDETAIL(char* BillID, char* ProductID, float Prices, float Quantities, float Discount, float Total)
{
    strcpy_s(this->BillID, BillID);
    strcpy_s(this->ProductID, ProductID);
    this->Prices = Prices;
    this->Quantities = Quantities;
    this->Discount = Discount;
    this->Total = Total;
}
//BILLDETAIL::BILLDETAIL(const char* BillID, const char* ProductID, float Prices, float Quantities, float Discount, float Total)
//{
//    strcpy_s(this->BillID, BillID);
//    strcpy_s(this->ProductID, ProductID);
//    this->Prices = Prices;
//    this->Quantities = Quantities;
//    this->Discount = Discount;
//    this->Total = Total;
//}
BILLDETAIL::~BILLDETAIL()
{
}
 int BILLDETAIL::sosanhBillID(char* x)
 {
 	if (!strcmp(this->BillID, x)) return 1;
 	return 0;
 }
 float BILLDETAIL::getTotal()
 {
     return Total;
 }
 int BILLDETAIL::sosanh(char* x)
 {
      if (!strcmp(this->BillID, x)) return 1;
      return 0;
 }
 /*int BILLDETAIL::sosanhProductID(char* x)
 {
 	if (!strcmp(this->ProductID, x)) return 1;
 	return 0;
 }*/
 /*BILLDETAIL BILLDETAIL::operator=(const BILLDETAIL& X)
{
    strcpy_s(this->BillID, X.BillID);
    strcpy_s(this->ProductID, X.ProductID);
    this->Prices = Prices;
    this->Quantities = Quantities;
    this->Discount = Discount;
    this->Total = Total;
    return *this;
}*/
ostream& operator<<(ostream& o, const BILLDETAIL& X)
{
    o << "\tBillID      \t:" << X.BillID << endl;
    o << "\tProductID   \t:" << X.ProductID << endl;
    o << "\tPrices      \t:" << X.Prices << endl;
    o << "\tQuantities  \t:" << X.Quantities << endl;
    o << "\tDiscount    \t:" << X.Discount << endl;
    o << "\tTotal       \t:" << X.Total << endl;
    return o;
}