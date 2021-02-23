#include "SHIPPER.h"
#include <string.h>
#include <iostream>
#include<iomanip>
using namespace std;
SHIPPER::SHIPPER()
{
	strcpy_s(ShipperID, "");
	strcpy_s(ShipperName, "");
	strcpy_s(PhoneNumber, "");
}
SHIPPER::SHIPPER(char* ShipperID, char* ShipperName, char* PhoneNumber)
{
	strcpy_s(this->ShipperID, ShipperID);
	strcpy_s(this->ShipperName, ShipperName);
	strcpy_s(this->PhoneNumber, PhoneNumber);
}
SHIPPER::~SHIPPER()
{
}
int SHIPPER::sosanh(char* x)
{
	if (!strcmp(this->ShipperID, x)) return 1;
	return 0;
}

SHIPPER SHIPPER::operator=(const SHIPPER& X)
{
	strcpy_s(this->ShipperID, X.ShipperID);
	strcpy_s(this->ShipperName, X.ShipperName);
	strcpy_s(this->PhoneNumber, X.PhoneNumber);
	return *this;
}
ostream& operator<<(ostream& o, const SHIPPER& X)
{
	o << "\tShipperID       \t:" << X.ShipperID << endl;
	o << "\tShipperName     \t:" << X.ShipperName << endl;
	o << "\tPhoneNumber          \t:" << X.PhoneNumber << endl;
	return o;
}
