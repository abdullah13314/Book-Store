// NileBookStore.cpp : Defines the entry point for the console application.
//


//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
#include "stdafx.h"
#include <iostream>
#include <string>
#include<vector>
#include "Book.h"
#include "AudioBook.h"
#include "GraphicNovel.h"
//#include "Customer.h"
//#include "GoldCustomer.h"
//#include "SeniorCustomer.h"
#include "CustomerManagement.h"
#include "InventoryManagement.h"
#include "BookStore.h"


using namespace std;

int main(int argc, char *argv[])
{
	//Checking customer and book class
	/*
	Book b1("Harry Potter and Prisoner of Azkaban", "J. K. Rolling");
	Book b2("Harry Potter and Goblet of Fire", "J. K. Rolling");
	Book b3("Harry Potter and Deathly Hollows", "J. K. Rolling");
	Book b4("Harry Potter and Half Boold Prince", "J. K. Rolling");
	Book b5("Harry Potter and Socerror Stones", "J. K. Rolling");
	Book b6("Harry Potter and Order of Pheonix", "J. K. Rolling");
	Book b7("Harry Potter and Chamber of Secret", "J. K. Rolling");


	GraphicNovel g1("One Piece 1", "Eiichiro Oda", "Eiichiro Oda");
	GraphicNovel g2("One Piece 1", "Eiichiro Oda", "Eiichiro Oda");

	
	AudioBook a1("Harry Potter and Prisoner of Azkaban", "J. K. Rolling","Dale");
	AudioBook a2("Harry Potter and Goblet of Fire", "J. K. Rolling", "Dale");
	AudioBook a3("Harry Potter and Deathly Hollows", "J. K. Rolling", "Dale");
	AudioBook a4("Harry Potter and Half Boold Prince", "J. K. Rolling", "Dale");


	//cout << (b2.getTitle()) <<endl<< (b2.getAuthor()) << endl;
	Customer c1("Peter", "Jackson");

	c1.purchaseBook(&b1, 54.21);
	c1.purchaseBook(&b1, 54.21);
	c1.purchaseBook(&b2, 54.21);
	c1.purchaseBook(&b3, 54.21);
	c1.purchaseBook(&g1, 34.21);
	c1.purchaseBook(&a1, 14.21);
	c1.purchaseBook(&a2, 14.21);
	c1.returnBook(&a2);

	c1.returnBook(&b1);
	c1.returnBook(&b3);
	//c1.returnBook(&b3);

	c1.tradeInBook(&b4, 20.45);
	
	vector<string> v = c1.getHistory();

	cout << c1.getFirstName() << " " << c1.getLastName() << " Balance: " << c1.getBalance() << endl;
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << endl;
	}
	cout << endl;
	SeniorCustomer c2("Hillary", "Clinton");

	c2.purchaseBook(&b1, 54.21);
	c2.purchaseBook(&b1, 54.21);
	c2.purchaseBook(&b2, 54.21);
	c2.purchaseBook(&b3, 54.21);
	c2.purchaseBook(&g1, 34.21);
	c2.purchaseBook(&a1, 14.21);
	c2.purchaseBook(&a2, 14.21);
	c2.returnBook(&a2);
	c2.returnBook(&b1);
	c2.returnBook(&b3);
	c2.returnBook(&b3);
	
	c2.tradeInBook(&b4, 20.45);

	vector<string> v2 = c2.getHistory();

	cout << c2.getFirstName() << " " << c2.getLastName() << " Balance: " << c2.getBalance() << endl;
	for (int i = 0; i < v2.size(); i++)
	{
		cout << v2[i] << endl;
	}

	GoldCustomer c3("Dexter", "Morgan");

	c3.purchaseBook(&b1, 54.21);
	c3.purchaseBook(&b1, 54.21);
	c3.purchaseBook(&b2, 54.21);
	c3.purchaseBook(&b3, 54.21);
	c3.purchaseBook(&g1, 34.21);
	c3.purchaseBook(&a1, 14.21);
	c3.purchaseBook(&a2, 14.21);
	c3.returnBook(&a2);
	c3.returnBook(&b1);
	c3.returnBook(&b3);
	c3.returnBook(&b3);

	c3.tradeInBook(&b4, 20.45);

	vector<string> v3 = c3.getHistory();

	cout << c3.getFirstName() << " " << c3.getLastName() << " Balance: " << c3.getBalance() << endl;
	for (int i = 0; i < v3.size(); i++)
	{
		cout << v3[i] << endl;
	}
	*/
	/*
	CustomerManagement c;
	c.setFileName("cTest.txt");
	c.CreateCustomerList();
	*/
/*
	InventoryManagement i;
	i.setFileName("iTest.txt");
	i.CreateInventory();
	*/

	//b.setFileNames("cTest.txt", "iTest.txt", "coTest.txt");
	//b.setFileNames("customers.txt", "Inventory.txt", "commands.txt");

	//while (1) {
	{
		BookStore b;
		b.setFileNames(argv[2], argv[1], argv[3]);
		b.BuildCustomerList();
		b.BuildInventory();

		b.CreateTransactions();
	    b.RunTransaction();
	}
	//}

/*
cout << argc << endl;
for (int i = 1; i < argc; i++)
{
	cout << argv[i] << endl;;
}*/
	//_CrtDumpMemoryLeaks();

	return 0;

}

