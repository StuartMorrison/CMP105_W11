#pragma once
#include "Framework/GameObject.h"
class Game :
	public GameObject
{
public:

	Game();
	void handleInput(float dt);
	void update(float dt);
	void render(sf::RenderWindow* window, GameObject gravBall);
	~Game();
};

