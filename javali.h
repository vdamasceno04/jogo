#include "inimigo.h"

class Javali : public Inimigo {
private:
public:
	Javali(sf::Vector2f pos, Jogador* p1, Jogador* p2, int vida, int dano, int visao);
	~Javali();
	void executar();
	void colidir(Entidade* pEnt, ID id);
};