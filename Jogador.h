#pragma once
#include <SFML/Graphics.hpp>
#include "Personagem.h"

namespace CaveiraDeCristal
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Jogador : public Personagem
			{
			private:
				
			public:
				Jogador(const sf::Vector2f posicao, const sf::Vector2f tamanho, const float vel);
				~Jogador();

				void executar ();
				void colisao(Entidade* colidido, sf::Vector2f colisao);
			};
		}
	}
}



