#pragma once


template <typename T>
class Validator 
{
public:
	template <typename T>
	Validator(T& validator) :
		m_validator(validator) {}
  virtual bool isValid() const = 0 ;

protected:
	T m_validator;
};
