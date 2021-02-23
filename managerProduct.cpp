#include "managerProduct.h"
managerProduct::managerProduct()
{
}
void managerProduct::setdatabase(PRODUCT*& X)
{
	this->manager.push_back(X);
}
void managerProduct::update(char* id,float sl)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)){  this->manager[i]->setSL(sl); }
	}
}
void managerProduct::Search()
{
	string productID;
	char ProductID[15];
	cout << "SEARCH INFORMATION PRODUCT  " << endl;
	cout << "ProductID : ";
	getline(cin, productID);
	getline(cin, productID);
	for (int i = 0; i < productID.length(); i++)
	{
		ProductID[i] = productID[i];
	}
	ProductID[productID.length()] = '\0';
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(ProductID)) cout << *(this->manager[i]);
	}
}

managerProduct::~managerProduct()
{
	this->manager.clear();
}

float managerProduct::getWholesalePrice(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) { return this->manager[i]->getWholesalePrice(); }
	}
}

float managerProduct::getExistingQuantities(char* id)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id)) return this->manager[i]->getExistingQuantities();
	}
}

int managerProduct::checkID(char* id)
{
	for (int i = 0; i < this->manager.size(); i++)
	{
		if (this->manager[i]->sosanh(id)) { cout << "ProductID is correct"<<endl; return 1; }
	}
	cout << "ProductID is not correct"<<endl; return 0;
}

int managerProduct::checkSL(char* id, float sl)
{
	for (int i = 0; i < this->manager.size(); i++) {
		if (this->manager[i]->sosanh(id))
		{
			if (this->manager[i]->getExistingQuantities() < sl) { cout << "ExistingQuantities:" << this->manager[i]->getExistingQuantities() << endl; return 0; }
		}
	}
	return 1;
}

void managerProduct::printf(char* id)
{
	for (int i = 0; i < this->manager.size(); i++)
	{
		if (this->manager[i]->sosanh(id)) { cout << *this->manager[i]; }
	}
}

ostream& operator<<(ostream& o, const managerProduct& X)
{
	for (int i = 0; i < X.manager.size(); i++)
	{
		cout << i + 1 << endl;
		o << *X.manager[i];
	}
	return o;
}


