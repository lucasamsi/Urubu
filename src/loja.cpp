// Arquivo: loja.cpp

#include "loja.hpp"
#include <iostream>

// Construtor da Loja: inicializa a lista de itens disponíveis
Loja::Loja() {
    itens.push_back(Item("Espada", 50, 10, 0, 0));
    itens.push_back(Item("Escudo", 40, 0, 10, 0));
    itens.push_back(Item("Poção de Vida", 30, 0, 0, 20));
}

// Exibe os itens disponíveis na loja
void Loja::exibirItens() {
    std::cout << "\n--- Loja ---\n";
    for (size_t i = 0; i < itens.size(); ++i) {
        std::cout << i + 1 << ". " << itens[i].getNome() << " (Preço: " << itens[i].getPreco() << ")\n";
    }
}

// Permite ao jogador comprar um item
void Loja::comprarItem(int escolha, Personagem& jogador, int& ouro) {
    if (escolha < 1 || escolha > static_cast<int>(itens.size())) {
        std::cout << "Escolha inválida.\n";
        return;
    }

    Item item = itens[escolha - 1];
    if (ouro >= item.getPreco()) {
        ouro -= item.getPreco();
        jogador.setVida(jogador.getVida() + item.getBonusVida());
        std::cout << "Você comprou " << item.getNome() << "!\n";
    } else {
        std::cout << "Ouro insuficiente para comprar " << item.getNome() << ".\n";
    }
}
