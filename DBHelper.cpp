#pragma once
#include "DBHelper.h"
#include<iomanip>
#include<conio.h>
#include<string.h>
using namespace std;
void DBHelper::Init() {
	sqlConnHandle = NULL;
	sqlStmtHandle = NULL;
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &sqlEnvHandle))
		close();
	//--- SQLAllochandle: cấp phát một môi trường, kết nối, câu lệnh hoặc xử lý bộ mô tả, 1. Loại xử lý được SQLAllocHandle cấp phát. 2 Xử lý đầu vào trong ngữ cảnh mà xử lý mới sẽ được cấp phát(đi theo cặp của 1), 3.Con trỏ đến một bộ đệm trong đó để trả lại xử lý về cấu trúc dữ liệu mới được cấp phát

	//---nếu lấy thành công khác với việc cấp phát một môi trường 
	if (SQL_SUCCESS != SQLSetEnvAttr(sqlEnvHandle, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, 0))
		close();
	//---SQLSetEnvAttr đặt các thuộc tính chi phối các khía cạnh của môi trường.1 môi trường,2 thuộc tính, 3 con trỏ liên kết với 2, 4 độ dài của chuỗi mà 3 trỏ đến
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_DBC, sqlEnvHandle, &sqlConnHandle))
		close();
	//output    
	cout << "Attempting connection to SQL Server...";
	cout << "\n";
	switch (SQLDriverConnect(sqlConnHandle, NULL, (SQLWCHAR*)L"DRIVER={SQL Server};SERVER=LAPTOP-JLIRL8KR\\SQLEXPRESS;DATABASE=Doan_hocky3;trusted=True;",
		SQL_NTS,
		retconstring,
		1024,
		NULL,
		SQL_DRIVER_NOPROMPT)) {
		//---SQLDriverconnect kết nối với sql. 3 chuỗi kết nối đầy đủ, 4 là độ dài của chuỗi 3, 5 là biến chứa con trỏ đã hoàn thành, 6 là độ dài của 5, 7 là độ dài được lấy của 4( dài hơn bị cắt), cờ hiệu để báo nahcws thêm thông tin kết nối
	case SQL_SUCCESS:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_SUCCESS_WITH_INFO:
		cout << "Successfully connected to SQL Server";
		cout << "\n";
		break;

	case SQL_INVALID_HANDLE:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	case SQL_ERROR:
		cout << "Could not connect to SQL Server";
		cout << "\n";
		close();
		break;

	default:
		break;
	}
	//if there is a problem connecting then exit application
	if (SQL_SUCCESS != SQLAllocHandle(SQL_HANDLE_STMT, sqlConnHandle, &sqlStmtHandle))
		close();
}

void DBHelper::SelectCustomer(managerCustomer& X)
{
	
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM CUSTOMER", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char customerID[15];
		char customerName[25];
		char customerEmail[25];
		char customerPhoneNumber[15];
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, customerID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, customerName, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, customerEmail, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, customerPhoneNumber, SQL_RESULT_LEN, &ptrSqlVersion);
			//---SQLGetdata: lấy dl trong bảng, 2 số cột trong bảng cần get (bắt đầu từ 1),3 là kiểu của 4 (https://bom.to/en5o2x5),4 con trỏ trỏ đến đệm để trả về dữ liệu, 5 là độ dài của ký tự hứng đó
			CUSTOMER* x = new CUSTOMER(customerID, customerName, customerEmail, customerPhoneNumber);
			X.setdatabase(x);
		}
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::InsertCustomer(managerCustomer& X)
{
	string s, customerID, customerName, customerEmail, customerPhoneNumber;
	string customerID_o, customerName_o, customerEmail_o, customerPhoneNumber_o;
	s = "INSERT INTO CUSTOMER VALUES(";
	cout << " INSERT CUSTOMER " << endl;
	const char* CustomerID;
	do {
		fflush(stdin);
		cout << " customerID : ";
		getline(cin, customerID);
		getline(cin, customerID);
		CustomerID = customerID.c_str();
	} while (X.checkID(const_cast<char*>(CustomerID)));
	
	customerID_o = "'" + customerID + "',";
	//-----------
	fflush(stdin);
	cout << " customerName: ";
	getline(cin, customerName);
	const char* CustomerName = customerName.c_str();
	customerName_o = "'" + customerName + "',";
	//----------------
	fflush(stdin);
	cout << "customerEmail :";
	getline(cin, customerEmail);
	const char* CustomerEmail = customerEmail.c_str();
	customerEmail_o = "'" + customerEmail + "',";
	//---------
	cout << "customerPhoneNumber :";
	fflush(stdin);
	getline(cin, customerPhoneNumber);
	const char* CustomerPhoneNumber = customerPhoneNumber.c_str();
	customerPhoneNumber_o = "'" + customerPhoneNumber + "')";
	//------------
	s = s + customerID_o + customerName_o + customerEmail_o + customerPhoneNumber_o ;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		CUSTOMER* x = new CUSTOMER(const_cast<char*>(CustomerID), const_cast<char*>(CustomerName), const_cast<char*>(CustomerEmail), const_cast<char*>(CustomerPhoneNumber));
		X.setdatabase(x);
		cout << "\nINSERT CUSTOMER SUCCESS"<<endl;
		return;
	}
}

