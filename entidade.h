#pragma once
#include"ente.h"
#define HEIGHT 720
#define WIDTH 1080
namespace Entidades{

	class Entidade: public Ente{
	protected:
		sf::Texture textura;
		sf::Sprite sprite;
		sf::RectangleShape body;
		sf::RenderWindow* window;
		sf::Vector2f position;
		sf::Vector2f size;
		bool remove;

	public:
		Entidade(sf::Vector2f pos, ID i);
		~Entidade();
		void setPosition(sf::Vector2f pos);
		sf::Vector2f getPosition() const;
		void setSize(sf::Vector2f siz);
		sf::Vector2f getSize() const;
		void setVelocidade(sf::Vector2f vel);
		sf::Vector2f getVelocidade();
		void setWindow(sf::RenderWindow* window);
		sf::RectangleShape getBody();
		void setSprite(const char* local);
		void renderizar();
		virtual void executar() = 0;
		bool getRemove();
	};
}