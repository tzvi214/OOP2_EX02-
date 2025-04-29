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
#include "Field.h"
#include "Id.h"
#include "Email.h"

int main() {
	int idVal = 123456782; // מספר תקין לפי אלגוריתם ת"ז
	std::string emailVal = "example@test.com";

	Id id(idVal);
	Email email(emailVal);

	Field<Id> idField(id);
	Field<Email> emailField(email);

	std::cout << "ID is valid: " << std::boolalpha << idField.isValid() << std::endl;
	std::cout << "Email is valid: " << std::boolalpha << emailField.isValid() << std::endl;

	return 0;
}

