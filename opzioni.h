#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class opzioni
{
public:
	opzioni(); //konstruktor
	void draw(sf::RenderWindow& window); //do rysowania
	void Gora(); //do poruszania w gore opcji
	void Dol(); //i w dol

	int opcjaChoosen = 0; //zmienna do wybierania opcji

private:

	sf::Font ksztaltLiter; //do czcionki
	sf::Text Opcje[2]; //do tekstu

	sf::Texture tlo3; //tekstura
	sf::Sprite tlo33; //i sprite
};