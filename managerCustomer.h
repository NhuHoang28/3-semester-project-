#pragma once
#include"CUSTOMER.h"
#include<vector>
using namespace std;
class managerCustomer
{
private:
	vector<CUSTOMER*> manager;
public:
	managerCustomer();
	void setdatabase(CUSTOMER*& );
    void update(char*,char*);
	void Delete(char*);
	void Search();
	int checkID(char*);
	friend ostream& operator<<(ostream&, const managerCustomer&);
	void printf(char*);
	~managerCustomer();
};

