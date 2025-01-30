// Arquivo: guerreiro.hpp

#ifndef GUERREIRO_HPP
#define GUERREIRO_HPP

#include "personagem.hpp"

// Subclasse Guerreiro
class Guerreiro : public Personagem {
public:
    // Construtor
    Guerreiro(const std::string& nome);

    // Ataque especial do Guerreiro
    void atacar(Personagem& alvo) override;
};

#endif
