#include "TitleState.h"

TitleState::TitleState(sf::RenderWindow* window) : State(window) {
    this->font = new sf::Font();
    this->font->loadFromFile("./resources/font/Arial.ttf");

    this->InitTexts();
}

TitleState::~TitleState() {
    delete this->font;
}

void TitleState::InitTexts() {
    titleText.setFont(*(this->font));
    titleText.setCharacterSize(88);
    titleText.setFillColor(sf::Color::White);
    titleText.setString("Rhythm Avoider");
    titleText.setPosition(CustomMath::GetCenterPos(CustomMath::NONE, 150, titleText.getLocalBounds().width));
}

int TitleState::EndState() {
    return 0;
}

void TitleState::UpdateInput(const float& dt) {
    
}

void TitleState::Update(const float& dt) {
    this->UpdateInput(dt);
    this->CheckForQuit();
}

void TitleState::Render(sf::RenderTarget* target) {
    if (!target)
        target = this->window;

    target->draw(titleText);
}