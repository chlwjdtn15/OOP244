
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>
#include "PosApp.h"
#include "NonPerishable.h"
#include "Perishable.h"
#include "Item.h"
#include <string.h>
#include <string>
using namespace std;

namespace ict {


	PosApp::PosApp(const char*filename, const char* billfname) {
		m_filename[0] = '\0';
		m_billfname[0] = '\0';
		strncpy(m_filename, filename, 128);
		strncpy(m_billfname, billfname, 128);
		m_noOfItems = 0;
		loadRecs();
	}

	int PosApp::menu() {
		int n = 0;

		cout << "The Sene-Store" << endl;
		cout << "1- List items" << endl;
		cout << "2- Add Perishable item" << endl;
		cout << "3- Add Non-Perishable item" << endl;
		cout << "4- Update item quantity" << endl;
		cout << "5- Show Item" << endl;
		cout << "6- POS" << endl;
		cout << "0- exit program" << endl;
		cout << "> ";
		cin.clear();
		cin >> n;
	
		if (cin.fail() || (n <0 || n > 6))
		{
			n = -1;
			cin.clear();
		}
		cin.ignore(100, '\n');
		cout << endl;
		return n;
	}

	void PosApp::deallocateItems()
	{
		for (int i = 0; i < m_noOfItems; i++) 
		{
			delete m_items[i];
		}
		m_noOfItems = 0;
	}

	
	void PosApp::loadRecs() {

		deallocateItems();
		fstream ftr;
		ftr.open(m_filename, ios::in);


		if (ftr.fail()) {
			ftr.clear();
			ftr.close();
			ftr.open(m_filename, ios::out);
			ftr.close();
		}
		else  {
			char id;
	
			while (!ftr.fail()) {	
				id = ftr.get();
		
				if (ftr.good()) {
		
					if (id == 'N' || id == 'P') {
						ftr.ignore(1, ',');

						switch (id) {
						case 'N':
							m_items[m_noOfItems] = new NonPerishable;
							break;
						case 'P':
							m_items[m_noOfItems] = new Perishable;
							break;
						}
						m_items[m_noOfItems]->load(ftr);
						m_noOfItems++;
					}
				}
			}
			ftr.clear();
		}
	}

	void PosApp::saveRecs() {

		fstream ftw;


		ftw.open(m_filename, ios::out);

		for (int i = 0; i < m_noOfItems; i++) {

			if (m_items[i]->quantity() >= 0)
			{
				m_items[i]->save(ftw);
				ftw << endl;
			}
		}
		ftw.close();
		loadRecs();
	}


	int PosApp::searchItems(const char* sku)const 
	{

		int n = 0;
		int items;

		for (int i = 0; i < m_noOfItems; i++)
		{
			if (*m_items[i] == sku)
			{
				items = i;
				n++;
			}
		}
		if (n == 0)
		{
			return -1;
		}
		else
		{
			return items;
		}
	}
//External Source #1
	void PosApp::updateQty() {

		cout << "Please enter the SKU: ";


		char sku[MAX_SKU_LEN+1];
		cin >> sku;
		
		
		int a = 0;
		int item = searchItems(sku);
		int Squantity;

		if (item == -1) {
			cout << "Not found!" << endl << endl;
		}

		else {
		
			m_items[item]->write(cout, false);

			cout << endl;
			cout << "Please enter the number of purchased items: ";

			
			cin >> Squantity;

			if (cin.fail()) {

				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Invalid Quantity value!" << endl << endl;
			}
			else {
				a += m_items[item]->quantity() + Squantity;
				m_items[item]->quantity(a);
				cout << "Updated!" << endl << endl;
			}
		}

	}
//External source #2
	void PosApp::addItem(bool isPerishable) {


		Item *item = nullptr;
		if (isPerishable == true) 
		{
			item = new Perishable;
		}
		else
		{
			item = new NonPerishable;
		}
		cin >> *item;

		if (cin.fail()) 
		{
			cout << *item << endl<<endl;
			cin.clear();
			cin.ignore(1000, '\n');
		}
		else  
		{

			m_items[m_noOfItems++] = item;

			cout << "Item added." << endl<<endl;
		}
	}

