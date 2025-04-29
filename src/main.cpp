//// main.cpp - Entry Point
//#include "Engine.h"
//#include <SFML/Graphics.hpp>
//
//int main() {
//	
//	
//    Engine engine;  //  Create the Engine instance
//    engine.run();   //  Start the loop inside Engine
//    return 0;
//}
#include <iostream>
#include <vector>
#include <memory>
#include "Field.h"
#include "Id.h"
#include "Email.h"
#include "Name.h"
#include "Address.h"

int main() {
	std::vector<std::unique_ptr<BaseField>> fields;

	// תקינים
	int validId = 123456782;  // מספר ת"ז תקני
	std::string validEmail = "example@test.com";
	std::string validName = "John Doe";
	std::string validAddress = "123 Main St";

	// לא תקינים
	int invalidId = 123456789; // לא עובר אלגוריתם ביקורת
	std::string invalidEmail = "no-at-symbol.com";
	std::string invalidName = ""; // ריק
	std::string invalidAddress = " "; // ריק מבחינת משמעות

	// מוסיפים אובייקטים תקינים
	fields.push_back(std::make_unique<Field<Id>>(Id(validId)));
	fields.push_back(std::make_unique<Field<Email>>(Email(validEmail)));
	fields.push_back(std::make_unique<Field<Name>>(Name(validName)));
	fields.push_back(std::make_unique<Field<Address>>(Address(validAddress)));

	// מוסיפים אובייקטים לא תקינים
	fields.push_back(std::make_unique<Field<Id>>(Id(invalidId)));
	fields.push_back(std::make_unique<Field<Email>>(Email(invalidEmail)));
	fields.push_back(std::make_unique<Field<Name>>(Name(invalidName)));
	fields.push_back(std::make_unique<Field<Address>>(Address(invalidAddress)));

	std::cout << "Testing fields validity:\n";

	int index = 1;
	for (const auto& field : fields) {
		std::cout << "Field #" << index++ << " is valid: "
			<< std::boolalpha << field->isValid() << std::endl;
	}
}

