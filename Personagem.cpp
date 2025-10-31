#include "Personagem.h"

CaveiraDeCristal::Entidades::Personagens::Personagem::Personagem(const sf::Vector2f posicao, const sf::Vector2f tamanho, const float velo) :
	corpo(sf::RectangleShape(tamanho))
{
	corpo.setPosition(posicao);
	vel = sf::Vector2f(velo, velo);
	podeAndar = false;
	paraEsquerda = false;
	relogioMovimento.restart();
	deltaTempo = 0.0f;
}

CaveiraDeCristal::Entidades::Personagens::Personagem::~Personagem()
{}

const sf::RectangleShape CaveiraDeCristal::Entidades::Personagens::Personagem::getCorpo() const
{
	return corpo;
}

void CaveiraDeCristal::Entidades::Personagens::Personagem::andar(const bool paraEsquerda)
{
	this->paraEsquerda = paraEsquerda;
	podeAndar = true;
}

void CaveiraDeCristal::Entidades::Personagens::Personagem::parar()
{
	podeAndar = false;
}

void CaveiraDeCristal::Entidades::Personagens::Personagem::Personagem::atualizarPosicao()
{
	//conceito de fisica basica: espaço = velocidade * tempo

	deltaTempo = relogioMovimento.getElapsedTime().asSeconds();
	float deltaEspaco = vel.x * deltaTempo;
	if (paraEsquerda)
	{
		deltaEspaco = -deltaEspaco;
	}
	corpo.move(deltaEspaco, 0.0f);
}
