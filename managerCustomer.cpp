#include "managerCustomer.h"
managerCustomer::managerCustomer()
{
}
void managerCustomer::setdatabase(CUSTOMER*& X)
{
	this->manager.push_back(X);
}

void managerCustomer::update(char* id, char* newSdt)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) this->manager[i]->setSDT(newSdt);
	}
}

void managerCustomer::Delete(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) this->manager.erase(this->manager.begin() + i);
	}
}

void managerCustomer::Search()
{
	string customerID;
	char CustomerID[15];
	cout << "SEARCH INFORMATION CUSTOMER  " << endl;
	cout << "CustomerID : ";
	fflush(stdin);
	getline(cin, customerID);
	getline(cin, customerID);
	for (int i = 0; i < customerID.length(); i++)
	{
		CustomerID[i] = customerID[i];
	}
	CustomerID[customerID.length()] = '\0';
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(CustomerID)) cout << *(this->manager[i]);
	}
}

int  managerCustomer::checkID(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) 
	{
		if (this->manager[i]->sosanh(id)) { cout << " This ID has been used." << endl; return 1; }
	}
	 cout << " This ID has not been used." << endl; return 0; 
}


void managerCustomer::printf(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) { cout << i + 1 << endl; cout << *this->manager[i];
		}
	}
}

managerCustomer::~managerCustomer()
{
	this->manager.clear();
}

ostream& operator<<(ostream& o, const managerCustomer& X)
{
	for (int i = 0; i < X.manager.size(); i++)
	{
		cout << i + 1<<endl;
		o << *X.manager[i];
	}
	return o;
}


