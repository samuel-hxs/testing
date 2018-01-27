#ifndef COIN_H
#define COIN_H

#include <SFML/Graphics.hpp>

class Coin
{
public:
	Coin(double x, double y, double size);
	Coin();
	~Coin();
	void AddTo(sf::RenderWindow* window);
	void Draw();
	void Update(sf::Time elapsed);
	void SetPos(double x, double y);
	double GetX();
private:
	double _x;
	double _y;
	double _s;
	double _angle;
	double _speed;
	sf::CircleShape _shape;
	sf::Texture _texture;
	sf::RenderWindow* _window;
	double GetDegree(double radian);
	double GetRadian(double degree);
};

#endif
