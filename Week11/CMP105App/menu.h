#pragma once
#include "Framework/GameObject.h"
#include <iostream>
class menu :
	public GameObject
{

public:
	sf::Font font;
	sf::Text text;

	menu();
	void handleInput(float dt) override;
	void update(float dt) override;
	void render(sf::RenderWindow* window);
	~menu();
};

