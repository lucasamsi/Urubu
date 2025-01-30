// Arquivo: bardo.hpp

#ifndef BARDO_HPP
#define BARDO_HPP

#include "personagem.hpp"

// Subclasse Bardo
class Bardo : public Personagem {
public:
    // Construtor
    Bardo(const std::string& nome);

    // Habilidade especial: Convencer
    void convencer(Personagem& alvo) override;
};

#endif
