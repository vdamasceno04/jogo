#include"jogador.h"

class Explorador : public Jogador {
private:
public:
	Explorador(Math::CoordF pos = Math::CoordF(0, HEIGHT * 0.635));
	~Explorador();
	void resetar();
	void controlar();
	void executar();
};