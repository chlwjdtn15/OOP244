//TODO: add header guards here
#ifndef PASSENGER_H
#define PASSENGER_H
// TODO: holiday namespace here
namespace holiday {
	class Passenger {
		private :
			char m_name[32]; //name of the passenger
			char m_destination[32]; //name of destination
			int m_departureYear;
			int m_departureMonth;
			int m_departureDay;

	public:
		void display(bool onlyNames = false) const;
		Passenger();
		Passenger(const char* name, const char* destination, int departureYear, int departureMonth, int departuredate);
		void travelWith(const Passenger* arrPassengers, int size);
		bool isEmpty() const;
		bool canTravelWith(const Passenger&) const;
	};
	// TODO: declare the class Passenger here
		// TODO: add the class the attributes,
		//       the member function already provided,
		//       and the member functions that you must implement
}
#endif
