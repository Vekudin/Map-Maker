#include "Illustrator.h"


Illustrator::Illustrator(int mapWidth, int mapHeight, int tileSize, sf::Vector2u tileSetSize,
	const std::string& tilesetPath)
	:mapWidth(mapWidth), mapHeight(mapHeight), tileSize(tileSize), tileSetSize(tileSetSize)
{
	tile.setSize(sf::Vector2f(tileSize, tileSize));
	tile.setOutlineColor(sf::Color::Black);
	tileNumber = 0;

	tileSetText.loadFromFile(tilesetPath);
	tile.setTexture(&tileSetText);

	controlPos.x = 0.5f; controlPos.y = 0.5f;
	control.setSize(sf::Vector2f(tileSize/2, tileSize/2));
	control.setFillColor(sf::Color::Red);
	control.setOrigin(tileSize/4, tileSize/4);
	control.setPosition(tileSize / 2, tileSize / 2);

	map = mapGenerator();
}

int * Illustrator::mapGenerator()
{
	static int map[10000];
	for (int i = 0; i < mapWidth * mapHeight; i++) {
		map[i] = 0;
	}
	tileCount++;
	return map;
}

void Illustrator::draw(sf::RenderWindow & window)
{
	for (int y = 0; y < mapHeight; y++) {

		for (int x = 0; x < mapWidth; x++) {

			int tu = map[x + y* mapHeight] % (tileSetSize.x / tileSize);
			int tv = map[x + y * mapHeight] / (tileSetSize.y / tileSize);

			tile.setPosition((float)x * tileSize, (float)y * tileSize);
			tile.setTextureRect(sf::IntRect(tu * tileSize, tv * tileSize, tileSize, tileSize));
			window.draw(tile);
		}	
	}

	control.setPosition(controlPos.x * (float)tileSize, controlPos.y * (float)tileSize);
	window.draw(control);
}

void Illustrator::interactionMove()
{
	bool flag = false;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
		tileCount = (controlPos.x - 0.5f) + (controlPos.y - 0.5f) * mapHeight;
		map[tileCount] = tileNumber;
		printf("map[%d]: %d\n", tileCount, map[tileCount]);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Add)) {
		tileNumber++;
		printf("tileNumber:%d\n", tileNumber);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Subtract)) {
		tileNumber--;
		printf("tileNumber:%d\n", tileNumber);
	}

	//directions
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
			if (controlPos.x + 1.0f <= mapWidth) {
				controlPos.x += 1.0f;
			}
			else {
				controlPos.x = 0.5f;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
			if (controlPos.x - 1.0f > 0.0f) {
				controlPos.x -= 1.0f;
			}
			else {
				controlPos.x = mapWidth - 0.5f;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
			if (controlPos.y - 1.0f > 0.0f) {
				controlPos.y -= 1.0f;
			}
			else {
				controlPos.y = mapHeight - 0.5f;
			}
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
			if (controlPos.y + 1.0f <= mapHeight) {
				controlPos.y += 1.0f;
			}
			else {
				controlPos.y = 0.5f;
			}
		}
	}
}
