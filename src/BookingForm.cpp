#include "BookingForm.h"
#include "DialogueManager.h"
#include <iostream>
#include <ctime>  // For getting current date

BookingForm::BookingForm(sf::RenderWindow& win, DialogueManager* manager) :window(win), formManager(manager) {
    fieldLabels = { "Name:", "ID:", "Address:", "Email:" };  // ✅ Add common fields
    userInput.resize(fieldLabels.size(), "");  // Initialize input fields
}

void BookingForm::openConfirmationWindow() {
    const std::string& formTitle = getFormType();
    sf::RenderWindow confirmWindow(sf::VideoMode(500, 600), "Confirm " + formTitle);

    sf::Font font;
    font.loadFromFile("C:/Windows/Fonts/arialbd.ttf");

    bool approved = false;

    std::vector<sf::Text> fieldTexts = createFieldTexts(font);
    float buttonY = fieldTexts.back().getPosition().y + 55;

    while (confirmWindow.isOpen()) {
        handleConfirmationEvents(confirmWindow, buttonY, approved, formTitle);

        confirmWindow.clear(sf::Color(240, 240, 240));
        drawConfirmationUI(confirmWindow, font, formTitle, fieldTexts, buttonY);
        confirmWindow.display();
    }

    if (approved) {
        formManager->closeForm();
    }
}
//------------------------------
std::vector<sf::Text> BookingForm::createFieldTexts(const sf::Font& font) {
    std::vector<sf::Text> texts;
    float y = 80.0f;

    for (size_t i = 0; i < fieldLabels.size(); ++i) {
        sf::Text label(fieldLabels[i] + " " + userInput[i], font, 18);
        label.setPosition(50, y);
        label.setFillColor(sf::Color::Black);
        texts.push_back(label);
        y += 25;

		if (m_fields.size() > 0 && !m_fields[i]->isValid()) {// m_fields.size() > 0 because i whant that will work for all the classes
            sf::Text invalid("    Invalid input", font, 18);
            invalid.setPosition(50, y);
            invalid.setFillColor(sf::Color::Red);
            texts.push_back(invalid);
            y += 25;
        }
    }

    return texts;
}
//-------------------------------
void BookingForm::handleConfirmationEvents(sf::RenderWindow& window, float buttonY, bool& approved, const std::string& formTitle) {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }

        if (event.type == sf::Event::MouseButtonPressed) {
            float x = event.mouseButton.x;
            float y = event.mouseButton.y;

            if (x >= 280 && x <= 400 && y >= buttonY && y <= buttonY + 45) {
                window.close();
            }

            if (x >= 100 && x <= 220 && y >= buttonY && y <= buttonY + 45) {
                std::cout << formTitle << " Confirmed! Returning to main menu." << std::endl;
                approved = true;
                window.close();
            }
        }
    }
}
//-------------------------------
void BookingForm::drawConfirmationUI(sf::RenderWindow& window, const sf::Font& font,
    const std::string& formTitle,
    const std::vector<sf::Text>& fieldTexts, float buttonY) 
{
    sf::Text title("Confirm " + formTitle, font, 22);
    title.setFillColor(sf::Color::Black);
    title.setStyle(sf::Text::Bold);
    title.setPosition(130, 20);
    window.draw(title);

    for (const auto& txt : fieldTexts)
        window.draw(txt);

    drawButton(window, font, "APPROVE", sf::Vector2f(100, buttonY), sf::Color(50, 150, 50));
    drawButton(window, font, "CANCEL", sf::Vector2f(280, buttonY), sf::Color(180, 0, 0));
}
//-------------------------------
void BookingForm::drawButton(sf::RenderWindow& window, const sf::Font& font,
    const std::string& text, sf::Vector2f pos, sf::Color color) {
    sf::RectangleShape button(sf::Vector2f(120, 40));
    button.setPosition(pos);
    button.setFillColor(color);
    window.draw(button);

    sf::Text buttonText(text, font, 18);
    buttonText.setFillColor(sf::Color::White);
    buttonText.setPosition(pos.x + 18, pos.y + 10);  // מרכוז מקורב
    window.draw(buttonText);
}
