#pragma once

#include <SFML/Graphics.hpp>

class Entidade
{
protected:
	int x;
	int y;
	sf::RectangleShape body;
	// ostream "buffer" tirar aspas depois;
public:
	Entidade();
	~Entidade();
	virtual void executar() = 0;
	virtual void salvar () = 0;
protected:
	void salvarDataBuffer(); // Impementar depois
};

