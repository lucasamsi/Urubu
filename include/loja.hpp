// Arquivo: loja.hpp

#ifndef LOJA_HPP
#define LOJA_HPP

#include <vector>
#include "item.hpp"
#include "personagem.hpp"

// Classe Loja
class Loja {
private:
    std::vector<Item> itens; // Lista de itens disponíveis na loja

public:
    // Construtor
    Loja();

    // Exibe os itens disponíveis
    void exibirItens();

    // Permite ao jogador comprar um item
    void comprarItem(int escolha, Personagem& jogador, int& ouro);
};

#endif