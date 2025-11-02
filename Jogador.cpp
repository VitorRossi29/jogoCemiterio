#include "Jogador.h"

CaveiraDeCristal::Entidades::Personagens::Jogador::Jogador(const sf::Vector2f posicao, const sf::Vector2f tamanho, const float vel) :
	Personagem(posicao, tamanho, vel, IDs::ID::jogador)
{	
	corpo.setFillColor(sf::Color::Green);
}

CaveiraDeCristal::Entidades::Personagens::Jogador::~Jogador()
{}

void CaveiraDeCristal::Entidades::Personagens::Jogador::executar()
{
	if (podeAndar)
	{
		atualizarPosicao();
	}
	relogioMovimento.restart();
}

void CaveiraDeCristal::Entidades::Personagens::Jogador::colisao(Entidade* colidido, sf::Vector2f colisao)
{

}