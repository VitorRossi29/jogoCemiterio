#include "Obstaculo.h"

CaveiraDeCristal::Entidades::Obstaculos::Obstaculo::Obstaculo(const sf::Vector2f posicao, const sf::Vector2f tam, IDs::ID id = IDs::ID::vazio) :
	Entidade(posicao, tam)
{}

CaveiraDeCristal::Entidades::Obstaculos::Obstaculo::~Obstaculo()
{}