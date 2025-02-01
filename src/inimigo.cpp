

#include "inimigo.hpp"
#include <iostream>


Inimigo::Inimigo(const std::string& nome, int vida, int ataque, int defesa, int agilidade)
    : Personagem(nome, vida, ataque, defesa, agilidade, 0) {} // Inimigos não têm carisma


void Inimigo::atacar(Personagem& alvo) {
    std::cout << nome << " ataca ferozmente " << alvo.getNome() << " causando "
              << ataque - alvo.getDefesa() << " de dano!\n";
    Personagem::atacar(alvo);
}
