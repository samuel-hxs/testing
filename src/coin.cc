#include <coin.hh>

#include <SFML/Graphics.hpp>

#include <string>

Coin::Coin(double x, double y, double size)
{
	_x = x;
	_y = y;
	_s = size;

	if (!_texture.loadFromFile("./res/coin.png"))
        {
                return;
        }
        _texture.setSmooth(true);
	
	_shape = sf::CircleShape(size);
	_shape.setFillColor(sf::Color(100, 250, 50));

	_shape.setTexture(&_texture); 
	_shape.setTextureRect(sf::IntRect(0, 0, 44, 47));
	_shape.setPosition(sf::Vector2f(_x, _y));
}

Coin::~Coin()
{
	
}

void Coin::AddTo(sf::RenderWindow* window)
{
	_window = window;
}

void Coin::Draw()
{
	if(_window == 0)
	{ 
		return;
	}

	(*_window).draw(_shape);
}

void Coin::SetPos(double x, double y)
{
	_x = x;
	_y = y;
	_shape.setPosition(sf::Vector2f(_x, _y));
}
