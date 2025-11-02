#pragma once

#include <SFML/Graphics.hpp>
#include "Jogador.h"

class Jogo
{
private:
    Jogador pJog1;
    // GerenciadorGrafico GG;
    // ...
    
    sf::RenderWindow window;
    sf::Texture textura_jogador2; 
public:
    Jogo();
    ~Jogo();
    void executar();
    // ...
};

