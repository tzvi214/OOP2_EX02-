#ifndef HOTELBOOKINGFORM_H
#define HOTELBOOKINGFORM_H

#include "BookingForm.h"
class HotelBookingForm : public BookingForm {
public:
    HotelBookingForm(sf::RenderWindow& win, DialogueManager* manager);
    std::string getFormType() const override;
    void render(sf::RenderWindow& window) override;
    void handleInput(sf::Event event) override;
private:
    void setDefaultValues() override;
    std::array<std::string, 4> roomTypeSelection = {"Single Room","Double Room","Family Room","Presidential Suite"};
	int selectedRoomType = 0;
    const int m_numOfFields = 9;
    void analyzedVec();
};

#endif // HOTELBOOKINGFORM_H
