#ifndef COIN_H
#define COIN_H

#include <SFML/Graphics.hpp>

class Coin
{
public:
	Coin(double x, double y, double size);
	~Coin();
	void AddTo(sf::RenderWindow* window);
	void Draw();
	void SetPos(double x, double y);
private:
	double _x;
	double _y;
	double _s;
	sf::CircleShape _shape;
	sf::Texture _texture;
	sf::RenderWindow* _window;
};

#endif
