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
	Passenger::Passenger(const char* name, const char* destination)
	{
		m_name[0] = '\0';
		m_destination[32] = '\0';
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
				m_departureDay = 1;
				m_departureMonth = 7;
				m_departureYear = 2017;
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
		if (strcmp(this->m_destination, name.m_destination) == 0 && (this->m_departureDay == name.m_departureDay)
			&& (this->m_departureMonth == name.m_departureMonth) && (this->m_departureYear == name.m_departureYear))
		{
			valid = true;
		}
		else
		{
			valid = false;
		}
		return valid;
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
