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
		sf::RenderWindow* janela;
		sf::Vector2f posicao;
		sf::Vector2f tamanho;
		bool remove;

	public:
		Entidade(sf::Vector2f pos, ID i);
		~Entidade();
		void setPosicao(sf::Vector2f pos);
		sf::Vector2f getPosicao() const;
		void setTamanho(sf::Vector2f tam);
		sf::Vector2f getTamanho() const;
		void setVelocidade(sf::Vector2f vel);
		sf::Vector2f getVelocidade();
		void setJanela(sf::RenderWindow* janela);
		sf::RectangleShape getBody();
		void setEscala(sf::Vector2f escala);
		void setSprite(const char* local);
		void renderizar();
		virtual void executar() = 0;
		bool getRemove();
	};
}