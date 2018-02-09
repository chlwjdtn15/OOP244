#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
#include <string>
#include "NonPerishable.h"
#include "Item.h"
using namespace std;

namespace ict {

	bool NonPerishable::ok() const {
		if (m_err.isClear())
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	void NonPerishable::clear() {
		m_err.clear();
	}
	char NonPerishable::signature() const {
		return 'N';
	}
	void NonPerishable::error(const char* message) {
		m_err.message(message);
	}

	fstream & NonPerishable::save(fstream & file) const
	{
		file << signature() << "," << sku() << "," << name() << "," << price() << "," << taxed() << "," << quantity();

		return file;
	}

	std::fstream& NonPerishable::load(std::fstream& file)
	{
		bool tax;
		double d;
		char a[100];
		int c;
		file.getline(a, MAX_SKU_LEN + 1, ',');
		sku(a);
		file.getline(a, 100, ',');
		name(a);
		file >> d;
		price(d);
		file.ignore();
		file >> tax;
		taxed(tax);
		file.ignore();
		file >> c;
		quantity(c);
		file.ignore();

		return file;
	}
//External source #1
	std::ostream& NonPerishable::write(std::ostream& ostr, bool linear)const {
		if (!ok())
			ostr << m_err;
		else {

			if (linear) {
				ostr.width(MAX_SKU_LEN);
				ostr << std::left << sku() << "|";
				ostr.width(20);
				ostr << std::left << name() << "|";
				ostr.width(7);
				ostr << std::right << std::setprecision(2) << std::fixed << price() << "|";
				ostr << " ";
				if (taxed()) {
					ostr << "T";
				}
				else {
					ostr << " ";
				}
				ostr << signature();
				ostr << '|';
				ostr.width(4);
				ostr << std::right << quantity() << "|";
				ostr.width(9);
				ostr << std::right << cost()*quantity() << "|";
			}

			else {
				if (taxed()) {
					ostr << "Name:" << endl;
					ostr << name() << endl;
					ostr << "Sku: " << sku() <<endl;
					ostr << "Price: " << price() << endl;
					ostr << "Price after tax: " << price()*(1+TAX)<< endl;
					ostr << "Quantity: " << quantity() << endl;
					ostr << "Total Cost: " << cost()*quantity() << endl;
				}
				else if (!taxed()) {
					ostr << "Name:" << endl;
					ostr << name() << endl;
					ostr << "Sku: " << sku() << endl;
					ostr << "Price: " << price() << endl;
					ostr << "Price after tax: N/A" << endl;
					ostr << "Quantity: " << quantity() << endl;
					ostr << "Total Cost: " << cost()*quantity() << endl;
				}

			}
		}

		return ostr;
	}

	istream & NonPerishable::read(std::istream & istr)
	{
		char   Sku[MAX_SKU_LEN + 1];
		char   Name[100];
		double Price;
		char   Staxed;
		int    Quantity;
		bool   pass = true;

		m_err.clear();
		cout << "Item Entry:" << endl;

		cout << "Sku: ";
		istr >> Sku;
		if (istr.fail()) {
			pass = false;
			m_err.message("Invalid SKU Entry");
		}

		if (pass) {
			cout << "Name:" << endl;
			istr.ignore();
			istr.getline(Name, 81, '\n');
			if (istr.fail())
			{
				pass = false;
				m_err.message("Invalid Name Entry");
			}
		}

		if (pass) {
			cout << "Price: ";
			istr >> Price;
			if (istr.fail())
			{
				pass = false;
				m_err.message("Invalid Price Entry");
			}
		}

		if (pass) {
			cout << "Taxed: ";
			istr >> Staxed;
			if (istr.fail() || (Staxed != 'Y' && Staxed != 'y' && Staxed != 'N' && Staxed != 'n'))
			{

				pass = false;
				m_err.message("Invalid Taxed Entry, (y)es or (n)o");
				istr.setstate(std::ios::failbit);
			}
		}


		if (pass)
		{
			cout << "Quantity: ";
			istr >> Quantity;
			if (istr.fail())
			{
				pass = false;
				m_err.message("Invalid Quantity Entry");
			}
		}

		if (pass)
		{
			sku(Sku);
			name(Name);
			price(Price);
			if (Staxed == 'Y' || Staxed == 'y')
				taxed(true);
			else
				taxed(false);
			quantity(Quantity);
		}

		return istr;
	}

}
