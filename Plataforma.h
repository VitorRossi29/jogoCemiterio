#pragma once
#include "Obstaculo.h"

namespace CaveiraDeCristal
{
	namespace Entidades
	{
		namespace Obstaculos
		{
			class Plataforma : public Obstaculo
			{
			protected:
				Plataforma(const sf::Vector2f posicao = sf::Vector2f(10.0f, 10.0f), const sf::Vector2f tam = sf::Vector2f(50.0f, 50.0f));
				~Plataforma();
			public:
				void colisao(Entidade* colidido, sf::Vector2f colisao);
			};
		}
	}
}


