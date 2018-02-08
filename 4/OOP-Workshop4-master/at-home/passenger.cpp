// TODO: add your headers here
#include <iostream>
#include "passenger.h"
#include <string.h>
// TODO: add the namespaces that you will be using here
using namespace std;
// TODO: holiday namespace here
namespace holiday {
	// TODO: add the default constructor here
	Passenger::Passenger() {
		 m_name[0] = '\0'; 
		 m_destination[32] = '\0'; //name of destination
		 m_departureYear = 0;
		 m_departureMonth = 0;
		 m_departureDay = 0;
	};
	// TODO: add the constructor with 2 parameters here
	Passenger::Passenger(const char* name, const char* destination, int departureYear, int departureMonth, int departuredate)
	{
		m_name[0] = '\0';
		m_destination[0] = '\0';
		m_departureYear = 0;
		m_departureMonth = 0;
		m_departureDay = 0;

		if (name != nullptr)
		{
			if (name[0] != '\0')
			{
				strcpy(m_name, name);
			}
		}
		else
		{
			return;
		}
		if (destination != nullptr)
		{
			if (destination[0] != '\0')
			{
				strcpy(m_destination, destination);
			}
		}
		else
		{
			return;
		}
		if (departureYear != 0)
		{
			if (departureYear == 2017 || departureYear == 2018 || departureYear == 2019 || departureYear == 2020)
			{
				m_departureYear = departureYear;
			}
		}
		else
		{
			return;
		}
		if (departureMonth != 0)
		{
			if ( departureMonth >= 1 && departureMonth <= 12)
			{
				m_departureMonth = departureMonth;
			}
		}
		else
		{
			return;
		}
		if (departuredate != 0)
		{
			if (departuredate >= 1 && departuredate <= 31)
			{
				m_departureDay = departuredate;
			}
		}
		else
		{
			return;
		}
	}
// TODO: add the canTravelWith(...) function here
	bool Passenger::canTravelWith(const Passenger& name) const
	{
		bool valid;
		if (strcmp(this->m_destination, name.m_destination) == 0 && this->m_departureDay == name.m_departureDay
			&& this->m_departureMonth == name.m_departureMonth && this->m_departureYear == name.m_departureYear)
		{
			valid = true;
		}
		else
		{
			valid = false;
		}
		return valid;
	}
	
	void Passenger::travelWith(const Passenger* arrPassengers, int size)
	{
		bool travel = false;

		for (int i = 0; i < size; i++)
		{
			travel = canTravelWith(arrPassengers[i]);
			if (travel == false)
			{
				i = size;
			}
		}
		if (arrPassengers == nullptr)
		{
			cout << "Nobody can join " << m_name << " on vacation!" << endl;
		}
		else if (travel == true) {
			cout << "Everybody can join " << m_name << " on vacation!" << endl;
			cout << m_name << " will be accompanied by ";
			for (int i = 0; i < size; i++) {
				if (i == size - 1) {
					cout << arrPassengers[i].m_name;
				}
				else {
					cout << arrPassengers[i].m_name << ", ";
				}
			}
			cout << "." << endl;
		}
		else if (travel == false) {
			cout << m_name << " will be accompanied by ";

			for (int i = 0; i < size; i++) {
				if (this->m_departureDay == arrPassengers[i].m_departureDay &&
					this->m_departureMonth == arrPassengers[i].m_departureMonth &&
					this->m_departureYear == arrPassengers[i].m_departureYear) {
					if (i == size - 1) {
						cout << arrPassengers[i].m_name;
					}
					else {
						cout << arrPassengers[i].m_name << ", ";
					}
				}
				else {
					continue;
				}
			}
			cout << "." << endl;
		}
		return;
	}
	// TODO: add the isEmpty() function here
	bool Passenger::isEmpty() const 
	{
		bool empty;
		if (m_name[0] == '\0' || m_destination[0] == '\0' || m_departureDay == 0 || m_departureMonth == 0 || m_departureYear == 0)
		{
			empty = true;
		}
		else
		{
			empty = false;
		}
		return empty;
	}
	// below is the member function already provided
	// TODO: read it and understand how it accomplishes its task
	void Passenger::display(bool nameOnly) const
	{
		if (false == this->isEmpty())
		{
			cout << this->m_name;
			if (false == nameOnly)
			{
				cout << " will travel to " << this->m_destination << ". "
					<< "The journey will start on "
					<< this->m_departureYear << "-"
					<< this->m_departureMonth << "-"
					<< this->m_departureDay
					<< "." << endl;
			}
		}
		else
		{
			cout << "Invalid passenger!" << endl;
		}
	}
}
