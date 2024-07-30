#include "GameManager.h"

GameManager::GameManager() {
	this->InitWindow();
	this->InitStates();
}

GameManager::~GameManager() {
	delete this->window;
}

void GameManager::InitWindow() {
	std::string title = fmt::format("Rhythm Avoider [{0}]", VERSION);
	sf::VideoMode windowBounds(600, 600 + BOTTOM_UI_HEIGHT);
    unsigned int frameRateLimit = 60;
    bool verticalSyncEnabled = false;

    this->window = new sf::RenderWindow(windowBounds, title);
}