	void PosApp::listItems() const {
		double cost = 0;

		cout << " Row | SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "-----|--------|--------------------|-------|---|----|---------|" << endl;

		for (int i = 0; i < m_noOfItems; i++) 
		{
			cost += m_items[i]->cost() * m_items[i]->quantity();
			cout << setw(4) << right << i + 1 << " | " << *m_items[i] << endl;
		}
		cout << "-----^--------^--------------------^-------^---^----^---------^" << endl;
		cout << setfill(' ') << right << setw(48) << "Total Asset: $  |"
			<< setw(14) << fixed << showpoint << cost << "|" << endl;
		cout << "-----------------------------------------------^--------------^" << endl;
		cout << endl;
	}


	void PosApp::truncateBillFile()
	{
		fstream ftw;

		ftw.open(m_billfname, ftw.out | ftw.trunc);
	
		ftw.close();
	}

//External source #3
	void PosApp::showBill() {
		char id;
		Item *item = nullptr;
		double total = 0;

		fstream ftp;
		ftp.open(m_billfname, ios::in);

		cout << "v--------------------------------------------------------v" << endl;

		cout << "| ";
		Date current;
		current.write();
		cout << setfill(' ') << right << setw(39) << " |" << endl;


		cout << "| SKU    | Item Name          | Price |TX |Qty |   Total |" << endl;
		cout << "|--------|--------------------|-------|---|----|---------|" << endl;

		while (!ftp.fail()) {

			id = ftp.get();
			ftp.ignore(50, ',');
			if (id == 'P' || id == 'N') {
				if (id == 'P') {
					item = new Perishable;
				}

				else if (id == 'N') {
					item = new NonPerishable;
				}
				cout << "| ";
				item->load(ftp);
				item->write(cout, true);

				cout << endl;
				total += item->cost();
				delete item;
			}
		}
		cout << "^--------^--------------------^-------^---^----^---------^" << endl;
		cout << "|" << setfill(' ') << right << setw(42) << "Total: $  |"
			<< setw(14) << fixed << showpoint << total << "|" << endl;
		cout << "^-----------------------------------------^--------------^" << endl;
		ftp.clear();
		ftp.close();
		truncateBillFile();
	}


	void PosApp::addToBill(Item& I) {

		fstream ftw;
		ftw.open(m_billfname, ios::out | ios::app);

		int tempQuantity = I.quantity();

		I.quantity(1);
		I.save(ftw);
		ftw << endl;
		tempQuantity--;
		I.quantity(tempQuantity);
		saveRecs();

		ftw.close();
	}

	void PosApp::POS() {


		bool pass = false;
		char getsku[MAX_SKU_LEN + 1];
		int index = 0;

		while (!pass) {
			cout << "Sku: ";
			cin.getline(getsku, MAX_SKU_LEN, '\n');
			if (getsku[0] == '\0')
			{
				showBill();
				pass = true;
			}
			else {

				index = searchItems(getsku);
				if (index != -1) 
				{
					cout << "v------------------->" << endl;
					cout << "| " << m_items[index]->name() << endl;
					cout << "^------------------->" << endl;
					addToBill(*m_items[index]);
				}
				else
				{
					cout << "Not found!" << endl;
				}
			}
		}
	}

	void PosApp::run()
	{
		string sku;
		int m;
		//char inSku[] = "";
		int opt;
		while ((opt = menu()) != 0) {

			switch (opt) {
			case 1:
				listItems();
				break;
			case 2:
				addItem(true);
				break;
			case 3:
				addItem(false);
				break;
			case 4:
				updateQty();
				break;
			case 5:
				cout << "Please enter the SKU: ";
				getline(cin, sku);
				m = searchItems(sku.c_str());
				if (m != -1) {
					cout << "v-----------------------------------v" << endl;
					m_items[m]->write(cout, false);
					cout << "^-----------------------------------^" << endl;
				}
				else if (m == -1) {
					cout << "Not found!" << endl;
				}
				cout << endl;
				break;
			case 6:
				POS();
				cout << endl;
				break;
			default:
				cout << "===Invalid Selection, try again===" << endl;
				cout << endl;
			}
		}
		cout << "Goodbye!" << endl;
	}
}

