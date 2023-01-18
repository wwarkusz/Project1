#include <fstream>
#include "koniec.h"

koniec::koniec() { //definicja konstruktora
	if (!ksztaltLiter.loadFromFile("czcionka.otf")) { //czcionka
		std::cout << "literki sie popsuly\n";
	}

	end.setFont(ksztaltLiter); //ustawianie czcionki
	end.setFillColor(sf::Color::Magenta); //kolor
	end.setCharacterSize(80); //rozmiar
	end.setString("Mamma mia"); //napis
	end.setPosition(350, 200); //pozycja

	END.setFont(ksztaltLiter);
	END.setFillColor(sf::Color::White);
	END.setCharacterSize(30);
	END.setString("Space - Menu");
	END.setPosition(490, 300);

	PRZEGRANE.setFont(ksztaltLiter);
	PRZEGRANE.setFillColor(sf::Color::Magenta);
	PRZEGRANE.setCharacterSize(45);
	PRZEGRANE.setPosition(950, 730);
	std::fstream plik("przegrane.txt"); //czytanie pliku
	plik >> przegrane;
	plik.close();
	PRZEGRANE.setString("Perso: " + std::to_string(przegrane));

	tlo1.loadFromFile("tlo3.jpg"); //ladowanie obrazka 
	tlo11.setTexture(tlo1); //ustawianie tekstury
	tlo11.setTextureRect(sf::IntRect(0, 0, 1200, 800)); //wielkossc
	tlo11.setPosition(0, 0); //pozycja
}

void koniec::draw(sf::RenderWindow& window) { //funkcja do rysowania
	window.draw(tlo11);
	window.draw(end);
	window.draw(END);
	window.draw(PRZEGRANE);
}