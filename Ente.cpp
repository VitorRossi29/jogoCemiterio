#include "Ente.h"

CaveiraDeCristal::Ente::Ente(const sf::Vector2f posicao = sf::Vector2f(10.0f, 10.0f), const sf::Vector2f tam = sf::Vector2f(50.0f, 50.0f)) :
	corpo(sf::RectangleShape(tam))
{
	corpo.setPosition(posicao);
}

CaveiraDeCristal::Ente::~Ente()
{}

const sf::RectangleShape CaveiraDeCristal::Ente::getCorpo() const
{
	return corpo;
}

const sf::Vector2f CaveiraDeCristal::Ente::getPosicao() const
{
	return corpo.getPosition();
}

const sf::Vector2f CaveiraDeCristal::Ente::getTamanho() const
{
	return corpo.getSize();
}