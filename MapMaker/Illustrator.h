#pragma once
#include <SFML\Graphics.hpp>

class Illustrator
{
public:
	Illustrator(int mapWidth, int mapHeight, int tileSize, sf::Vector2u tileSetSize, const std::string& tileset);
	int * mapGenerator();
	void draw(sf::RenderWindow &window);
	void interactionMove();

	int * map;
	int mapWidth; int mapHeight;
	int tileSize; int tileCount;
	sf::Vector2u tileSetSize;

	int tileNumber;
	sf::RectangleShape tile;
	sf::Texture tileSetText;

	sf::RectangleShape control;
	sf::Vector2f controlPos;
};

