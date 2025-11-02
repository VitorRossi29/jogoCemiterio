#include "Entidade.h"

CaveiraDeCristal::Entidades::Entidade::Entidade(const sf::Vector2f posicao, const sf::Vector2f tam, IDs::ID id = IDs::ID::vazio) :
	Ente(posicao, tam),
	id(id)
{}

CaveiraDeCristal::Entidades::Entidade::~Entidade()
{}