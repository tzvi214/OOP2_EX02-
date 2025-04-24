#pragma once
#include <string>
#include <cctype>


class Email
{
public:
	Email();
	Email(const std::string& email);
	void setEmail(const std::string& email) { m_email = email; };
	std::string getEmail() const { return m_email; };
	//bool isValid() const;


private:
	std::string m_email;
};
