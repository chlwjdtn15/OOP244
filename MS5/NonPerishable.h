#ifndef ICT_NONPERISHABLE_H__
#define ICT_NONPERISHABLE_H__

#include "Error.h"
#include "Item.h"

namespace ict {

	// class NonPerishable
	class NonPerishable : public Item
	{
	private:
		Error m_err;

	protected:
		bool ok() const;

		void error(const char*);

		virtual char signature() const;

		void clear();
	
	public:

		fstream& save(fstream&) const;

		fstream& load(fstream&);

		ostream& write(ostream&, bool) const;

		istream& read(istream&);

	};

}

#endif