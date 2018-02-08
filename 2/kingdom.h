// OOP244 Workshop ??: ??????????
// File ???????
// Version 1.0
// Date ???????????
// Author ?????????
// Description
// ?????????????????????
//
//
// Revision History
///////////////////////////////////////////////////////////
// Name     Date    Reason
// 
///////////////////////////////////////////////////////////


// TODO: header safeguards
#ifndef KINGDOM_H_
#define KINGDOM_H_

// TODO: westeros namespace
namespace westeros {

// TODO: define the class Kingdom in the westeros namespace
	
	
	class Kingdom {
	public:
		char m_name[32];
		int m_population;
	};
	
	void display(Kingdom& pKingdoms);

	void display(Kingdom* pKingdoms, int size);

	void display(Kingdom* pKingdoms, int size, int min);

	void display(Kingdom* pKingdoms, int size, const char* name);

}
/*
= struct Kingdom {
	char m_name[32];
	int m_population;
	};
*/

// TODO: add the declaration for the function display(...),
//         also in the westeros namespace

#endif