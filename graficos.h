#pragma once
#include "coords.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Gerenciadores {
	
	class Graficos {
	protected:
		Graficos(); //padr�o de projeto singleton
	private:
		sf::RenderWindow* window;
		sf::View view;
		sf::Font* font;
		sf::Clock clock;
		static float dt;
		static Gerenciadores::Graficos* instance; //padr�o de projeto singleton
	public:
		~Graficos();
		static Graficos* getInstance();
		static void apagarInstance();
		sf::Clock getClock();
		void render(sf::Sprite* sprite);
		void render(sf::Text* text);
		sf::RenderWindow* getWindow();
		void display();
		void clear();
		bool isWindowOpen() const;
		void closeWindow();
		Math::CoordU getWindowSize() const;
		void setWindowSize(Math::CoordU size);
		Math::CoordF getView();
		void centerView(Math::CoordF pos);
		sf::Font* getFont();
		void updateTime();
	};
}
