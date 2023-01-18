#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class wygrana
{
public:
	wygrana(); //konstruktor
	void draw(sf::RenderWindow& window); //do rysowania
	int wygrane; //zmienna wygrane do odczytywania z pliku
private:
	sf::Font ksztaltLiter; //do czcionki
	sf::Text win; //do tekstu
	sf::Text WIN;
	sf::Text WYGRANE;

	sf::Texture tlo5; //tekstura
	sf::Sprite tlo55; //i sprite
};