#include"PRODUCT.h"
#include <string.h>
#include <iostream>
#include<iomanip>
using namespace std;
PRODUCT::PRODUCT() {
	strcpy_s(ProductID, "");
	strcpy_s(ProductName, "");
	strcpy_s(ResourcesFirm, "");
	strcpy_s(Size, "");
	this->ExistingQuantities = 0;
	this->WholesalePrice = 0;
}
PRODUCT::PRODUCT(char* ProductID, char* ProductName, char* ResourcesFirm, char* Size, float ExistingQuantities, float WholesalePrice)
{
	strcpy_s(this->ProductID, ProductID);
	strcpy_s(this->ProductName, ProductName);
	strcpy_s(this->ResourcesFirm, ResourcesFirm);
	strcpy_s(this->Size, Size);
	this->ExistingQuantities = ExistingQuantities;
	this->WholesalePrice = WholesalePrice;
}

void PRODUCT::setSL(float X)
{
	this->ExistingQuantities = X;
}

PRODUCT::~PRODUCT()
{
}

int PRODUCT::sosanh(char* x)
{
	if (!strcmp(this->ProductID, x)) return 1;
	return 0;
}

float PRODUCT::getWholesalePrice()
{
	return this->WholesalePrice;
}

float PRODUCT::getExistingQuantities()
{
	return this->ExistingQuantities;
}

PRODUCT PRODUCT::operator=(const PRODUCT& X)
{
	strcpy_s(this->ProductID, X.ProductID);
	strcpy_s(this->ProductName, X.ProductName);
	strcpy_s(this->ResourcesFirm, X.ResourcesFirm);
	strcpy_s(this->Size, X.Size);
	this->ExistingQuantities = X.ExistingQuantities;
	this->WholesalePrice = WholesalePrice;
	return *this;
}
ostream& operator<<(ostream& o, const PRODUCT& X)
{
	o << "\tProductID        \t:" << X.ProductID << endl;
	o << "\tProductName      \t:" << X.ProductName << endl;
	o << "\tResourcesFirm    \t:" << X.ResourcesFirm << endl;
	o << "\tSize             \t:" << X.Size << endl;
	o << "\tExistingQuantities\t:" << X.ExistingQuantities << endl;
	o << "\tWholesalePrice    \t:" << X.WholesalePrice << endl;
	return o;
}
