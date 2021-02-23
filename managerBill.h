#pragma once
#include"BILL.h"
#include<vector>
using namespace std;
class managerBill
{
private:
	vector<BILL*> manager;
public:
	managerBill();
	void setdatabase(BILL*&);
	void update(char*, float);
	void update(char*,char*);
	void Delete(char*);
	void Search();
	int checkID(char*);
	int size();
	void sapxepnoibot(managerBill&);
	friend ostream& operator<<(ostream&, const managerBill&);
	~managerBill();
};

