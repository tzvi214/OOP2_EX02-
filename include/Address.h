#pragma once
#include <string>
#include <cctype>


class Address 
{
public:
	Address();
	Address(const std::string& address);
	void setAddress(const std::string& address) { m_address = address; };
	std::string getAddress() const { return m_address; };
	bool isValid() const { return true; };

private:
	std::string m_address;
};