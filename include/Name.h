#pragma once
#include <string>
#include <cctype>


class Name
{
public:
	Name();
	Name(const std::string& name);
	void setName(const std::string& name) { m_name = name ; };
	bool isValid() const;
private:
	std::string m_name;
};