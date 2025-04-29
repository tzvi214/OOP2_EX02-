#pragma once

template <typename T>
class Validator 
{
public:
	virtual ~Validator() = default;

	Validator(T& validator) :
		m_validator(validator) {}

  virtual bool isValid() const = 0 ;
  
protected:
	T m_validator;
};
