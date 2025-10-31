#include "Jogador.h"

CaveiraDeCristal::Entidades::Personagens::Jogador::Jogador(const sf::Vector2f posicao, const sf::Vector2f tamanho, const float vel) :
	Personagem(posicao, tamanho, vel)
{	
	corpo.setFillColor(sf::Color::Green);
}

CaveiraDeCristal::Entidades::Personagens::Jogador::~Jogador()
{}

void CaveiraDeCristal::Entidades::Personagens::Jogador::atualizar()
{
	if (podeAndar)
	{
		atualizarPosicao();
	}
	relogioMovimento.restart();
}