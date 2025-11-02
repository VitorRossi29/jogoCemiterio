#pragma once

#include "IDs.h"
#include <SFML/Graphics.hpp>

namespace CaveiraDeCristal
{
	class Ente
	{
	protected:
		sf::RectangleShape corpo;
		IDs::ID id;
	public:
		Ente(const sf::Vector2f posicao = sf::Vector2f(10.0f, 10.0f), const sf::Vector2f tam = sf::Vector2f(50.0f, 50.0f));
		
		virtual ~Ente();
		
		const sf::RectangleShape getCorpo() const;
		const sf::Vector2f getPosicao() const;
		const sf::Vector2f getTamanho() const;

		virtual void executar() = 0;
	};
}

