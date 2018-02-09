#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <iomanip>
#include "PosIO.h"
#include "Item.h"
#include <string.h>
#include "Perishable.h"
#include "NonPerishable.h"
#include "Date.h"

using namespace std;
namespace ict {

	Perishable::Perishable() : NonPerishable()
	{
		m_expiry.dateOnly(true);
	}

	fstream & Perishable::save(fstream & file) const
	{
		NonPerishable::save(file);
		file << "," << m_expiry;
		return file;
	}

	fstream & Perishable::load(fstream & file)
	{
		NonPerishable::load(file);
		file >> m_expiry;
		file.ignore();
		return file;
	}

	ostream & Perishable::write(ostream & ostr, bool linear) const
	{
		NonPerishable::write(ostr, linear);
		if (ok() && linear==false)
			ostr << "Expiry date: " << m_expiry <<endl ;
		return ostr;
	}
	istream & Perishable::read(istream & istr)
	{
		cout << "Perishable ";
		NonPerishable::read(istr);

		if (NonPerishable::ok())
		{
			cout << "Expiry date (YYYY/MM/DD): ";
			m_expiry.read(istr);
			int errCode = m_expiry.errCode();
			if (errCode >= CIN_FAILED && errCode <= DAY_ERROR)
			{
				switch (errCode)
				{
				case CIN_FAILED:
					error("Invalid Date Entry");
					break;
				case YEAR_ERROR:
					error("Invalid Year in Date Entry");
					break;
				case MON_ERROR:
					error("Invalid Month in Date Entry");
					break;
				case DAY_ERROR:
					error("Invalid Day in Date Entry");
					break;
				default:
					error("Default Date Error");
					break;
				}
				istr.setstate(ios::failbit);
			}
		}
		return istr;
	}
}



