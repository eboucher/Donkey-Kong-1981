#include "pch.h"
#include "StringHelpers.h"
#include "Game.h"
#include "EntityManager.h"

using namespace std;

const float Game::PlayerSpeed = 100.f;
const sf::Time Game::TimePerFrame = sf::seconds(1.f / 60.f);
const string Game::texturesPath = "Media/Textures/DonkeyKong_SpriteSheet.png";

shared_ptr<sf::Texture> Game::getTexture(const sf::Image &spriteSheet)
{
	return texture;
}

shared_ptr<sf::Texture> Game::GetSprite(const sf::Image &spriteSheet, const sf::IntRect &pos)
{
	texture = make_shared<sf::Texture>();
	texture->loadFromImage(spriteSheet, pos);
	texture->setRepeated(true);
	return texture;
}

Game::Game()
	: mWindow(sf::VideoMode(840, 600), "Donkey Kong 1981", sf::Style::Close)
	, mTexture()
	, mPlayer()
	, mFont()
	, mStatisticsText()
	, mStatisticsUpdateTime()
	, mStatisticsNumFrames(0)
	, mIsMovingUp(false)
	, mIsMovingDown(false)
	, mIsMovingRight(false)
	, mIsMovingLeft(false)
{
	mWindow.setFramerateLimit(160);

	// Draw ground blocks

	_TextureBlock.loadFromFile("Media/Textures/Block.png");
	_sizeBlock = _TextureBlock.getSize();

	sf::Vector2f position;
	for (int i = 0; i < BLOCK_COUNT_X; i++)
	{
		for (int j = 0; j < BLOCK_COUNT_Y; j++)
		{
			position = sf::Vector2f(100.f + 70.f * (i + 1), 0.f + BLOCK_SPACE * (j + 1));
			EntityManager::AddGroundBlock(position);
		}
	}

	// Draw Ladders

	_LadderTexture.loadFromFile("Media/Textures/Ladder.png");

	for (int i = 0; i < LADDER_COUNT; i++)
	{
		_Ladder[i].setTexture(_LadderTexture);
		_Ladder[i].setPosition(100.f + 70.f * (i + 1), 0.f + BLOCK_SPACE * (i + 1) + _sizeBlock.y );

		shared_ptr<Entity> se = make_shared<Entity>();
		se->m_sprite = _Ladder[i];
		se->m_type = EntityType::ladder;
		se->m_size = _LadderTexture.getSize();
		se->m_position = _Ladder[i].getPosition();
		EntityManager::AddLadder(se->m_position);
	}

	// Draw Mario

	mTexture.loadFromFile("Media/Textures/Mario_small_transparent.png"); // Mario_small.png");
	_sizeMario = mTexture.getSize();
	mPlayer.setTexture(mTexture);
	sf::Vector2f posMario;
	posMario.x = 100.f + 70.f;
	posMario.y = BLOCK_SPACE * 5 - _sizeMario.y;

	EntityManager::SetMario(posMario);

	// Draw Statistic Font 

	mFont.loadFromFile("Media/Sansation.ttf");
	mStatisticsText.setString("Welcome to Donkey Kong 1981");
	mStatisticsText.setFont(mFont);
	mStatisticsText.setPosition(5.f, 5.f);
	mStatisticsText.setCharacterSize(10);
}

void Game::run()
{
	sf::Clock clock;
	sf::Time timeSinceLastUpdate = sf::Time::Zero;
	while (mWindow.isOpen())
	{
		sf::Time elapsedTime = clock.restart();
		timeSinceLastUpdate += elapsedTime;
		while (timeSinceLastUpdate > TimePerFrame)
		{
			timeSinceLastUpdate -= TimePerFrame;

			processEvents();
			EntityManager::UpdateEntities(TimePerFrame);
		}

		updateStatistics(elapsedTime);
		render();
	}
}

void Game::processEvents()
{
	sf::Event event;
	while (mWindow.pollEvent(event))
	{
		switch (event.type)
		{
		case sf::Event::KeyPressed:
			handlePlayerInput(event.key.code, true);
			break;

		case sf::Event::KeyReleased:
			handlePlayerInput(event.key.code, false);
			break;

		case sf::Event::Closed:
			mWindow.close();
			break;
		}
	}
}

//TODO: Render according the nature of the object (consider only animate objects?)
void Game::render()
{
	mWindow.clear();

	for (shared_ptr<Entity> entity : EntityManager::m_Entities)
	{
		if (entity->m_enabled == false)
		{
			continue;
		}

		mWindow.draw(entity->m_sprite);
	}

	mWindow.draw(mStatisticsText);
	mWindow.display();
}

void Game::updateStatistics(sf::Time elapsedTime)
{
	mStatisticsUpdateTime += elapsedTime;
	mStatisticsNumFrames += 1;

	if (mStatisticsUpdateTime >= sf::seconds(1.0f))
	{
		mStatisticsText.setString(
			"Frames / Second = " + toString(mStatisticsNumFrames) + "\n" +
			"Time / Update = " + toString(mStatisticsUpdateTime.asMicroseconds() / mStatisticsNumFrames) + "us");

		mStatisticsUpdateTime -= sf::seconds(1.0f);
		mStatisticsNumFrames = 0;
	}

	//
	// Handle collision
	//

	if (mStatisticsUpdateTime >= sf::seconds(0.050f))
	{
		// Handle collision weapon enemies
	}
}

void Game::handlePlayerInput(sf::Keyboard::Key key, bool isPressed)
{
	if (key == sf::Keyboard::Up)
		mIsMovingUp = isPressed;
	else if (key == sf::Keyboard::Down)
		mIsMovingDown = isPressed;
	else if (key == sf::Keyboard::Left)
		mIsMovingLeft = isPressed;
	else if (key == sf::Keyboard::Right)
		mIsMovingRight = isPressed;

	if (key == sf::Keyboard::Space)
	{
		if (isPressed == false)
		{
			return;
		}

	}
}


//TODO: This method definition should be defined somewhere else, other than inside the Game class
void Game::handleGroundCollision() {
	auto GroundBlocks = EntityManager::GetGroundBlocks();
	auto playerBounds = sf::Rect<float>(
		mario->m_position.x,
		mario->m_position.y,
		mario->m_size.x,
		mario->m_size.y
		);
	for (auto const& floor : GroundBlocks) {
		auto floorGloabalBounds = floor.get()->m_sprite.getGlobalBounds();
		if (floorGloabalBounds.intersects(playerBounds)) {
			mario->isFalling = false;
			return;
		}
	}
	mario->isFalling = true;
}