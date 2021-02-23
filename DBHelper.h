#pragma once
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include<stdlib.h>
#include "managerCustomer.h"
#include "managerShipper.h"
#include "managerProduct.h"
#include "managerBill.h"
#include "managerBillDetail.h"
class DBHelper
{
protected:
#define SQL_RESULT_LEN 240
#define SQL_RETURN_CODE_LEN 1024
	//define handles and variables
	SQLHANDLE sqlConnHandle;
	SQLHANDLE sqlStmtHandle;
	SQLHANDLE sqlEnvHandle;
	SQLWCHAR retconstring[SQL_RETURN_CODE_LEN];
public:
	void Init();
	void SelectCustomer(managerCustomer&);
	void InsertCustomer(managerCustomer&);
	void UpdateCustomer(managerCustomer&);
	void DeleteCustomer(managerCustomer&);
	//---------------------------------------
	void SelectShipper(managerShipper&);
	//---------------------------------------
	void SelectProduct(managerProduct&);
	void UpdateProduct(managerProduct&, string, float);
	//---------------------------------------
	void SelectBill(managerBill&);
	void InsertBill(managerBill&, managerBillDetail& , managerProduct& , managerCustomer , managerShipper );
	void UpdateBill(managerBill&,string,float&);
	void UpdateBill(managerBill&);
	void DeleteBill(managerBill&, managerBillDetail&);
	//---------------------------------------
	void SelectBillDetail(managerBillDetail&);
	void InsertBillDetail(managerBillDetail&,string,managerBill&, managerProduct&,float&);
	void DeleteBillDetail(managerBillDetail&,string );
	
	void close();
};

