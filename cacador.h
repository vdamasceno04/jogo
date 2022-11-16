#include"jogador.h"

class Cacador : public Jogador {
private:
public:
	Cacador(sf::Vector2f pos = sf::Vector2f(0, HEIGHT*0.635), ID i = ID::cacador);
	~Cacador();
	void move();
	void executar();
};