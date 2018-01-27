#include <SFML/Graphics.hpp>
#include <Box2D/Box2D.h>

#include <iostream>

#include <coin.hh>

int main()
{
	sf::RenderWindow window(sf::VideoMode(480, 800), "HexFAF minimal", sf::Style::None);
	window.setVerticalSyncEnabled(true);

	//sf::CircleShape shape(100.f);
	//shape.setFillColor(sf::Color::Green);

	sf::Texture texture;
	if (!texture.loadFromFile("./res/tex2.png"))
	{
		return 2;
	}
	texture.setSmooth(true);

	sf::Sprite sprite;
	sprite.setTexture(texture);

	sf::Font font;
	if(!font.loadFromFile("./res/Roboto-Regular.ttf"))
	{
		return 1;
	}

	sf::Text text;

	// select the font
	text.setFont(font); // font is a sf::Font
	text.setString("ProjektKanal");
	text.setCharacterSize(48); // in pixels, not points!
	text.setFillColor(sf::Color::Green);
	//text.setStyle(sf::Text::Bold | sf::Text::Underlined);

	sf::RectangleShape load_back(sf::Vector2f(480 - 16 * 2, 30));
	load_back.setFillColor(sf::Color(0, 0, 0));
	load_back.setPosition(16, 800 - 16 - 30);

	sf::RectangleShape load_status(sf::Vector2f(484, 28));
	load_status.setFillColor(sf::Color(255, 145, 0));
	load_status.setPosition(17, 800 - 16 + 1 - 28);

	sf::Clock clock;
	sf::Time runtime;

	int coin_amount = 30;
	Coin coins[coin_amount];

	std::default_random_engine generator;
        std::uniform_int_distribution<int> distribution(10, 790);

	std::default_random_engine generator2;
        std::uniform_int_distribution<int> distribution2(8, 60);
	
	for(int i = 0; i < coin_amount; i++)
	{
         	double y = distribution(generator);
		double size = distribution2(generator2);
		coins[i] = Coin(0, y, size);
		coins[i].AddTo(&window);
	}

	bool running = true;
	while (window.isOpen() && running)
	{
		sf::Time elapsed = clock.restart();
		runtime = runtime + elapsed;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
		{
			running = false;
		}

		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();

		float splash_time = 3.0f;

		if(runtime < sf::seconds(splash_time))
		{
			load_status.setSize(sf::Vector2f((int)((480 - 16 * 2 + 1) / splash_time * runtime.asSeconds()), 26));
			
			window.draw(sprite);
			window.draw(text);

			window.draw(load_back);
			window.draw(load_status);	
			
		}
		else
		{
			text.setString("Click the coins!\nPress ESC to exit.");
			
			window.draw(sprite);
			window.draw(text);
			
			for(int i = 0; i < coin_amount; i++)
			{
				coins[i].Update(elapsed);
				coins[i].Draw();
				
				if(coins[i].GetX() > 480)
				{
					coins[i].SetPos(-10, distribution(generator));
				} 
			}
		}

		window.display();
	}

	return 0;
}


