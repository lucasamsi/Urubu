// Arquivo: bardo.cpp

#include "bardo.h"
#include <iostream>
#include <cstdlib> // Para gerar números aleatórios

// Construtor da classe Bardo
Bardo::Bardo(const std::string& nome)
    : Personagem(nome, 100, 10, 8, 6, 12) {}

// Habilidade especial: Convencer
void Bardo::convencer(Personagem& alvo) {
    int chance = carisma * 10; // Chance de sucesso baseada no carisma
    if (rand() % 100 < chance) {
        std::cout << nome << " convenceu " << alvo.getNome() << " a recuar temporariamente!\n";
        alvo.setVida(alvo.getVida() - 5); // Um pequeno dano psicológico
    } else {
        std::cout << nome << " tentou convencer " << alvo.getNome() << ", mas falhou.\n";
    }
}
