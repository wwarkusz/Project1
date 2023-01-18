#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class menu
{
public:
	menu(); //konstruktor
	void draw(sf::RenderWindow& window); //do rysowania w oknie
	void Gora(); //funkcja do poruszania sie w gore menu
	void Dol(); //i w dol

	int menuChoosen = 0; //zmienna do wybierania opcji z menu

private:

	sf::Font ksztaltLiter; //do czcionki
	sf::Text pozycjeMenu[3]; //do tekstu

	sf::Texture tlo2; //tekstura
	sf::Sprite tlo22; //i sprite
};