#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class opzioni
{
public:
	opzioni();
	void draw(sf::RenderWindow& window);
	void Gora();
	void Dol();

	int opcjaChoosen = 0;

private:

	sf::Font ksztaltLiter;
	sf::Text Opcje[2];
};