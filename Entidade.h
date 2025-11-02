#pragma once

#include "Ente.h"
#include "IDs.h"
#include <SFML/Graphics.hpp>

namespace CaveiraDeCristal
{
	namespace Entidades
	{
		class Entidade : public Ente
		{
		protected:
			IDs::ID id;
		public:
			Entidade(const sf::Vector2f posicao = sf::Vector2f(10.0f, 10.0f), const sf::Vector2f tam = sf::Vector2f(50.0f, 50.0f), IDs::ID id = IDs::ID::vazio);
			virtual ~Entidade();

			IDs::ID getID() const { return id; }
			void setID(IDs::ID novoID) { id = novoID; }

			virtual void executar() = 0;
			virtual void colisao(Entidade* colidido, sf::Vector2f colisao) = 0;
		};
	}
}


