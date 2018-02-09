#pragma once
#ifndef SICT_POSAPP_H__
#define SICT_POSAPP_H__
#include "Perishable.h"
#include "NonPerishable.h"
#include "Item.h"
namespace ict {
	class PosApp 
	{

	private:
		
		char m_filename[128];
		char m_billfname[128];
		Item* m_items[MAX_NO_ITEMS];
		int m_noOfItems;


		int menu();
		void deallocateItems();
		void loadRecs();
		void saveRecs();
		int searchItems(const char* sku)const;
		void updateQty();
		void addItem(bool isPerishable);
		void listItems()const;
		void showBill();
		void addToBill(Item& I);
		void POS();
		void truncateBillFile();
	public:
		PosApp(const char* filename, const char* billfname);

		// prevent copying and assignment here!
		
		void run();
	};
}

#endif