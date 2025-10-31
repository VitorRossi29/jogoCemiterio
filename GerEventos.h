#pragma once

#include "GerGrafico.h"
#include "Jogador.h"

namespace CaveiraDeCristal
{
	namespace Gerenciadores
	{
		class GerEventos
		{
		private:
			GerGrafico* pGrafico;
			Entidades::Personagens::Jogador* pJogador;

			//Singleton
			static GerEventos* pEvento;
			GerEventos();
		public:
			~GerEventos();
			static GerEventos* getGerEventos();
			void setjogador(Entidades::Personagens::Jogador* pJog);
			void verificaTeclaPressionada(sf::Keyboard::Key tecla);
			void verificaTeclaSolta(sf::Keyboard::Key tecla);
			void executar();
		};
	}
}


