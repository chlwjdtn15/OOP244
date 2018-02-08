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

#include <iostream>
#include "kingdom.h"
#include <string.h>

using namespace std;
using namespace westeros;

int main(void)
{
	int count = 0; // the number of kingdoms in the array
	
	// TODO: declare the kingdoms pointer here (don't forget to initialize it)

	Kingdom* pKingdoms = nullptr;


	cout << "==========" << endl
		 << "Input data" << endl
		 << "==========" << endl
		 << "Enter the number of kingdoms: ";
	cin >> count;
	cin.ignore();
	// TODO: allocate dynamic memory here for the kingdoms pointer
	pKingdoms = new Kingdom[count];

	

	for (int i = 0; i < count; ++i)
	{
		// TODO: add code to accept user input for the kingdoms array
		cout << "Enter the name for kingdom #" << i + 1 << ": ";
		cin >> pKingdoms[i].m_name;

		cout << "Enter the number people living in " << pKingdoms[i].m_name << ": ";

		cin >> pKingdoms[i].m_population;
		
	}

	cout << "==========" << endl << endl;
	cout << "------------------------------" << endl
		<< "The first kingdom of Westeros" << endl
		<< "------------------------------" << endl;
	display(pKingdoms[0]);
	cout << "------------------------------" << endl << endl;

	display(pKingdoms, count);
	cout << endl;

	display(pKingdoms, count, 345678);
	cout << endl;

	display(pKingdoms, count, "Mordor");
	cout << endl << endl;

	display(pKingdoms, count, "The_Vale");
	cout << endl;
	
	
	// TODO: deallocate the dynamic memory here
	delete[] pKingdoms;
	pKingdoms = nullptr;

	return 0;
}
