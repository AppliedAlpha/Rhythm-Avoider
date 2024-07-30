#include "CustomFunction.h"

sf::Vector2f CustomMath::GetCenterPos(float x, float y, float width, float height) {
    if (x == CustomMath::NONE)
        x = (600 - width) / 2;
    
    if (y == CustomMath::NONE)
        y = ((600 + BOTTOM_UI_HEIGHT) - height) / 2;
    
    return {x, y};
}

float CustomMath::GetLength(const sf::Vector2f& vector) {
	return std::sqrt(vector.x * vector.x + vector.y * vector.y);
}

sf::Vector2f CustomMath::Normalize(const sf::Vector2f& vector) {	
	float length = CustomMath::GetLength(vector);
	
	if (length != 0.0f)
		return {vector.x / length, vector.y / length};
	else 
		return vector;
}

// bool CustomMath::CheckCollision() { }

float CustomMath::GetRandomAngle() {
	// set rand seed to current time
	std::srand(static_cast<unsigned int>(std::time(nullptr)));

	return (std::rand() % 360) * 3.141592 / 180;
}
