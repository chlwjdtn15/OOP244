#ifndef ICT_ITEM_H__
#define ICT_ITEM_H__
// inlcude PosIO and POS header files
#include "PosIO.h"
#include "POS.h"
namespace ict {
	// class Item
	class Item : public PosIO
	{
	private:
		char   m_sku[MAX_SKU_LEN + 1];
		char   *m_name;
		double m_price;
		bool   m_taxed;
		int    m_quantity;


	public:
		Item();
		Item(const char *sku, const char *name, const double price, const bool tax = true);
		Item(const Item &cItem);

		virtual ~Item();


		Item& operator=(const Item& other);


		void sku(char* other);
		void price(double other);
		void name(char* other);
		void taxed(bool other);
		void quantity(int other);

		const char* sku()const;
		const double price()const;
		const char* name() const;
		const bool taxed() const;
		const int quantity() const;
		const double cost() const;
		const bool isEmpty() const;




		bool operator==(const char*other)const;
		int  operator+=(const int other);
		int  operator-=(const int other);
		// end class Item
	};
	// operator += 
	double operator+=(double& d, const Item& I);
	// operator << and operator >>

	std::ostream& operator<<(std::ostream& cout, const Item&it);
	std::istream& operator >> (std::istream& cin, Item&it);
}


#endif