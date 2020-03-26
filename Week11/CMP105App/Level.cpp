#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in, GameState* gs, AudioManager* aud)
{
	window = hwnd;
	input = in;
	gameState = gs;
	audio = aud;

	// initialise game objects
	audio->addMusic("sfx/cantina.ogg", "cantina");
	audio->addSound("sfx/TP_Secret.ogg", "secret");
	audio->addSound("sfx/smb_jump-small.ogg", "jump");

	gravBallText.loadFromFile("gfx/Beach_Ball.png");
	gravBall.setTexture(&gravBallText);
	gravBall.setSize(sf::Vector2f(100, 100));
	gravBall.setPosition(100, 100);
	gravBall.setInput(input);
	gravBall.setWindu(window);

	game.setInput(input);
	Menu.setInput(input);

	gameState->setCurrentState(State::MENU);
}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	if (input->isKeyDown(sf::Keyboard::Enter) && gameState->getCurrentState() == State::LEVEL)
	{
		input->setKeyUp(sf::Keyboard::Enter);
		gameState->setCurrentState(State::MENU);
		gravBall.setStepVelocity(sf::Vector2f(0, 0));
		gravBall.setPosition(100, 100);
		audio->stopAllMusic();
	}

	if (input->isKeyDown(sf::Keyboard::Enter) && gameState->getCurrentState() == State::MENU)
	{
		input->setKeyUp(sf::Keyboard::Enter);
		gameState->setCurrentState(State::LEVEL);
		audio->playMusicbyName("cantina");
	}

	if (input->isKeyDown(sf::Keyboard::Escape) && gameState->getCurrentState() == State::LEVEL)
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::PAUSE);
		audio->stopAllMusic();
	}
	else if (input->isKeyDown(sf::Keyboard::Escape) && gameState->getCurrentState() == State::PAUSE)
	{
		input->setKeyUp(sf::Keyboard::Escape);
		gameState->setCurrentState(State::LEVEL);
		audio->playMusicbyName("cantina");
	}

	if (input->isKeyDown(sf::Keyboard::Numpad0))
	{
		input->setKeyUp(sf::Keyboard::Numpad0);
		audio->playSoundbyName("secret");
	}

	switch (gameState->getCurrentState())
	{
	case(State::MENU):
		Menu.handleInput(dt);
		break;

	case(State::LEVEL):
		game.handleInput(dt);
		gravBall.handleInput(dt, audio);
		break;
	}
}

// Update game objects
void Level::update(float dt)
{
	switch (gameState->getCurrentState())
	{
	case(State::MENU):
		Menu.update(dt);
		break;

	case(State::LEVEL):
		game.update(dt);
		gravBall.update(dt);
		break;
	}
}

// Render level
void Level::render()
{
	beginDraw();
	switch (gameState->getCurrentState())
	{
	case(State::MENU):
		Menu.render(window);
		break;

	case(State::LEVEL):
		game.render(window, gravBall);
		break;

	case(State::PAUSE) :
		game.render(window, gravBall);
		break;
	}
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}