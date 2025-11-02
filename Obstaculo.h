#pragma once
#include "Entidade.h"

namespace CaveiraDeCristal
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Obstaculo : public Entidade
			{
			protected:
				Obstaculo(const sf::Vector2f posicao = sf::Vector2f(10.0f, 10.0f), const sf::Vector2f tam = sf::Vector2f(50.0f, 50.0f), IDs::ID id = IDs::ID::vazio);
				~Obstaculo();
			public:
				virtual void colisao(Entidade* colidido) = 0;
			};
		}
	}
}



