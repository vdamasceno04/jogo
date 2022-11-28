#include"jogador.h"


namespace Entidades {
	namespace Personagens {
		class Explorador : public Jogador {
		private:
		public:
			Explorador(sf::Vector2f pos = sf::Vector2f(0, HEIGHT * 0.635));
			~Explorador();
			void resetar();
			void controlar();
			void executar();
		};
	}
}