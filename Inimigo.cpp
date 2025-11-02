#include "Inimigo.h"

CaveiraDeCristal::Entidades::Personagens::Inimigo::Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, CaveiraDeCristal::Entidades::Personagens::Jogador* jog, const float velo) :
	Personagem(pos, tam, velo, IDs::ID::plataforma)
{
	jogador = jog;
	corpo.setFillColor(sf::Color::Red);
	moveAleatorio = rand() % 2;
	relogioAleatorio.restart();
}

CaveiraDeCristal::Entidades::Personagens::Inimigo::~Inimigo()
{}

void CaveiraDeCristal::Entidades::Personagens::Inimigo::executar()
{
	mover();
}

void CaveiraDeCristal::Entidades::Personagens::Inimigo::mover()
{
	sf::Vector2f posJogador = jogador->getCorpo().getPosition();
	sf::Vector2f posInimigo = corpo.getPosition();

	if (fabs(posJogador.x - posInimigo.x) <= RAIO_PERSEGUIR_X && fabs(posJogador.y - posInimigo.y <= RAIO_PERSEGUIR_Y))
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
	bool esquerda = true;
	if (posJogador.x > posInimigo.x)
	{
		andar(!esquerda);
	}
	else if (posJogador.x < posInimigo.x)
	{
		andar(esquerda);
	}
	else
	{
		parar();
	}
}

void CaveiraDeCristal::Entidades::Personagens::Inimigo::movimentoAleatorio()
{
	bool esquerda = true;
	switch (moveAleatorio)
	{
	case 0 :
		andar(!esquerda);
		break;
	case 1 :
		andar(esquerda);
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
