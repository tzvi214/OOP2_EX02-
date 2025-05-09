#pragma once
#include <string>
#include <cctype>
#include "Validator.h"

class NumGuests : public Validator<int>
{
public:
	NumGuests(int&);
	bool isValid() const;
	int getNumOfGuests() const { return m_validator ; }
};