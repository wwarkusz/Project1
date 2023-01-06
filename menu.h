#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

class menu
{
public:
	menu();
	void draw(sf::RenderWindow& window);
	void Gora();
	void Dol();
	int menuChoosen = 0;

	int menuPressed() {
		return menuChoosen;
	}

private:
	
	sf::Font ksztaltLiter;
	sf::Text pozycjeMenu[3];
};