#include <iostream>
#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include "DBHelper.h"
//#include "VECTOR.h"
#include <string>
#include <vector>
//use the std namespace
using namespace std;
void menu()          
{
	cout << "                                                 *************************** MANAGE CLOTHES SHOP ONLINE ***************************"<<endl;
	cout << "                                                 *                                  GROUP 19.14A                                  *"<<endl;
	cout << "                                                 *                               Hoang Thi Thu Nhu                                *"<<endl;
	cout << "                                                 *                               Tran Thi Hong Ngoc                               *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
	cout << endl;
	cout << "                                                 ************************************** MENU **************************************"<<endl;
	cout << "                                                 * 1. SHOW                                                                        *"<<endl;
	cout << "                                                 * 2. SEARCH                                                                      *"<<endl;
	cout << "                                                 * 3. INSERT                                                                      *"<<endl;
	cout << "                                                 * 4. UPDATE                                                                      *"<<endl;
	cout << "                                                 * 5. DELETE                                                                      *"<<endl;
	cout << "                                                 * 6. SORT                                                                        *"<<endl;
	cout << "                                                 * 0. EXIT                                                                        *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
}
void Show()
{
	cout << endl;
	cout << "                                                 ************************************** SHOW **************************************"<<endl;
	cout << "                                                 * 1. CUSTOMERS                                                                   *"<<endl;
	cout << "                                                 * 2. SHIPPERS                                                                    *"<<endl;
	cout << "                                                 * 3. PRODUCTS                                                                    *"<<endl;
	cout << "                                                 * 4. BILLS                                                                       *"<<endl;
	cout << "                                                 * 5. BILLDETAIL                                                                  *"<<endl;
	cout << "                                                 * 0. EXIT                                                                        *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
}
void Search()
{
	cout << endl;
	cout << "                                                 ************************************* SEARCH *************************************"<<endl;
	cout << "                                                 * 1. CUSTOMERS                                                                   *"<<endl;
	cout << "                                                 * 2. SHIPPERS                                                                    *"<<endl;
	cout << "                                                 * 3. PRODUCTS                                                                    *"<<endl;
	cout << "                                                 * 4. BILLS                                                                       *"<<endl;
	cout << "                                                 * 5. BILLDETAILS                                                                 *"<<endl;
	cout << "                                                 * 0. EXIT                                                                        *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
}
void Insert()
{
	cout << endl;
	cout << "                                                 ************************************* INSERT *************************************"<<endl;
	cout << "                                                 * 1. CUSTOMER                                                                    *"<<endl;
	cout << "                                                 * 2. BILL                                                                        *"<<endl;
	cout << "                                                 * 0. EXIT                                                                        *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
}
void Update()
{
	cout << endl;
	cout << "                                                 ************************************* UPDATE *************************************"<<endl;
	cout << "                                                 * 1. CUSTOMER'S PHONE NUMBER                                                      *"<<endl;
	cout << "                                                 * 2. BILL'S DELIVERY PLACE                                                       *"<<endl;
	cout << "                                                 * 0. EXIT                                                                        *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
}
void Delete()
{
	cout << endl;
	cout << "                                                 ************************************* DELETE *************************************"<<endl;
	cout << "                                                 * 1. BILL                                                                        *"<<endl;
	cout << "                                                 * 0. EXIT                                                                        *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
}
void Sapxep()
{
	cout << endl;
	cout << "                                                 ************************************** SORT **************************************" << endl;
	cout << "                                                 * 1. SORT BY TOTAL OF BILL                                                       *" << endl;
	cout << "                                                 * 0. EXIT                                                                        *" << endl;
	cout << "                                                 **********************************************************************************" << endl;
}
void Exit()
{
	cout << endl;
	cout << "                                                 ************************************** EXIT *************************************"<<endl;
	cout << "                                                 *                                                                                *"<<endl;
	cout << "                                                 * THANK YOU FOR YOUR WATCHING...                                                 *"<<endl;
	cout << "                                                 *                                                                                *"<<endl;
	cout << "                                                 **********************************************************************************"<<endl;
}
int main() {
	int choice;
	DBHelper database;
	managerCustomer customers;
	managerShipper shippers;
	managerProduct products;
	managerBill bills;
	managerBillDetail billdetails;
	database.Init();
	database.SelectCustomer(customers);
	database.SelectShipper(shippers);
	database.SelectProduct(products);
	database.SelectBill(bills);
	database.SelectBillDetail(billdetails);
	do 
	{
		system("cls");
		menu();
		cout << endl;
		cout << "ENTER YOUR CHOICE:  ";
		cin >> choice;
		if (choice == 1)
		{
			int i;
			do
			{
				system("cls");
				Show();
				cout << "ENTER YOUR CHOICE:  ";
				cin >> i;
				if (i == 1) { cout << customers; system("pause"); }
				if (i == 2) { cout << shippers; system("pause"); }
				if (i == 3) { cout << products;system("pause"); }
				if (i == 4) { cout << bills; system("pause");}
				if (i == 5) { cout << billdetails;system("pause"); }
			} while (i);
		}
		if (choice == 2)
		{
			int i;
			do
			{
				system("cls");
				Search();
				cout << "ENTER YOUR CHOICE:  ";
				cin >> i;
				if (i == 1) {customers.Search();system("pause"); }
				if (i == 2) {shippers.Search();system("pause"); }
				if (i == 3) {products.Search();system("pause"); }
				if (i == 4) {bills.Search();system("pause"); }
				if (i == 5) {billdetails.Search();system("pause"); }
			} while (i);
		}
		if (choice == 3)
		{
			int i;
			do
			{
				system("cls");
				Insert();
				cout << "ENTER YOUR CHOICE:  ";
				cin >> i;
				if (i == 1) { database.InsertCustomer(customers);system("pause"); }
				if (i == 2) { database.InsertBill(bills, billdetails, products, customers, shippers);system("pause"); }
			} while (i);
		}
		if (choice == 4)
		{
			int i;
			do
			{
				system("cls");
				Update();
				cout << "ENTER YOUR CHOICE:  ";
				cin >> i;
				if (i == 1) { database.UpdateCustomer(customers); system("pause"); }
				if (i == 2) { database.UpdateBill(bills); system("pause"); }
			} while (i);
		}
		if (choice == 5)
		{
			int i;
			do
			{
				system("cls");
				Delete();
				cout << "ENTER YOUR CHOICE:  ";
				cin >> i;
				if (i == 1) {database.DeleteBill(bills,billdetails);system("pause"); }
			} while (i);
		}
		if (choice == 6)
		{
			int i;
			do
			{
				system("cls");
				Sapxep();
				cout << "ENTER YOUR CHOICE:  ";
				cin >> i;
				if (i == 1) { bills.sapxepnoibot(bills); system("pause"); }
			} while (i);
		}
		if (choice == 0)
		{
				system("cls");
				Exit();
		}
	} while (choice);
	database.close();
	return 1;
}