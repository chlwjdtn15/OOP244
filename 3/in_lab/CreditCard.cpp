#include "CreditCard.h"
#include <cstring>
#include <iostream>


using namespace std;

namespace sict {
	void CreditCard::name(const char cardHolderName[])
	{
		strcpy(m_cardHolderName, cardHolderName); //strcpy = Copy characters from string
	}

	void CreditCard::initialize(unsigned long long creditCardNumber,
		int instCode,
		int expiryYear,
		int expiryMonth,
		int numberInTheBack)
	{
		m_cardNumber = creditCardNumber;
		m_institutionCode = instCode;
		m_expiryYear = expiryYear;
		m_expiryMonth = expiryMonth;
		m_numberInTheBack = numberInTheBack;
	}

	bool CreditCard::isValid() const
	{
		//if (strlen(m_cardHolderName) > 0)

		return ((m_cardHolderName[0] != '\0') &&
			(m_cardNumber >= MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER) &&
			(m_institutionCode >= MIN_INST_NUMBER && m_institutionCode <= MAX_INST_NUMBER) &&
			(m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR) &&
			(m_expiryMonth >= 1 && m_expiryMonth <= 12) &&
			(m_numberInTheBack > -1 && m_numberInTheBack < 1000));


		/* same thing as above but first one is more prefered.
		if ((m_cardHolderName[0] != '\0') &&
			(m_cardNumber >= MIN_CARD_NUMBER && m_cardNumber <= MAX_CARD_NUMBER) &&
			(m_institutionCode >= MIN_INST_NUMBER && m_institutionCode <= MAX_INST_NUMBER) &&
			(m_expiryYear >= MIN_EXP_YEAR && m_expiryYear <= MAX_EXP_YEAR) &&
			(m_expiryMonth >= 1 && m_expiryMonth <= 12) &&
			(m_numberInTheBack > -1 && m_numberInTheBack < 1000))
		{
			return true;
		}
		else
		{
			return flase;
		}*/
	}	

	void  CreditCard::write() const
	{
		if (isValid() == true)
		{
			cout << "Cardholder: " << m_cardHolderName << endl;
			cout << "Card Number: " << m_cardNumber << endl;
			cout << "Institution: " << m_institutionCode << endl;
			cout << "Expires: " << m_expiryMonth << "/" << m_expiryYear << endl;
			cout << "Number at the back: " << m_numberInTheBack;
		}
	}
}
