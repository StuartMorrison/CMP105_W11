#include "menu.h"

menu::menu()
{

}

void menu::handleInput(float dt)
{

}

void menu::update(float dt)
{

}

void menu::render(sf::RenderWindow* window)
{
	if (!font.loadFromFile("font/arial.ttf"))
	{
		std::cout << "Error loading font\n";
	}
	text.setFont(font);
	text.setString("Title Screen, press Enter to continue.");
	text.setCharacterSize(30);
	text.setFillColor(sf::Color::Green);
	text.setPosition(100, 100);

	window->draw(text);
}

menu::~menu()
{

}
