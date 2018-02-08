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


// TODO: include the necessary headers
#include "kingdom.h"
#include <iostream>
#include <string.h>
using namespace std;
// TODO: the westeros namespace
namespace westeros {

	void display(Kingdom& pKingdoms)
	{
		
		
		cout << pKingdoms.m_name << ", population " << pKingdoms.m_population << endl;
		
	}

	void display(Kingdom* pKingdoms, int size)
	{
		int total = 0;
		cout << "------------------------------" << endl
			<< "Kingdoms of Westeros" << endl
			<< "------------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << ". " << pKingdoms[i].m_name << ", population " << pKingdoms[i].m_population << endl;
			total += pKingdoms[i].m_population;
		}
		cout << "------------------------------" << endl;
		cout << "Total population of Westeros: " << total << endl;
		cout << "------------------------------" << endl;
	}

	void display(Kingdom* pKingdoms, int size, int min)
	{
		cout << "------------------------------" << endl;
		cout << "Kingdoms of Westeros with more than " << min << " people" << endl;
		cout << "------------------------------" << endl;
		for (int i = 0; i < size; i++)
		{
			if (pKingdoms[i].m_population >= min)
			{
				cout << pKingdoms[i].m_name << ", population " << pKingdoms[i].m_population << endl;
			}
		}
		cout << "------------------------------" << endl;
	}

	void display(Kingdom* pKingdoms, int size, const char* name)
	{
		bool found = false;
		cout << "------------------------------" << endl;
		cout << "Searching for kingdom " << name << " in Westeros" << endl;
		cout << "------------------------------" << endl;

		for (int i = 0; i < size; i++)
		{
			if (strcmp (pKingdoms[i].m_name, name) == 0)
			{
				found = true;
				cout << name << ", population " << pKingdoms[i].m_population << endl;
			}
		}
		if (!found)
		{
			cout << name << " is not part of Westeros." << endl;
		}
		cout << "------------------------------" << endl;
	}
}

