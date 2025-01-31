// Arquivo: personagem.cpp

#include "personagem.hpp"
#include <algorithm> // Para usar std::max e std::min

// Construtor da classe base Personagem
Personagem::Personagem(const std::string& nome, int vida, int ataque, int defesa, int agilidade, int carisma)
    : nome(nome), vida(vida), maxVida(vida), ataque(ataque), defesa(defesa), agilidade(agilidade), carisma(carisma) {}

// Retorna o nome do personagem
std::string Personagem::getNome() const {
    return nome;
}

// Retorna os pontos de vida atuais
int Personagem::getVida() const {
    return vida;
}

// Ajusta os pontos de vida (limitando entre 0 e o máximo)
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

// Ação de ataque básico
void Personagem::atacar(Personagem& alvo) {
    int dano = std::max(1, ataque - alvo.getDefesa());
    alvo.setVida(alvo.getVida() - dano);
    std::cout << nome << " atacou " << alvo.getNome() << " causando " << dano << " de dano.\n";
}

// Ação de defesa (aumenta a defesa temporariamente)
void Personagem::defender() {
    std::cout << nome << " está se defendendo, aumentando sua defesa temporariamente!\n";
    defesa += 5;
}

// Método genérico para cura (implementado apenas em subclasses específicas)
void Personagem::curar(Personagem& aliado) {
    std::cout << nome << " não possui habilidades de cura.\n";
}

// Método genérico para convencer (implementado apenas em subclasses específicas)
void Personagem::convencer(Personagem& alvo) {
    std::cout << nome << " não possui habilidades de persuasão.\n";
}
