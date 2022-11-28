#pragma once
#include "coords.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Gerenciadores {
	
	class Graphics {
	protected:
		Graphics(); //padr�o de projeto singleton
	private:
		sf::RenderWindow* window;
		sf::View view;
		sf::Font* font;
		sf::Clock clock;
		static float dt;
		static Gerenciadores::Graphics* instance; //padr�o de projeto singleton
	public:
		~Graphics();
		static Graphics* getInstance();
		static void apagarInstance();
		sf::Clock getClock();
		void render(sf::Sprite* sprite);
		void render(sf::Text* text);
		sf::RenderWindow* getWindow();
		void display();
		void clear();
		bool isWindowOpen() const;
		void closeWindow();
		sf::Vector2u getWindowSize() const;
		void setWindowSize(sf::Vector2u size);
		sf::Vector2f getView();
		void centerView(sf::Vector2f pos);
		sf::Font* getFont();
		void updateTime();
	};
}
