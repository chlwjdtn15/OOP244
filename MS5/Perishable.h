#ifndef ICT_PERISHABLE_H__
#define ICT_PERISHABLE_H__

#include "Date.h"
#include "NonPerishable.h"

namespace ict {

	// class Perishable
	class Perishable : public NonPerishable
	{
	private:
		Date m_expiry;

	protected:
		char signature() const 
			{ return 'P'; }

	public:
		Perishable();

		fstream& save(fstream&) const;

		fstream& load(fstream&);

		ostream& write(ostream&, bool) const;

		istream& read(istream&);
	};

}



#endif
