#pragma once
#include <string>
#include <cctype>

class Id {
public:
	Id();
	Id(const int& id);
	
	bool isValid() const;
	
private:
	int m_id;
};

