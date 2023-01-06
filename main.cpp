#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "pagaia.h"

int main()
{
	std::cout << "bdchwbcjh";
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Gioco");
	menu menuGlowne;
	pagaia paletka;

	sf::Texture tekstura;
	if (!tekstura.loadFromFile("Tlo.png")) {
		std::cout << "tekstura sie popsula\n";
	}
	
	sf::Sprite Tlo;
	Tlo.setTexture(tekstura);
	Tlo.setTextureRect(sf::IntRect(0, 0, 1200, 800));
	Tlo.setPosition(0,0);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();

			if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::Up:
					menuGlowne.Gora();
					break;
				case sf::Keyboard::Return:
					switch (menuGlowne.menuChoosen) {
					case 2:
						window.close();
						break;
					case 0:
						while (window.isOpen()) {
							window.clear();
							paletka.draw(window);
							window.display();
							while (window.pollEvent(event)) {
								if (event.type == sf::Event::Closed)
									window.close();
								if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
									window.close();
								}
							}
						}
						break;
					case 1:
						sf::RenderWindow pomoc(sf::VideoMode(1200, 800), "Aiuto");
						sf::Event ev;
						while (pomoc.isOpen()) {
							pomoc.clear();
							pomoc.draw(Tlo);
							pomoc.display();
							while (pomoc.pollEvent(ev)) {
								if (ev.type == sf::Event::Closed)
									pomoc.close();
								if (ev.type == sf::Event::KeyReleased && ev.key.code == sf::Keyboard::Escape) {
									pomoc.close();
								}
							}
						}
						break;
					}
				}
			}

			if (event.type == sf::Event::KeyReleased) {
				switch (event.key.code) {
				case sf::Keyboard::Down:
					menuGlowne.Dol();
					break;
				}
			}
		}
		window.clear();
		menuGlowne.draw(window);
		window.display();
	}
	return 0;
}