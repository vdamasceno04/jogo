#include"jogador.h"

class Cacador : public Jogador {
private:

public:
	Cacador(Math::CoordF pos = Math::CoordF(500, HEIGHT * 0.635));
	~Cacador();
	void resetar();
	void controlar();
	void executar();
};