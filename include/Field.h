#pragma once
#include <string>
#include "BaseField.h" 
template <typename T>
class Field : public BaseField
{
public:
	
	Field(const T& validator) :
		m_val(validator) {
	}
         bool isValid() const;  
private:
	T m_val;
	// std::string m_name;	
};
//-------------------------------------------------------
template<typename T>
bool Field<T>::isValid() const
{
	return m_val.isValid();
}
