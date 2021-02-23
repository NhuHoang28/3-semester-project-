#pragma once
#pragma once
#include<iostream>
#include<string>
using namespace std;
class CUSTOMER
{
private:
	char CustomerID[15];
	char CustomerName[25];
	char CustomerEmail[25];
	char CustomerPhoneNumber[15];
public:
	CUSTOMER();
	CUSTOMER(char*, char*, char*, char*);
	~CUSTOMER();
	int sosanh(char*);
	void setSDT(char*);
	friend ostream& operator<<(ostream&, const CUSTOMER&);
	CUSTOMER operator=(const CUSTOMER&);
};



