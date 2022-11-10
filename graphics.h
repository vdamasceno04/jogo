#pragma once
#include "coords.h"
#include <SFML/Graphics.hpp>
#include <map>

namespace Managers {
	
	class Graphics {
	protected:
		Graphics(); //padr�o de projeto singleton
	private:
		sf::RenderWindow* window;
		sf::View view;
		std::map<const char*, sf::Texture*> mapaTextura;
		sf::Font* font;
		sf::Clock clock;
		static float dt;
		static Managers::Graphics* instance; //padr�o de projeto singleton
	public:
		~Graphics();
		static Graphics* getInstance();
		void render(sf::RectangleShape* body);
		void render(sf::Text* text);
		sf::RenderWindow* getWindow();
		void display();
		void clear();
		bool isWindowOpen() const;
		void closeWindow();
		sf::Vector2u getWindowSize() const;
		void setWindowSize(sf::Vector2u size);
		void centerView(sf::Vector2f pos);
		sf::Texture* loadTexture(const char* path);
		sf::Font* getFont();
		void updateTime();
	};
}