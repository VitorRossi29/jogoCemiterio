#pragma once
#include "Jogador.h"
#include <time.h>
#include <stdlib.h>

#define RAIO_PERSEGUIR_X 200.0f
#define RAIO_PERSEGUIR_Y 200.0f

namespace CaveiraDeCristal
{
    namespace Entidades
    {
        namespace Personagens
        {
            class Inimigo : public Personagem
            {
            private:
                Jogador* jogador;
                short moveAleatorio;
                sf::Clock relogioAleatorio;
            public:
                Inimigo(const sf::Vector2f pos, const sf::Vector2f tam, Jogador* jog, const float velo);
                ~Inimigo();
                void persegueJogador(sf::Vector2f posJogador, sf::Vector2f posInimigo);
                void movimentoAleatorio();
                void atualizar();
                void colisao() {};
            };
        }
    }
}


