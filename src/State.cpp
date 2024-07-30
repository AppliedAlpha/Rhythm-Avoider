#include "State.h"

State::State(sf::RenderWindow* window) {
	this->window = window;
	this->quit = false;
}

State::~State() = default;

const bool& State::GetQuit() const {
	return this->quit;
}

void State::CheckForQuit() {
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
		this->quit = true;
	}
}

int State::EndState() {
	return 0;
}

void State::UpdateInput(const float& dt) {
	
}

void State::Update(const float& dt) {
	this->CheckForQuit();

	this->UpdateInput(dt);
}

void State::Render(sf::RenderTarget* target) {
	if (!target)
		target = this->window;
}