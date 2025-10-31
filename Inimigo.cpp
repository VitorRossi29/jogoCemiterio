#include "Inimigo.h"

CaveiraDeCristal::Entidades::Personagens::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, CaveiraDeCristal::Entidades::Personagens::Jogador* jog, const float velo) :
	Personagem(pos, tam, velo)
{
	jogador = jog;
	corpo.setFillColor(sf::Color::Red);
	moveAleatorio = rand() % 2;
	relogioAleatorio.restart();

}

CaveiraDeCristal::Entidades::Personagens::Inimigo::~Inimigo()
{ }

void CaveiraDeCristal::Entidades::Personagens::Inimigo::atualizar()
{
	sf::Vector2f posJogador = jogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.x <= RAIO_PERSEGUIR_Y))
	{
		persegueJogador(posJogador, posInimigo);
	}
	else
	{
		movimentoAleatorio();
	}
	if (podeAndar)
	{
		atualizarPosicao();
	}
	relogioMovimento.restart();
}

void CaveiraDeCristal::Entidades::Personagens::Inimigo::persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo)
{
	if (posJogador.x > posInimigo.x)
	{
		andar(false);
	}
	else if (posJogador.x < posInimigo.x)
	{
		andar(true);
	}
	else
	{
		parar();
	}
}

void CaveiraDeCristal::Entidades::Personagens::Inimigo::movimentoAleatorio()
{
	switch (moveAleatorio)
	{
	case 0 :
		andar(false);
		break;
	case 1 :
		andar(true);
		break;
	default :
		break;
	}

	float variacaoTempo = relogioAleatorio.getElapsedTime().asSeconds();
	if (variacaoTempo >= 1.0f)
	{
		parar();
		relogioAleatorio.restart();
		moveAleatorio = rand() % 2;
	}
}
