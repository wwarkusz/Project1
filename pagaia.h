#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class pagaia
{
public:
	pagaia();
	void draw(sf::RenderWindow& window);

private:
	sf::RectangleShape paletka;
};

