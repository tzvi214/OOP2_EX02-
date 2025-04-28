#pragma once
#include "Name.h"
#include "Id.h"
#include "Address.h"
#include "Email.h"
#include <string>

class Field
{
public:

	virtual bool isValid() const = 0;
	virtual ~Field() = default;

private:

};
