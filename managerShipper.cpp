#include "managerShipper.h"

managerShipper::managerShipper()
{
}
void managerShipper::setdatabase(SHIPPER*& X)
{
	this->manager.push_back(X);
}
void managerShipper::Search()
{
	string shipperID;
	char ShipperID[15];
	cout << "SEARCH INFORMATION SHIPPER  " << endl;
	cout << "ShipperID : ";
	getline(cin, shipperID);
	getline(cin, shipperID);
	for (int i = 0; i < shipperID.length(); i++)
	{
		ShipperID[i] = shipperID[i];
	}
	ShipperID[shipperID.length()] = '\0';
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(ShipperID)) cout << *(this->manager[i]);
	}
}

int managerShipper::checkID(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) return 1;
	}
	return 0;
}


managerShipper::~managerShipper()
{
	this->manager.clear();
}

ostream& operator<<(ostream& o, const managerShipper& X)
{
	for (int i = 0; i < X.manager.size(); i++)
	{
		cout << i + 1 << endl;
		o << *X.manager[i];
	}
	return o;
}

