#pragma once
#include "CustomFunction.h"
#include "State.h"

class TitleState : public State {
public:
	sf::Font* font;
	sf::Text titleText;

	explicit TitleState(sf::RenderWindow* window);
	~TitleState() override;

	void InitTexts();

	int EndState() override;
	void UpdateInput(const float& dt) override;
	void Update(const float& dt) override;
	void Render(sf::RenderTarget* target) override;

private:
};

