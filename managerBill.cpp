#include "managerBill.h"
managerBill::managerBill()
{
}
void managerBill::setdatabase(BILL*& X)
{
	this->manager.push_back(X);
}

void managerBill::update(char* id, float Total)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) {  this->manager[i]->setTotal(Total); }
	}
}

void managerBill::update(char* id, char* Del)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) { this->manager[i]->setDeliveryPlace(Del); }
	}
}

void managerBill::Delete(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) this->manager.erase(this->manager.begin() + i);
	}
}

void managerBill::Search()
{
	string billID;
	char BillID[15];
	cout << "SEARCH INFORMATION BILL  " << endl;
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

int managerBill::checkID(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) return 1;
	}
	return 0;
}

int managerBill::size()
{
	return this->manager.size();
}

void managerBill::sapxepnoibot(managerBill& a)
{
	for (int i = 0; i < a.size()-1; i++)
	{
		for (int j = 0; j < a.size()-i-1; j++)
		{
			if (a.manager[j]->getTotal() < a.manager[j+1]->getTotal())
			{
				BILL* temp = new BILL;
				temp->copy(a.manager[j]);
				a.manager[j]->copy(a.manager[j+1]);
				a.manager[j+1]->copy(temp);

			}
		}
	}
	cout << "Sort successfully" << endl;
	cout << a<<endl;
}

managerBill::~managerBill()
{
	this->manager.clear();
}

ostream& operator<<(ostream& o, const managerBill& X)
{
	for (int i = 0; i < X.manager.size(); i++)
	{
		cout << i + 1 << endl;
		o << *X.manager[i];
	}
	return o;
}

