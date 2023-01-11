#pragma once
#include"ente.h"
#define HEIGHT 720
#define WIDTH 1080
#define GRAVIDADE 2.9

namespace Entidades {

	class Entidade : public Ente {
	protected:
		sf::Texture textura;
		sf::Sprite sprite;
		sf::RectangleShape body;
		sf::RenderWindow* janela;
		Math::CoordF posicao;
		Math::CoordF tamanho;
		Math::CoordF velocidade;
		Math::CoordF vmax;
		bool remove;
		int vida;
		int dano;
		bool colidindo;
	public:
		Entidade(Math::CoordF pos);
		~Entidade();

		void setPosicao(Math::CoordF pos);
		Math::CoordF getPosicao() const;

		void setVelocidade(Math::CoordF vel);
		Math::CoordF getVelocidade() const;

		void setTamanho(Math::CoordF tam);
		Math::CoordF getTamanho() const;
		void setEscala(Math::CoordF escala);

		void setJanela(sf::RenderWindow* janela);

		sf::RectangleShape getBody();
		void setSprite(const char* local);

		void renderizar();
		void atualizar();

		void tomaDano(int ferimento);
		int getDano() const;

		bool getRemove();
		void setRemove(bool rem);

		void setColidindo(bool chao);
		bool getColidindo();
		
		virtual void efeito(Entidade* p) {};
		virtual void executar() = 0;

	};
}