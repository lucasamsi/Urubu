#ifndef ALQUIMISTA_HPP
#define ALQUIMISTA_HPP

#include "personagem.hpp"

// Subclasse Alquimista
class Alquimista : public Personagem {
public:
    // Construtor
    Alquimista(const std::string& nome);

    // Habilidade especial: Criar Poção
    void criarPocao();
};

#endif