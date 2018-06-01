#include <iostream>
#include <SFML\Graphics.hpp>
#include "Illustrator.h"

int main() {
	sf::RenderWindow window(sf::VideoMode(1000, 600), "Map maker", sf::Style::Close);
	Illustrator illustrator(15, 15, 60, sf::Vector2u(600, 600), "image\\map.png");

	while (window.isOpen()) {
		sf::Event evnt;
		window.waitEvent(evnt);

		window.clear(sf::Color::Cyan);
		if (evnt.type == sf::Event::KeyPressed) {
			illustrator.interactionMove();

			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
				window.close();
			}
		}
		illustrator.draw(window);
		window.display();

	}

	return 0;
}