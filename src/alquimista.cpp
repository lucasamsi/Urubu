#include "alquimista.hpp"
#include <iostream>
#include <cstdlib> // Para gerar números aleatórios

// Construtor da classe Alquimista
Alquimista::Alquimista(const std::string& nome)
    : Personagem(nome, 90, 12, 6, 8, 14) {} // Vida menor, mas inteligência alta

// Habilidade especial: Criar Poção
void Alquimista::criarPocao() {
    int efeito = rand() % 3; // Três tipos de poções possíveis

    switch (efeito) {
        case 0: // Poção de Cura
            std::cout << nome << " criou uma Poção de Cura e restaurou 20 pontos de vida!\n";
            setVida(getVida() + 20);
            break;

        case 1: // Poção de Força
            std::cout << nome << " criou uma Poção de Força! Seu ataque aumentou temporariamente.\n";
            setAtaque(getAtaque() + 5);
            break;

        case 2: // Poção de Agilidade
            std::cout << nome << " criou uma Poção de Agilidade! Sua defesa aumentou temporariamente.\n";
            setDefesa(getDefesa() + 5);
            break;
    }
}