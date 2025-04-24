#pragma once
#include <string>
#include <cctype>

class Id {
public:
	Id();
	Id(const int& id);
	void setId(const int & id) { m_id = id; };
	int  getId() const { return m_id; };
	bool isValid() const;

	
private:
	int m_id;
	
};

