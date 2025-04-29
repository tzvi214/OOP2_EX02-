#pragma once
#include "Validator.h"
#include <string>
#include <ctime>
#include <iomanip>
#include <sstream>

class Date : public Validator<std::string>
{
public:
	Date();
	Date(std::string&);
	virtual bool isValid() const override;

private:
	const std::string getTodayDate();
};
