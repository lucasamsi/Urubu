// Arquivo: inimigo.cpp

#include "inimigo.h"
#include <iostream>

// Construtor da classe Inimigo
Inimigo::Inimigo(const std::string& nome, int vida, int ataque, int defesa, int agilidade)
    : Personagem(nome, vida, ataque, defesa, agilidade, 0) {} // Inimigos não têm carisma

// Ataque básico do inimigo
void Inimigo::atacar(Personagem& alvo) {
    std::cout << nome << " ataca ferozmente " << alvo.getNome() << " causando "
              << ataque - alvo.getDefesa() << " de dano!\n";
    Personagem::atacar(alvo);
}