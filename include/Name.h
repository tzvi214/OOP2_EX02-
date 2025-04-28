#pragma once
#include <string>
#include <cctype>
#include "Validator.h"

class Name : public Validator<std::string>
{
public:
	Name(std::string& name);
	bool isValid() const;
private:

};