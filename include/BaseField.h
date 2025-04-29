#pragma once
#include <string>

class BaseField
{
public:
	
	virtual bool isValid() const = 0;
	virtual ~BaseField() = default;
private:

};
