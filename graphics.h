#pragma once
#include "coords.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Managers {
	
	class Graphics {
	private:
		sf::RenderWindow* window;
		sf::View view;
		std::map<const char*, sf::Texture*> texturesMap;
		sf::Font* font;
		sf::Clock clock;
		static float dt;
		static Managers::Graphics* instance;
		Graphics();
	public:
		~Graphics();
		static Graphics* getInstance();
		void render(sf::RectangleShape* body);
		void render(sf::Text* text);
		void display();
		void clear();
		bool isWindowOpen() const;
		void closeWindow();
		void handleWindowResize();
		void setWindowSize(Math::CoordU size);
		Math::CoordU getWindowSize(Math::CoordU size);
		sf::Vector2u getWindowSize() const;
		void centerView(Math::CoordF pos);
		sf::Texture* loadTexture(const char* path);
		sf::Font* getFont();
		void updateTime();


	};
}