#include"fase.h"

class FlorestaVermelha : public Fase {

public:
	FlorestaVermelha(Managers::Graphics* pG);
	~FlorestaVermelha();
	void criachao();
	void criaespinho();
	void criajavali();
	void criacaracol();
	void inicializar();
	void executar();
	void colidir();
};