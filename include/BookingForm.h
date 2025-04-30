#ifndef BOOKINGFORM_H
#define BOOKINGFORM_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include <array>
#include <memory>
#include <utility>
#include "BaseField.h"
#include "Validator.h"
#include "Field.h"
#include "Name.h"
#include "Id.h"
#include "Address.h"
#include "Email.h"
#include "Date.h"
#include "NumGuests.h"
#include "StartEndDate.h"
#include "ChoiceHotel.h"
#include "RoomGuestMatcher.h"


class DialogueManager;

struct PersonalInfo {
    std::string name;
    std::string id;
    std::string address;
    std::string email;
};

class BookingForm {

protected:
    std::vector<std::string> fieldLabels;
    std::vector<std::string> userInput;
	std::vector<std::unique_ptr<BaseField>> m_fields;

    std::size_t activeField = 0;
    sf::Clock cursorTimer;
    bool showCursor = true;

    sf::RenderWindow& window;
    DialogueManager* formManager;
    PersonalInfo personalInfo;

    virtual void setDefaultValues()=0 ;
    void openConfirmationWindow();//to add in this function the validators

    int stringToInt(const std::string &);
public:
    BookingForm(sf::RenderWindow& win, DialogueManager* manager);
    virtual ~BookingForm() = default;
    virtual std::string getFormType() const = 0;
    virtual void render(sf::RenderWindow& window) = 0;
    virtual void handleInput(sf::Event event) = 0;
};

#endif // BOOKINGFORM_H
