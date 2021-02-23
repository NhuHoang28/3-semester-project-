#include "managerBillDetail.h"
managerBillDetail::managerBillDetail()
{
}
void managerBillDetail::setdatabase(BILLDETAIL*& X)
{
	this->manager.push_back(X);
}

int managerBillDetail::checkID(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanhBillID(id)) { return 1; }
	}
	return 0;
}

float managerBillDetail::getTotal(char* id)
{
	float Total=0;
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanhBillID(id)) { Total+= this->manager[i]->getTotal();}
	}
	return Total;
}

//void managerBillDetail::update(char* id, char* newSdt)
//{
//	for (int i = 0; i < this->manager.size(); i++) {
//		if (this->manager[i]->sosanh(id)) this->manager[i]->setSDT(newSdt);
//	}
//}
//
void managerBillDetail::Delete(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) { this->manager.erase(this->manager.begin() + i); i--; }
	}
}

void managerBillDetail::Search()
{
	string billID;
	char BillID[15];
	cout << "SEARCH INFORMATION BILLDETAIL  " << endl;
	cout << "BillID : ";
	getline(cin, billID);
	getline(cin, billID);
	for (int i = 0; i < billID.length(); i++)
	{
		BillID[i] = billID[i];
	}
	BillID[billID.length()] = '\0';
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(BillID)) cout << *(this->manager[i]);
	}
}


managerBillDetail::~managerBillDetail()
{
	this->manager.clear();
}

ostream& operator<<(ostream& o, const managerBillDetail& X)
{
	for (int i = 0; i < X.manager.size(); i++)
	{
		cout << i + 1 << endl;
		o << *X.manager[i];
	}
	return o;
}


