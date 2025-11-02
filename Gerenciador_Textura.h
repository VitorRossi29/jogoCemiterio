#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
class Gerenciador_Textura
{
private:
	std::vector<sf::Texture> textures;
    int contador;
public:
    Gerenciador_Textura(); // Precisamos de um construtor
    ~Gerenciador_Textura();

    // O 'load' agora é diferente
    void setTextura();
    sf::Texture* getTextura(int indice);
}; 

