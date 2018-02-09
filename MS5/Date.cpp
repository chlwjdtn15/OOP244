#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <ctime>
#include "Date.h"
#include "POS.h"

using namespace std;
namespace ict {
	v	void Date::set() {
		time_t t = time(NULL);
		tm lt = *localtime(&t);
		m_day = lt.tm_mday;
		m_mon = lt.tm_mon + 1;
		m_year = lt.tm_year + 1900;
		if (dateOnly()) {
			m_hour = m_min = 0;
		}
		else {
			m_hour = lt.tm_hour;
			m_min = lt.tm_min;
		}
	}

	int Date::value()const {
		return m_year * 535680 + m_mon * 44640 + m_day * 1440 + m_hour * 60 + m_min;
	}

	void Date::errCode(int errorCode) {
		m_readErrorCode = errorCode;
	}

	int Date::mdays()const {
		int days[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31, -1 };
		int mon = m_mon >= 1 && m_mon <= 12 ? m_mon : 13;
		mon--;
		return days[mon] + int((mon == 1)*((m_year % 4 == 0) && (m_year % 100 != 0)) || (m_year % 400 == 0));
	}

	void Date::set(int year, int mon, int day, int hour, int min) {

		m_year = year;
		m_mon = mon;
		m_day = day;
		m_hour = hour;
		m_min = min;
		m_readErrorCode = NO_ERROR;
	}
	// constructors
	Date::Date() {
		m_dateOnly = false;
		set();
	}
	Date::Date(int year, int mon, int day) {
		m_dateOnly = true;
		set(year, mon, day, 0, 0);
	}
	Date::Date(int year, int mon, int day, int hour, int min) {
		m_dateOnly = false;
		set(year, mon, day, hour, min);
	}

	// operators
	bool Date::operator==(const Date& D)const {
		return(value() == D.value());
	}

	bool Date::operator!=(const Date& D)const {
		return(value() != D.value());
	}
	bool Date::operator<(const Date& D)const {
		return  (value() < D.value());
	}
	bool Date::operator>(const Date& D)const {
		return (value() > D.value());
	}
	bool Date::operator<=(const Date& D)const {
		return (value() <= D.value());
	}
	bool Date::operator>=(const Date& D)const {
		return(value() >= D.value());

	}


	//methods
	int Date::errCode()const 
	{
		return m_readErrorCode;
	}
	bool Date::bad()const
	{
		return (m_readErrorCode != NO_ERROR);
	}

	bool Date::dateOnly()const
	{
		return m_dateOnly;
	}
	void Date::dateOnly(bool value) {
		m_dateOnly = value;
		if (value) 
		{
			m_hour = 0;
			m_min = 0;
		}
	}

	std::istream& Date::read(std::istream& istr) {


		if (m_dateOnly) {

			istr >> m_year;
			istr.ignore();
			istr >> m_mon;
			istr.ignore();
			istr >> m_day;


			if (m_year<MIN_YEAR || m_year>MAX_YEAR)
			{
				errCode(YEAR_ERROR);
			}
			else if (m_mon < 1 || m_mon>12)
			{
				errCode(MON_ERROR);
			}
			else if (m_day < 1 || m_day > mdays())
			{
				errCode(DAY_ERROR);
			}
			else
			{
				errCode(NO_ERROR);
			}
			if (istr.fail())
			{
				errCode(CIN_FAILED);
			}

		}
		else {

			istr >> m_year;
			istr.ignore();
			istr >> m_mon;
			istr.ignore();
			istr >> m_day;
			istr.ignore();
			istr >> m_hour;
			istr.ignore();
			istr >> m_min;

			if (m_year<MIN_YEAR || m_year>MAX_YEAR)
			{
				errCode(YEAR_ERROR);
			}
			else if (m_mon < 1 || m_mon>12)
			{
				errCode(MON_ERROR);
			}
			else if (m_day < 1 || m_day > mdays())
			{
				errCode(DAY_ERROR);
			}
			else if (m_hour < 0 || m_hour > 24)
			{
				errCode(HOUR_ERROR);
			}
			else if (m_min < 0 || m_min > 59)
			{
				errCode(MIN_ERROR);
			}
			else
			{
				errCode(NO_ERROR);
			}
			if (istr.fail())
			{
				errCode(CIN_FAILED);
			}
		}
		return istr;
	}

	std::ostream& Date::write(std::ostream& ostr)const {


		if (m_dateOnly)
		{
			ostr << m_year << "/" << m_mon << "/" << m_day;
		}
		else if (!m_dateOnly)
		{
			ostr << m_year << "/" << m_mon << "/" << m_day << ", " << m_hour << ":" << m_min;
			return  ostr;
		}
	}

	std::istream& operator >> (std::istream& istr, Date &d)
	{
		return d.read(istr);
	}


	std::ostream& operator << (std::ostream &ostr, const Date &d)
	{
		return d.write(ostr);
	}
}
