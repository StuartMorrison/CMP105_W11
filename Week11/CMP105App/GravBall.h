#pragma once
#include "Framework/GameObject.h"
#include "Framework/AudioManager.h"
class GravBall :
	public GameObject
{
public:

	float scale;
	int isJumping;
	sf::Vector2f gravity;
	sf::Vector2f stepVelocity;
	sf::Vector2f jumpVector;
	sf::RenderWindow* window;

	GravBall();
	void setStepVelocity(sf::Vector2f newStepVelocity) { stepVelocity = newStepVelocity; };
	void handleInput(float dt, AudioManager* audio);
	void update(float dr) override;
	void setWindu(sf::RenderWindow* hwnd) { window = hwnd; };
	~GravBall();
};

