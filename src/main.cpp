// main.cpp - Entry Point
#include "Engine.h"
#include <SFML/Graphics.hpp>

int main() {
	
	
    Engine engine;  //  Create the Engine instance
    engine.run();   //  Start the loop inside Engine
    return 0;
}
//#include <iostream>
//#include <vector>
//#include <memory>
//#include "Field.h"
//#include "Date.h"
//
//int main() {
//    std::vector<std::unique_ptr<BaseField>> fields;
//
//    std::string validDate = "2025-04-29";
//    std::string invalidDate1 = "2025/04/29"; // תווי מפריד שגויים
//    std::string invalidDate2 = "20250429";   // בלי מפרידים בכלל
//    std::string invalidDate3 = "20a5-04-29"; // תווים לא מספריים
//    std::string invalidDate4 = "2025-4-9";   // פורמט לא מלא
//
//    fields.push_back(std::make_unique<Field<Date>>(Date(validDate)));
//    fields.push_back(std::make_unique<Field<Date>>(Date(invalidDate1)));
//    fields.push_back(std::make_unique<Field<Date>>(Date(invalidDate2)));
//    fields.push_back(std::make_unique<Field<Date>>(Date(invalidDate3)));
//    fields.push_back(std::make_unique<Field<Date>>(Date(invalidDate4)));
//    fields.push_back(std::make_unique<Field<Date>>(Date())); // תאריך של היום
//
//    int index = 1;
//    for (const auto& field : fields) {
//        std::cout << "Date field #" << index++ << " is valid: "
//            << std::boolalpha << field->isValid() << std::endl;
//    }
//}
//
