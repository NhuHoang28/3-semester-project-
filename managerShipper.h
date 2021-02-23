#pragma once
#include"SHIPPER.h"
#include<vector>
using namespace std;
class managerShipper
{
private:
	vector<SHIPPER*> manager;
public:
	managerShipper();
	void setdatabase(SHIPPER*&);
	void Search();
	int checkID(char*);
	friend ostream& operator<<(ostream&, const managerShipper&);
	~managerShipper();
};

