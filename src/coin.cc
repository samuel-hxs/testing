#include <coin.hh>

#include <SFML/Graphics.hpp>

#include <string>
#include <iostream>

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

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(0, 400);
	_angle = distribution(generator);
	_angle = 0;
	_speed = size / 2;
}

Coin::Coin()
{

}

Coin::~Coin()
{
	
}

void Coin::AddTo(sf::RenderWindow* window)
{
	if(_window == 0)
	{
		return;
	}

	_window = window;
}

double Coin::GetDegree(double radian)
{
	return radian * 57.295779513082;
}

double Coin::GetRadian(double degree)
{
	return degree * 0.017453292519;
}

void Coin::Update(sf::Time elapsed)
{
	double start_x = 0;
	double start_y = 0;

	double len = _speed * (elapsed.asSeconds());

	_x = _x + len * cos(_angle);
        _y = _y + len * sin(_angle);

	//std::cout << "Coin -> x:" << _x << " y: " << _y << std::endl;
	//Point(distance * Math.Cos(angle), distance * Math.Sin(angle))
	_shape.setPosition(sf::Vector2f(_x, _y));
}

void Coin::Draw()
{
	if(_window == 0)
	{ 
		return;
	}

	(*_window).draw(_shape);
}

double Coin::GetX()
{
	return _x;
}

void Coin::SetPos(double x, double y)
{
	_x = x;
	_y = y;
	_shape.setPosition(sf::Vector2f(_x, _y));
}
