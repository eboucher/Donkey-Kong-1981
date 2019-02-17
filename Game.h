#pragma once

#define LADDER_COUNT 4
#define BLOCK_COUNT_X 8
#define BLOCK_COUNT_Y 5
#define BLOCK_SPACE 110.f

using namespace std;

class Game
{
public:
	Game();
	~Game() { };
	void run();

private:
	shared_ptr<sf::Texture> texture;

	void processEvents();
	void update(sf::Time elapsedTime);
	void render();

	void updateStatistics(sf::Time elapsedTime);
	void handlePlayerInput(sf::Keyboard::Key key, bool isPressed);
	void handleGroundCollision();

private:
	static const float		PlayerSpeed;
	static const sf::Time	TimePerFrame;

	sf::RenderWindow		mWindow;
	sf::Texture	mTexture;
	sf::Sprite	mPlayer;
	sf::Font	mFont;
	sf::Text	mStatisticsText;
	sf::Time	mStatisticsUpdateTime;

	static const string texturesPath;

	size_t	mStatisticsNumFrames;
	bool mIsMovingUp;
	bool mIsMovingDown;
	bool mIsMovingRight;
	bool mIsMovingLeft;

	sf::Texture	_LadderTexture;
	sf::Sprite	_Ladder[LADDER_COUNT];
	sf::Texture	_TextureBlock;
	sf::Sprite	_Block[BLOCK_COUNT_X][BLOCK_COUNT_Y];
	sf::Texture	_TextureWeapon;
	sf::Sprite	_Weapon;
	sf::Vector2u _sizeBlock;
	sf::Vector2u _sizeMario;

  public:
	shared_ptr<sf::Texture> getTexture(const sf::Image &spriteSheet);
	shared_ptr<sf::Texture> GetSprite(const sf::Image &spriteSheet, const sf::IntRect &pos);
};