void DBHelper::UpdateCustomer(managerCustomer& X)
{
	string s,s1, customerID, customerPhoneNumber;
	string customerID_o, customerPhoneNumber_o;
	s = "UPDATE CUSTOMER SET PhoneNumber= '";
	s1 = " WHERE CustomerID = '";
	cout << " UPDATE PHONE NUMBER "<<endl;
	const char* CustomerID;
	do {
		fflush(stdin);
		cout << "Your customerID : ";
		getline(cin, customerID);
		getline(cin, customerID);
		CustomerID = customerID.c_str();
	} while (!X.checkID(const_cast<char*>(CustomerID)));
	customerID_o = customerID + "'";
	//-----------
	fflush(stdin);
	cout << "New customerPhoneNumber :";
	fflush(stdin);
	getline(cin, customerPhoneNumber);
	const char* CustomerPhoneNumber = customerPhoneNumber.c_str();
	customerPhoneNumber_o = customerPhoneNumber + "'";
	s = s + customerPhoneNumber_o + s1 + customerID_o;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server update";
		cout << "\n";
		close();
	}
	else {
		X.update(const_cast<char*>(CustomerID), const_cast<char*>(CustomerPhoneNumber));
		cout << "\nUPDATE CUSTOMER SUCCESS"<<endl;
		return;
	}
}

void DBHelper::DeleteCustomer(managerCustomer& X)
{
	string s, customerID;
	s = "DELETE from CUSTOMER where CustomerID = '";
	cout << "DELETE CUSTOMER  "<<endl;
	const char* CustomerID;
	do {
		fflush(stdin);
		cout << "Your customerID : ";
		getline(cin, customerID);
		CustomerID = customerID.c_str();
	} while (!X.checkID(const_cast<char*>(CustomerID)));
	customerID = customerID + "'";
	//-----------
	s = s  + customerID;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server delete";
		cout << "\n";
		close();
	}
	else {
		X.Delete(const_cast<char*>(CustomerID));
		cout << "\nDELETE CUSTOMER SUCCESS"<<endl;
		return;
	}
}

void DBHelper::SelectShipper(managerShipper& X)
{
	//output
	/*cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";*/
	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM SHIPPER", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		SQLINTEGER ptrSqlVersion;
		char shipperID[20];
		char shipperName[25];
		char phoneNumber[15];
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, shipperID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, shipperName, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, phoneNumber, SQL_RESULT_LEN, &ptrSqlVersion);
			//---SQLGetdata: láº¥y dl trong báº£ng, 2 sá»‘ cá»™t trong báº£ng cáº§n get (báº¯t Ä‘áº§u tá»« 1),3 lÃ  kiá»ƒu cá»§a 4 (https://bom.to/en5o2x5),4 con trá» trá» Ä‘áº¿n Ä‘á»‡m Ä‘á»ƒ tráº£ vá» dá»¯ liá»‡u, 5 lÃ  Ä‘á»™ dÃ i cá»§a kÃ½ tá»± há»©ng Ä‘Ã³
			SHIPPER* x = new SHIPPER(shipperID, shipperName, phoneNumber);
			//cout << *x;
			X.setdatabase(x);
		}
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::SelectProduct(managerProduct& X)
{
	//output
	/*cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";*/
	//if there is a problem executing the query then exit application
	//else display query result
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM PRODUCT", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		//declare output variable and pointer
		SQLINTEGER ptrSqlVersion;
		char productID[15];
		char productName[25];
		char resourcesFirm[30];
		char size[2];
		float existingQuantities;
		float wholesalePrice;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, productID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, productName, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, resourcesFirm, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_C_FLOAT, &existingQuantities, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_C_FLOAT, &wholesalePrice, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, size, SQL_RESULT_LEN, &ptrSqlVersion);
			//---SQLGetdata: láº¥y dl trong báº£ng, 2 sá»‘ cá»™t trong báº£ng cáº§n get (báº¯t Ä‘áº§u tá»« 1),3 lÃ  kiá»ƒu cá»§a 4 (https://bom.to/en5o2x5),4 con trá» trá» Ä‘áº¿n Ä‘á»‡m Ä‘á»ƒ tráº£ vá» dá»¯ liá»‡u, 5 lÃ  Ä‘á»™ dÃ i cá»§a kÃ½ tá»± há»©ng Ä‘Ã³
			PRODUCT* x = new PRODUCT(productID, productName, resourcesFirm, size, existingQuantities, wholesalePrice);
			//cout << *x;
			X.setdatabase(x);
		}
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::UpdateProduct(managerProduct& X,string productID, float x)// là số đã trừ
{
	string s, s1,quantities;
	string productID_o= productID;
	s = "UPDATE PRODUCT SET ExistingQuantities= '";
	s1 = " WHERE ProductID = '";
	quantities = to_string(x);
	quantities = quantities + "'";
	const char* ProductID = productID_o.c_str();
	productID = productID + "'";
	//----------
	s = s + quantities + s1 + productID;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server update";
		cout << "\n";
		close();
	}
	else {
		X.update(const_cast<char*>(ProductID), x);
		cout << "\nUPDATE PRODUCT SUCCESS"<<endl;
		return;
	}
}

