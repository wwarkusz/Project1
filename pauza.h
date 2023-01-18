#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class pauza
{
public:
	void draw(sf::RenderWindow& window); //do rysowania
	pauza(); //konstruktor

private:
	sf::RectangleShape rectangle; //tworzenie prostokata

	sf::Font ksztaltLiter; //do czcionki
	sf::Text stop; //do tekstu
};

