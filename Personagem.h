#pragma once

#include <SFML/Graphics.hpp>
#include "Entidade.h"

namespace CaveiraDeCristal
{
	namespace Entidades
	{
		namespace Personagens
		{
			class Personagem : public Entidade 
			{
			protected:
				sf::Vector2f vel;
				bool podeAndar;
				bool paraEsquerda;
				sf::Clock relogioMovimento;
				float deltaTempo;
			public:
				Personagem(const sf::Vector2f posicao, const sf::Vector2f tamanho, const float velo, IDs::ID id = IDs::ID::vazio);
				~Personagem();

				//const sf::RectangleShape getCorpo() const;
				virtual void executar () = 0;

				void andar(const bool paraEsquerda);
				void parar();
				void atualizarPosicao();
			};
		}
	}
}