void DBHelper::SelectBill(managerBill& X)
{
	/*cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";*/
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM BILL", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		SQLINTEGER ptrSqlVersion;
		char billID[15];
		char customerID[15];
		char shipperID[15];
		char purchasingDate[15];
		char deliveryDate[15];
		char deliveryPlace[80];
		float discount;
		float deliveryFees;
		float total;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, billID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, customerID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_CHAR, shipperID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_CHAR, purchasingDate, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_CHAR, deliveryDate, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_CHAR, deliveryPlace, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 7, SQL_C_FLOAT, &discount, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 8, SQL_C_FLOAT, &deliveryFees, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 9, SQL_C_FLOAT, &total, 1, &ptrSqlVersion);
			BILL* x = new BILL(billID, customerID, shipperID, purchasingDate, deliveryDate, deliveryPlace, discount, deliveryFees, total);
			X.setdatabase(x);
		}
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::InsertBill(managerBill& X, managerBillDetail& BD, managerProduct& P, managerCustomer C, managerShipper S)
{
	string s, billID, customerID, shipperID, purchasingDate, deliveryDate, deliveryPlace, discount, deliveryFees, total;
	string billID_o, customerID_o, shipperID_o, purchasingDate_o, deliveryDate_o, deliveryPlace_o;
	float Discount=0;
	float DeliveryFees=0;
	float Total=0;
	s = "INSERT INTO BILL VALUES(";
	cout << " INSERT BILL " << endl;
	const char* BillID;
	do {
		cout << " billID : ";
		getline(cin, billID_o);
		getline(cin, billID_o);
		BillID = billID_o.c_str();
	} while (X.checkID(const_cast<char*>(BillID)));
	billID = billID_o;
	billID = "'" + billID + "',";
	//-----------
	const char*CustomerID;
	do {
		fflush(stdin);
		cout << " Chose customerID" << endl;
		cout << C << endl;
		cout << " customerID: ";
		getline(cin, customerID_o);
	    CustomerID = customerID_o.c_str();
	} while (!C.checkID(const_cast<char*>(CustomerID)));
	C.printf(const_cast<char*>(CustomerID));
	system("pause");
	customerID = customerID_o;
	customerID = "'" + customerID + "',";
	//------------------
	const char* ShipperID;
	do {
		fflush(stdin);
		cout << " Choose shipperID" << endl;
		cout << S << endl;
		cout << " shipperID: ";
		getline(cin, shipperID_o);
		ShipperID = shipperID_o.c_str();
	} while (!S.checkID(const_cast<char*>(ShipperID)));
	shipperID = shipperID_o;
	shipperID = "'" + shipperID + "',";
	//-----------
	fflush(stdin);
	cout << " purchasingDate: ";
	getline(cin, purchasingDate_o);
	const char* PurchasingDate = purchasingDate_o.c_str();
	purchasingDate =  purchasingDate_o;
	purchasingDate = "'" + purchasingDate + "',";
	//-------------

	fflush(stdin);
	cout << " deliveryDate: ";
	getline(cin, deliveryDate_o);
	const char* DeliveryDate = deliveryDate_o.c_str();
	deliveryDate = deliveryDate_o;
	deliveryDate = "'" + deliveryDate + "',";
	//--------------
	fflush(stdin);
	cout << "deliveryPlace :";
	getline(cin, deliveryPlace_o);
	const char*DeliveryPlace=deliveryPlace_o.c_str();
	deliveryPlace = deliveryPlace_o;
	deliveryPlace = "'" + deliveryPlace + "',";
	//------------
	fflush(stdin);
	cout << "discount :";
	cin >> Discount;
	discount = to_string(Discount);
	//float Discounts = float(Discount);
	discount = "'" + discount + "',";
	//---------------------
	fflush(stdin);
	cout << "deliveryFees :";
	cin >> DeliveryFees;
	deliveryFees = to_string(DeliveryFees);
	//float DeliveryFeess = float(DeliveryFees);
	deliveryFees = "'" + deliveryFees + "',";
	//------------
	total = "0";
	total = "'" + total + "')";
	s = s + billID + customerID + shipperID + purchasingDate + deliveryDate + deliveryPlace + discount + deliveryFees + total;
	const char* m = s.c_str();
	fflush(stdin);
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		BILL* x = new BILL(const_cast<char*>(BillID), const_cast<char*>(CustomerID), const_cast<char*>(ShipperID), const_cast<char*>(PurchasingDate), const_cast<char*>(DeliveryDate), const_cast<char*>(DeliveryPlace), Discount, DeliveryFees, Total);
		X.setdatabase(x);
		int i;
		float sum=0;
		do {
			fflush(stdin);
			this->InsertBillDetail(BD, billID_o, X, P,sum);
			sum = sum - Discount + DeliveryFees;
			cout << endl;
			cout << "You want to add more items? Press 1 if you agree. Else press 0. ENTER YOUR CHOICE : ";
			cin >> i;
		} while (i);
		//cout << sum;
		this->UpdateBill(X,billID_o,sum);
		cout << "\nINSERT BILL SUCCESS"<<endl;
		return;
	}
}

