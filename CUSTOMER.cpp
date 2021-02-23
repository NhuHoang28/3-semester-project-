#include "CUSTOMER.h"
#include <string.h>
#include <iostream>
#include<iomanip>
using namespace std;

CUSTOMER::CUSTOMER() {
	strcpy_s(CustomerID, "");
	strcpy_s(CustomerName, "");
	strcpy_s(CustomerEmail, "");
	strcpy_s(CustomerPhoneNumber, "");
}
CUSTOMER::CUSTOMER(char* CustomerID, char* CustomerName, char* CustomerEmail, char* CustomerPhoneNumber) {
	strcpy_s(this->CustomerID, CustomerID);
	strcpy_s(this->CustomerName, CustomerName);
	strcpy_s(this->CustomerEmail, CustomerEmail);
	strcpy_s(this->CustomerPhoneNumber, CustomerPhoneNumber);

}

CUSTOMER::~CUSTOMER()
{
}

int CUSTOMER::sosanh(char* x)
{
	if (!strcmp(this->CustomerID, x)) return 1;
	return 0;
}
void CUSTOMER::setSDT(char* x)
{
	strcpy_s(this->CustomerPhoneNumber, x);
}
CUSTOMER CUSTOMER::operator=(const CUSTOMER& X)
{
	strcpy_s(this->CustomerID, X.CustomerID);
	strcpy_s(this->CustomerName, X.CustomerName);
	strcpy_s(this->CustomerEmail, X.CustomerEmail);
	strcpy_s(this->CustomerPhoneNumber,X.CustomerPhoneNumber);
	return *this;
}




//void CUSTOMER::Scanf() {
//	cout << "=================== NHAP THONG TIN KHACH HANG =======================" << endl;
//		cout << "\t:CustomerID ";
//		cin.ignore();
//		cin.getline(CustomerID, 10);
//		cout << "\ttCustomerName: ";
//		cin.ignore();
//		cin.getline(CustomerName, 25);
//		cout << "\tCustomerEmail: ";
//		cin.ignore();
//		cin.getline(CustomerEmail, 50);
//		cout << "\tCustomerPhoneNumber: ";
//		cin.ignore();
//		cin.getline(CustomerPhoneNumber, 15);
//		cout << "\:CumulativePoints ";
//		cin.ignore();
//		cin >> CumulativePoints;
//	}
//}

//void Update();
//void Delete();

ostream& operator<<(ostream& o, const CUSTOMER& X)
{
	o << "\tCustomerID        \t:" << X.CustomerID << endl;
	o << "\tCustomerName      \t:" <<X.CustomerName << endl;
	o << "\tCustomerEmail    \t:" << X.CustomerEmail << endl;
	o << "\tCustomerPhoneNumber\t:" << X.CustomerPhoneNumber << endl;
	return o;
}


