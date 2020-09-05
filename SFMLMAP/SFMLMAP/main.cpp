#include <iostream>
#include <SFML/Graphics.hpp>
#include <ctime>
using namespace std;

int main()
{
	//sf::Clock clock;
	//float timer=clock.getElapsedTime().asMicroseconds();
	//clock.restart();
	//timer = timer/10;
	sf::RenderWindow window(sf::VideoMode(1920, 1080), "my Window"/*, sf::Style::Fullscreen*/);
	//float currectFrame=0;
	//sf::Texture texture;
	//texture.loadFromFile("campfire_fire.png");
	//sf::Sprite sprite(texture);
	
	sf::Image mImage;
	mImage.loadFromFile("map.png");
	sf::Texture mTexture;
	mTexture.loadFromImage(mImage);
	sf::View minimap;

	sf::Sprite mSprite(mTexture);
	minimap.setCenter(sf::Vector2f(1750.f, 100.f));
	mSprite.setTextureRect(sf::IntRect(1750, 100 , 250, 250));
	sf::View view;
	view.setSize(1024.f, 1024.f);
	view.setViewport(sf::FloatRect(0.f, 0.f, 1.f, 1.f));
	
	//view.setCenter(sf::Vector2f(1750.f, 100.f));


	minimap.setViewport(sf::FloatRect(0.75f, 0.0f, 1.f, 1.f));
		while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{

			if (event.type == sf::Event::Closed)
			{
				window.close();
			}

		}
		/*window.clear();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z));
		{
			std::cout << "Currerct frame" << currectFrame<<endl;
			currectFrame += timer;
			if (currectFrame > 8)
				currectFrame -= 8;
				sprite.setTextureRect(sf::IntRect(0, int(currectFrame) * 64, 64, 64));
		
		}
		sf::Vector2i pos = sf::Mouse::getPosition(window);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Z))
		{
			if (view.getSize().x < 1024.f && view.getSize().y<1024.f)
			{
				view.zoom(1.005f);
				window.setView(view);
			}
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::X))
		{
			view.zoom(0.995f);
			window.setView(view);
		}
		if (pos.x < 30)
			view.move(-1, 0);
		if (pos.x > window.getSize().x - 30)
			view.move(1, 0);
		if (pos.y < 30)
			view.move(0, -1);
		if (pos.y > window.getSize().y - 30)
			view.move(0, 1);
		window.clear();
		view.setCenter(window.getPosition().x/2,window.getPosition().y/2);

		window.setView(view);*/
		 window.setView(minimap);
		 window.draw(mSprite);

		window.display();
	}


}