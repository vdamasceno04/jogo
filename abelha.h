#include "inimigo.h"

class Abelha : public Inimigo {
private:
	int mel;
public:
	Abelha(sf::Vector2f pos, Jogador* p1, Jogador* p2, int mel);
	~Abelha();
	void inicializa(int mel);
	void executar();
	void colidir(Entidade* pEnt, ID id);
};