void DBHelper::UpdateBill(managerBill& X, string billID,float& sum)
{
	string s, s1, total,billID_o;
	s = "UPDATE BILL SET Total= '";
	s1 = " WHERE BillID = '";
	total = to_string(sum);
	total = total + "'";
	const char* BillID = billID.c_str();
	billID_o = billID + "'";
	//----------
	s = s + total + s1 + billID_o;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server update";
		cout << "\n";
		close();
	}
	else {
		X.update(const_cast<char*>(BillID),sum);
		cout << "\nUPDATE BILL SUCCESS"<<endl;
		return;
	}
}

void DBHelper::UpdateBill(managerBill& X)
{
	string s, s1, billID, deliveryPlace;
	string billID_o,deliveryPlace_o;
	s = "UPDATE BILL SET DeliveryPlace= '";
	s1 = " WHERE BillID = '";
	cout << " UPDATE DeliveryPlace " << endl;
	const char* BillID;
	do {
		fflush(stdin);
		cout << "Your BillID : ";
		getline(cin, billID);
		getline(cin, billID);
		BillID = billID.c_str();
	} while (!X.checkID(const_cast<char*>(BillID)));
	billID_o = billID + "'";
	//-----------
	fflush(stdin);
	cout << "New DelyveryPlace :";
	fflush(stdin);
	getline(cin, deliveryPlace);
	const char* DeliveryPlace = deliveryPlace.c_str();
	deliveryPlace_o = deliveryPlace + "'";
	s = s + deliveryPlace_o + s1 + billID_o;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server update";
		cout << "\n";
		close();
	}
	else {
		X.update(const_cast<char*>(BillID), const_cast<char*>(DeliveryPlace));
		cout << "\nUPDATE BILL SUCCESS"<<endl;
		return;
	}
}

void DBHelper::DeleteBill(managerBill& X,managerBillDetail& BD)
{
	string s, billID;
	string billID_o;
	s = "DELETE from BILL where BillID = '";
	cout << "DELETE BILL  " << endl;
	const char* BillID;
	do {
		fflush(stdin);
		cout << " Enter BillID need delete: ";
		getline(cin, billID);
		getline(cin, billID);
		BillID = billID.c_str();
	} while (!X.checkID(const_cast<char*>(BillID)));
	billID_o = billID + "'";
	//-----------
	s = s + billID_o;
	const char* m = s.c_str();
	DeleteBillDetail(BD, billID);
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server delete";
		cout << "\n";
		close();
	}
	else {
		X.Delete(const_cast<char*>(BillID));
		cout << "\nDELETE BILL SUCCESS"<<endl;
		return;
	}
}

