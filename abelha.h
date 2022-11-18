#include "inimigo.h"

class Abelha : public Inimigo {
private:

public:
	Abelha(sf::Vector2f pos, Jogador* p1, Jogador* p2, int vida, int dano);
	~Abelha();
	void executar();
	void colidir(Entidade* pEnt, ID id);
};