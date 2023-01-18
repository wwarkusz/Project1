#include <iostream>
#include <SFML/Graphics.hpp>
#include "menu.h"
#include "pagaia.h"
#include "opzioni.h"
#include "koniec.h"
#include "wygrana.h"
#include "pauza.h"


int main()
{
	a:
	sf::RenderWindow window(sf::VideoMode(1200, 800), "Gioco");
	window.setFramerateLimit(680);

	menu menuGlowne;
	pagaia paletka;
	opzioni Opcje;
	koniec end;
	wygrana win;
	pauza PAUZA;

	sf::Texture tekstura;
	if (!tekstura.loadFromFile("Tlo.png")) {
		std::cout << "tekstura sie popsula\n";
	}

	sf::Sprite Tlo;
	Tlo.setTexture(tekstura);
	Tlo.setTextureRect(sf::IntRect(0, 0, 1200, 800));
	Tlo.setPosition(0, 0);

//a:
	while (window.isOpen())
	{
		window.clear();
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed) {
				window.close();
			}

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
						window.clear();
						while (window.isOpen()) {
							sf::Event event;
							window.clear();
							Opcje.draw(window);
							window.display();
							while (window.pollEvent(event)) {
								if (event.type == sf::Event::Closed) {
									window.close();
								}
								if (event.type == sf::Event::KeyReleased) {
									switch (event.key.code) {
									case sf::Keyboard::Up:
										Opcje.Gora();
										break;
									case sf::Keyboard::Down:
										Opcje.Dol();
										break;
									case sf::Keyboard::Escape:
										goto a;
										break;
									case sf::Keyboard::Return:
										switch (Opcje.opcjaChoosen) {
										case 0:
											paletka.dx = 0.4f;
											paletka.dy = 0.5;
											break;
										case 1:
											paletka.dx = 0.5f;
											paletka.dy = 0.7f;
											break;
										}
										while (window.isOpen()) {///////////////////////////gra
											
											if (paletka.p == 3) {
												while (window.isOpen()) {
													window.clear();
													win.draw(window);
													window.display();
													while (window.pollEvent(event)) {
														if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
															goto a;
														}
														if (event.type == sf::Event::Closed) {
															window.close();
														}
													}
												}
											}
											if (paletka.Ruch() == 9) {
												while (window.isOpen()) {
													window.clear();
													end.draw(window);
													window.display();
													while (window.pollEvent(event)) {
														if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
															goto a;
														}
														if (event.type == sf::Event::Closed) {
															window.close();
														}
													}
												}
											}
											paletka.zabijanieKwadratow(paletka.odbijanie());
											window.clear();
											paletka.draw(window);
											paletka.pisanie();
											window.display();
											b:
											while (window.pollEvent(event)) {
												if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
													PAUZA.draw(window);
													window.display();
													while (window.isOpen()) {
														while (window.pollEvent(event)) {
															switch (event.key.code) {
																case sf::Keyboard::Space:
																	goto a;
																	break;
																case sf::Keyboard::Return:
																	goto b;
																	break;
															}
														}
													}
												}
												if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
													sf::RenderWindow pomoc(sf::VideoMode(1200, 800), "Aiuto");
													while (pomoc.isOpen()) {
														pomoc.clear();
														pomoc.draw(Tlo);
														pomoc.display();
														while (pomoc.pollEvent(event)) {
															if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Space) {
																pomoc.close();
															}
														}
													}
												}
												if (event.type == sf::Event::Closed) {
													window.close();
												}
											}
											if (event.type == sf::Event::KeyPressed) {
												switch (event.key.code) {
												case sf::Keyboard::Right:
													paletka.Prawo();
													break;
												case sf::Keyboard::Left:
													paletka.Lewo();
													break;
												case sf::Keyboard::Escape:
													window.close();
													break;
												}
											}
										}
										break;

									}
								}
							}
						}
						break;


					case 1:
						sf::RenderWindow pomoc(sf::VideoMode(1200, 800), "Aiuto");
						while (pomoc.isOpen()) {
							pomoc.clear();
							pomoc.draw(Tlo);
							pomoc.display();
							while (pomoc.pollEvent(event)) {
								if (event.type == sf::Event::Closed)
									pomoc.close();
								if (event.type == sf::Event::KeyReleased && event.key.code == sf::Keyboard::Escape) {
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

			window.clear();
			menuGlowne.draw(window);
			window.display();


		}
		window.clear();
		menuGlowne.draw(window);
		window.display();
	}

	return 0;

}