void DBHelper::SelectBillDetail(managerBillDetail& X)
{
	/*cout << "\n";
	cout << "Executing T-SQL query...";
	cout << "\n";*/
	if (SQL_SUCCESS != SQLExecDirect(sqlStmtHandle, (SQLWCHAR*)L"SELECT * FROM BILLDetail", SQL_NTS)) {
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		SQLINTEGER ptrSqlVersion;
		char billID[15];
		char productID[15];
		float prices;
		float quantities;
		float discount;
		float total;
		while (SQLFetch(sqlStmtHandle) == SQL_SUCCESS) {
			SQLGetData(sqlStmtHandle, 1, SQL_CHAR, billID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 2, SQL_CHAR, productID, SQL_RESULT_LEN, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 3, SQL_C_FLOAT, &prices, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 4, SQL_C_FLOAT, &quantities, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 5, SQL_C_FLOAT, &discount, 1, &ptrSqlVersion);
			SQLGetData(sqlStmtHandle, 6, SQL_C_FLOAT, &total, 1, &ptrSqlVersion);
			BILLDETAIL* x = new BILLDETAIL(billID, productID, prices, quantities, discount, total);
			X.setdatabase(x);
		}
	}
	SQLCancel(sqlStmtHandle);
}

void DBHelper::InsertBillDetail(managerBillDetail& X, string billID, managerBill& B, managerProduct& P,float &sum)
{
	string s,productID, prices, quantities, discount, total;
	float Prices ;
	float Quantities = 0.0;
	float Discount = 0.0;
	float Total = 0.0;
	cout << "INSERT BILLDETAIL " << endl;
	s = "INSERT INTO BILLDetail VALUES(";
	const char* BillID = billID.c_str();
	string billIDs = "'" + billID + "',";
	//-----------
	fflush(stdin);
	char ProductID[15];
	do {
		system("cls");
		cout << "INSERT BILLDETAIL " << endl;
		fflush(stdin);
		cout << " productID:";
		getline(cin, productID);
		for (int i = 0; i < productID.length(); i++)
		{
			ProductID[i] = productID[i];
		}
		ProductID[productID.length()] = '\0';
	} while (!P.checkID(ProductID));
	string productIDs = productID;
	productID = "'" + productID + "',";
	P.printf(ProductID);
	//-----------------
	Prices =P.getWholesalePrice(ProductID)+30000.0;
	cout << "prices: "<<Prices<<endl;
	prices=to_string(Prices);
	prices = "'" + prices + "',";
	//------------
	do {
		Quantities = 0;
		fflush(stdin);
		cout << "quantities :";
		cin >> Quantities;
		quantities = to_string(Quantities);
	} while (!P.checkSL(ProductID, Quantities));
	float Quantitiess = P.getExistingQuantities(ProductID) -float(Quantities);
	quantities = "'" + quantities + "',";
	//-----------
	fflush(stdin);
	cout << "discount :";
	cin >> Discount;
	discount = to_string(Discount);
	//float Discounts = float(Discount);
	discount = "'" + discount + "',";
	//---------
	Total = Prices* Quantities - Quantities*Discount;
	sum += Total;
	//float Totals = float(Total);
	cout <<"Total: "<< Total;
	total = to_string(Total);
	total = "'" + total + "')";
	//-------
	s = s + billIDs + productID + prices + quantities + discount + total;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {

		cout << "\n";
		cout << "Error querying SQL Server";
		cout << "\n";
		close();
	}
	else {
		this->UpdateProduct(P, productIDs, Quantitiess);
		BILLDETAIL* x = new BILLDETAIL(const_cast<char*>(BillID),const_cast<char*>(ProductID), Prices, Quantities, Discount, Total);
		X.setdatabase(x);
		cout << "\nINSERT SUCCESS";
		return;
	}
}

void DBHelper::DeleteBillDetail(managerBillDetail& X,string billID)
{
	string s,billID_o;
	s = "DELETE from BILLDetail where BillID = '";
	//cout << "DELETE CUSTOMER  " << endl;
	const char* BillID;
	BillID = billID.c_str();
	billID_o = billID + "'";
	//-----------
	s = s + billID_o;
	const char* m = s.c_str();
	if (SQL_SUCCESS != SQLExecDirectA(sqlStmtHandle, (SQLCHAR*)m, SQL_NTS)) {
		cout << "\n";
		cout << "Error querying SQL Server delete";
		cout << "\n";
		//close();
	}
	else {
		X.Delete(const_cast<char*>(BillID));
		cout << "\nDELETE BILLDETAIL SUCCESS";
		return;
	}
}

void DBHelper::close() {

	SQLFreeHandle(SQL_HANDLE_STMT, sqlStmtHandle);
	SQLDisconnect(sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_DBC, sqlConnHandle);
	SQLFreeHandle(SQL_HANDLE_ENV, sqlEnvHandle);
	system("pause");
	exit(0);
}





