// Arquivo: inimigo.hpp

#ifndef INIMIGO_HPP
#define INIMIGO_HPP

#include "personagem.hpp"

// Classe Inimigo (derivada de Personagem)
class Inimigo : public Personagem {
public:
    // Construtor
    Inimigo(const std::string& nome, int vida, int ataque, int defesa, int agilidade);

    // Ataque básico do inimigo
    void atacar(Personagem& alvo) override;
};

#endif
