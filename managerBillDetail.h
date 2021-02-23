#pragma once
#include"BILLDETAIL.h"
#include<vector>
using namespace std;
class managerBillDetail
{
private:
	vector<BILLDETAIL*> manager;
public:
	managerBillDetail();
	void setdatabase(BILLDETAIL*&);
	int checkID(char*);
	float getTotal(char*);
	/*void update(char*, char*);*/
	void Delete(char*);
	void Search();
	friend ostream& operator<<(ostream&, const managerBillDetail&);
	~managerBillDetail();
};

