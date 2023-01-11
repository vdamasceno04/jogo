#include "inimigo.h"

class Abelha : public Inimigo {
private:
	int mel;
public:
	Abelha(Math::CoordF pos, Jogador* p1, Jogador* p2, int mel);
	~Abelha();
	void inicializa(int mel);
	void ataca(Jogador* pJ);
	void voar();
	void executar();
};