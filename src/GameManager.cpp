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
	this->window->setFramerateLimit(frameRateLimit);
	this->window->setVerticalSyncEnabled(verticalSyncEnabled);
}

void GameManager::InitStates() {
	this->states.push_front(new TitleState(this->window));
}

void GameManager::UpdateDt() {
	this->dt = this->dtClock.restart().asSeconds();
}

void GameManager::UpdateSFMLEvents() {
	while (this->window->pollEvent(this->event)) {
		if (this->event.type == sf::Event::Closed) {
			this->window->close();
		}
	}
}

void GameManager::Update() {
	this->UpdateSFMLEvents();

	if (!this->states.empty()) {
		this->states.front()->Update(this->dt);

		if (this->states.front()->GetQuit()) {
			int res = this->states.front()->EndState();

			if (auto* titleState = dynamic_cast<TitleState *>(this->states.front())) {
				// Ingame Start
			}

			delete this->states.front();
			this->states.pop_front();
		}
	} else {
		this->window->close();
	}
}

void GameManager::Render() {
	this->window->clear();

	if (!this->states.empty()) {
		this->states.front()->Render(this->window);
	}

	this->window->display();
}

void GameManager::Run() {
	while (this->window->isOpen()) {
		this->UpdateDt();
		this->Update();
		this->Render();
	}
}