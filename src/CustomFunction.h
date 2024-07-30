#pragma once
#include "header/stdafx.h"

class CustomMath {
public:
    static const int NONE = -1;

    static sf::Vector2f GetCenterPos(float x = NONE, float y = NONE, float width = 0.f, float height = 0.f);
    static float GetLength(const sf::Vector2f& vector);
    static sf::Vector2f Normalize(const sf::Vector2f& vector);
	// static bool CheckCollision();
	static float GetRandomAngle();
};