#pragma once

namespace CaveiraDeCristal
{
	namespace Entidades
	{
		class Entidade
		{
		protected:
			sf::RectangleShape corpo;
		public:
			Entidade(const sf::Vector2f posicao, const sf::Vector2f tam);
			~Entidade();
			const sf::RectangleShape getCorpo() const;
			virtual void atualizar() = 0;
			virtual void colisao() = 0;
		};
	}
}


