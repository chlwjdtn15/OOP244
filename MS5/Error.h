#ifndef ICT_ERROR_H_
#define ICT_ERROR_H_

#include <iostream>

using namespace std;

namespace ict
{
	class Error {
		char* m_message;

	public:
	
		Error();
		Error(const char*);
		~Error();

		void operator=(const char* errorMessage);

		void clear();
		bool isClear() const;
		void message(const char*);

		operator const char*() const;
		operator bool()const;
		friend ostream & operator<<(ostream & cout, const Error & error);
	};
	ostream & operator<<(ostream & cout, const Error & error);
	
}

#endif