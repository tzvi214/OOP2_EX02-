#include "Name.h"

Name::Name()

{
}
//------------------------------
Name::Name(const std::string& name)
	: m_name(name)
{}
//------------------------------
bool Name::isValid() const
{
	if (m_name.empty())
		return false;
	for (char c : m_name)
	{
		if (std::isdigit(c) || c == ' ')
			return false;
	}
	return true;
}