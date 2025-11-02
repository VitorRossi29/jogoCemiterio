#include "Plataforma.h"

CaveiraDeCristal::Entidades::Obstaculos::Plataforma::Plataforma(const sf::Vector2f posicao = sf::Vector2f(10.0f, 10.0f), const sf::Vector2f tam = sf::Vector2f(50.0f, 50.0f)) :
		Obstaculo(posicao, tam, IDs::ID::plataforma)
{}

CaveiraDeCristal::Entidades::Obstaculos::Plataforma::~Plataforma()
{}

void CaveiraDeCristal::Entidades::Obstaculos::Plataforma::colisao(Entidade* colidido, sf::Vector2f colisao)
{

}