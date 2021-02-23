#pragma once
#include"PRODUCT.h"
#include<vector>
using namespace std;
class managerProduct
{
private:
	vector<PRODUCT*> manager;
public:
	managerProduct();
	void setdatabase(PRODUCT*&);// Lấy về
	void update(char*,float );// update lại số lượng 
	void Search();// tìm kiếm theo id và show ra và đặt
	float getWholesalePrice(char*);
	float getExistingQuantities(char*);
	int checkID(char*);
	int checkSL(char*, float);
	void printf(char*);
	friend ostream& operator<<(ostream&, const managerProduct&);// in sản phẩm ra
	~managerProduct();
};

