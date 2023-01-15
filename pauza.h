#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>


class pagaia
{
public:
	pagaia();
	void draw(sf::RenderWindow& window);
	void Prawo();
	void Lewo();
	float dx, dy;
	void Ruch();
	void odbijanie();

private:

	sf::Texture teksturaPaletki;
	sf::Sprite paletka;

	sf::Texture teksturaPilki;
	sf::Sprite pilka;

	sf::Texture teksturaKwadratow;
	sf::Sprite kwadrat[24];
};