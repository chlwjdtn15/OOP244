#define _CRT_SECURE_NO_WARNINGS  
#include <iostream>
#include <string.h>
#include <string>
#include "Item.h"
#include "POS.h"
#include "PosIO.h"
using namespace std;
namespace ict {

	Item::Item() {
		m_sku[0] = '\0';
		m_name = nullptr;
		m_price = 0;
		m_taxed = true;
		m_quantity = 0;
	}

	Item::Item(const char *sku, const char *name, const double price, const bool tax) {

		m_price = price;
		m_taxed = tax;
		m_quantity = 0;
		m_sku[0] = '\0';
		m_name = nullptr;

		if (sku[0] != '\0' && sku != nullptr)
			strcpy(m_sku, sku);
		if (name[0] != '\0' && name != nullptr)
		{
			m_name = new char[strlen(name) + 1];
			strcpy(m_name, name);
		}
	}

	Item::Item(const Item &cItem) {

		m_price = cItem.m_price;
		m_taxed = cItem.m_taxed;
		m_quantity = cItem.m_quantity;
		m_sku[0] = '\0';
		m_name = nullptr;

		if (cItem.m_sku[0] != '\0' && cItem.m_sku != nullptr)
			strcpy(m_sku, cItem.m_sku);

		if (cItem.m_name[0] != '\0' && cItem.m_name != nullptr) {
			m_name = new char[strlen(cItem.m_name) + 1];
			strcpy(m_name, cItem.m_name);
		}
	}

	Item& Item::operator=(const Item& other) {
		if (other.m_sku[0] == '\0' && other.m_name == nullptr && other.m_price == 0 && other.m_taxed == true && other.m_quantity == 0)
			return *this;
		else
			m_price = other.m_price;
		m_taxed = other.m_taxed;
		m_quantity = other.m_quantity;

		strcpy(m_sku, other.m_sku);

		m_name = new char[strlen(other.m_name) + 1];
		strcpy(m_name, other.m_name);
		return *this;
	}


	Item::~Item() {
		delete[]m_name;
		m_name = nullptr;
	}


	void Item::sku(char* other) {
		strcpy(m_sku, other);
	}
	void Item::price(double other) {
		m_price = other;
	}
	void Item::name(char* other) {
		m_name = new char[strlen(other) + 1];
		strcpy(m_name, other);
	}
	void Item::taxed(bool other) {
		m_taxed = other;
	}
	void Item::quantity(int other) {
		m_quantity = other;
	}

	//getter
	const char* Item::sku()const {
		return m_sku;
	}

	const double Item::price()const {
		return m_price;
	}

	const char* Item::name() const {
		return m_name;
	}
	const bool Item::taxed() const {
		return m_taxed;
	}
	const int Item::quantity() const {
		return m_quantity;
	}

	// calculate price
	const double Item::cost() const {
		if (taxed())
			return m_price*(1 + TAX);
		else
			return m_price;
	}
	// return true if memebers are in empty 
	const bool Item::isEmpty() const {
		if (m_sku[0] == '\0' && m_name == nullptr && m_price == 0 && m_taxed == true && m_quantity == 0)
			return true;
		else
			return false;
	}


	bool Item::operator==(const char*other)const {
		if (strcmp(m_sku, other) == 0)
			return true;
		else
			return false;

	}
	int  Item::operator+=(const int other) {

		return m_quantity += other;

	}
	int  Item::operator-=(const int other) {
		return m_quantity -= other;
	}
	// non-member overload
	double operator+=(double& d, const Item& I) {
		return d += I.price() * I.quantity();
	}

	std::ostream& operator<< (std::ostream& cout, const Item& it) {
		it.write(cout,true);
		return cout;
	}

	std::istream& operator >> (std::istream& cin, Item& it) {
		it.read(cin);
		return cin;
	}

}