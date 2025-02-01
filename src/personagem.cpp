

#include "personagem.hpp"
#include <algorithm> 


Personagem::Personagem(const std::string& nome, int vida, int ataque, int defesa, int agilidade, int carisma)
    : nome(nome), vida(vida), maxVida(vida), ataque(ataque), defesa(defesa), agilidade(agilidade), carisma(carisma) {}


std::string Personagem::getNome() const {
    return nome;
}


int Personagem::getVida() const {
    return vida;
}


void Personagem::setVida(int novaVida) {
    vida = std::max(0, std::min(novaVida, maxVida));
}

int Personagem::getDefesa() const {
    return defesa;
}

void Personagem::setDefesa(int novaDefesa) {
    defesa = novaDefesa;
}

int Personagem::getAtaque() const {
    return ataque;
}

void Personagem::setAtaque(int novoAtaque) {
    ataque = novoAtaque;
}


void Personagem::atacar(Personagem& alvo) {
    int dano = std::max(1, ataque - alvo.getDefesa());
    alvo.setVida(alvo.getVida() - dano);
    std::cout << nome << " atacou " << alvo.getNome() << " causando " << dano << " de dano.\n";
}


void Personagem::defender() {
    std::cout << nome << " está se defendendo, aumentando sua defesa temporariamente!\n";
    defesa += 5;
}


void Personagem::curar(Personagem& aliado) {
    std::cout << nome << " não possui habilidades de cura.\n";
}


void Personagem::convencer(Personagem& alvo) {
    std::cout << nome << " não possui habilidades de persuasão.\n";
}
