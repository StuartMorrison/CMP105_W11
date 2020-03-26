#include "GravBall.h"

GravBall::GravBall()
{
	scale = 100.f;
	gravity = sf::Vector2f(0, 9.8f) * scale;
	jumpVector = sf::Vector2f(0, -4.0f) * scale;
	isJumping = 0;
}

void GravBall::handleInput(float dt, AudioManager* audio)
{
	if (input->isKeyDown(sf::Keyboard::Space))
	{
		input->setKeyUp(sf::Keyboard::Space);
		if (isJumping < 3)
		{
			stepVelocity = jumpVector;
			isJumping++;
			audio->playSoundbyName("jump");
		}
	}
}

void GravBall::update(float dt)
{
	sf::Vector2f pos = stepVelocity * dt + 0.5f * gravity * dt * dt;
	stepVelocity += gravity * dt;
	setPosition(getPosition() + pos);

	if (getPosition().y + getSize().y >= window->getSize().y)
	{
		isJumping = 0;
		setPosition(getPosition().x, window->getSize().y - getSize().y);
		stepVelocity = (-stepVelocity) / 1.2f;
	}
}

GravBall::~GravBall()
{

}