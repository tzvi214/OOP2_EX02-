#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) {
    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}
//----------------------------------------------------
int BookingForm::stringToInt(const std::string& str)
{

   if (str.empty()) return 0;

   int result = 0;
   for (char c : str) {
       if (c < '0' || c > '9') return 0; // תו לא מספרי
       result = result * 10 + (c - '0');
   }

   return result;
  
}
//-------------------------------------------
void BookingForm::openConfirmationWindow() {
    const std::string& formTitle = getFormType();
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + formTitle);

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    bool approved = false;

    // הכנת השורות עם צבעים לפי חוקיות
    std::vector<sf::Text> fieldTexts;
    float y = 80.0f;
    for (size_t i = 0; i < fieldLabels.size(); ++i) {
        sf::Text fieldText(fieldLabels[i] + " " + userInput[i], font, 18);
        fieldText.setPosition(50, y);
        fieldText.setFillColor(sf::Color::Black);
        fieldTexts.push_back(fieldText);
        y += 25;

        if (!m_fields[i]->isValid()) {
            sf::Text invalidText("    Invalid input", font, 18);
            invalidText.setPosition(50, y);
            invalidText.setFillColor(sf::Color::Red);
            fieldTexts.push_back(invalidText);
            y += 25;
        }
    }
    for (size_t i = fieldLabels.size(); i < m_fields.size(); ++i) {
        if (!m_fields[i]->isValid()) {
            std::string label = "Field " + std::to_string(i + 1) + " is invalid";
            sf::Text invalidText(label, font, 18);
            invalidText.setPosition(50, y);
            invalidText.setFillColor(sf::Color::Red);
            fieldTexts.push_back(invalidText);
            y += 25;
        }
    }


    float buttonY = y + 30;

    while (confirmWindow.isOpen()) {
        sf::Event event;
        while (confirmWindow.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                confirmWindow.close();

            if (event.type == sf::Event::MouseButtonPressed) {
                float mouseX = event.mouseButton.x;
                float mouseY = event.mouseButton.y;

                if (mouseX >= 280 && mouseX <= 400 && mouseY >= buttonY && mouseY <= buttonY + 45) {
                    confirmWindow.close();
                }
                if (mouseX >= 100 && mouseX <= 220 && mouseY >= buttonY && mouseY <= buttonY + 45) {
                    std::cout << formTitle << " Confirmed! Returning to main menu." << std::endl;
                    approved = true;
                    confirmWindow.close();
                }
            }
        }

        confirmWindow.clear(sf::Color(240, 240, 240));

        sf::Text title("Confirm " + formTitle, font, 22);
        title.setFillColor(sf::Color::Black);
        title.setStyle(sf::Text::Bold);
        title.setPosition(130, 20);
        confirmWindow.draw(title);

        for (auto& txt : fieldTexts)
            confirmWindow.draw(txt);

        // ✅ Approve Button
        sf::RectangleShape approveButton(sf::Vector2f(120, 40));
        approveButton.setPosition(100, buttonY);
        approveButton.setFillColor(sf::Color(50, 150, 50));
        confirmWindow.draw(approveButton);

        sf::Text approveText("APPROVE", font, 18);
        approveText.setFillColor(sf::Color::White);
        approveText.setPosition(118, buttonY + 10);
        confirmWindow.draw(approveText);

        // ✅ Cancel Button
        sf::RectangleShape cancelButton(sf::Vector2f(120, 40));
        cancelButton.setPosition(280, buttonY);
        cancelButton.setFillColor(sf::Color(180, 0, 0));
        confirmWindow.draw(cancelButton);

        sf::Text cancelText("CANCEL", font, 18);
        cancelText.setFillColor(sf::Color::White);
        cancelText.setPosition(305, buttonY + 10);
        confirmWindow.draw(cancelText);

        confirmWindow.display();
    }

    if (approved) {
        formManager->closeForm();
    }
}
