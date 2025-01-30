// Arquivo: item.cpp

#include "item.h"

// Construtor da classe Item
Item::Item(const std::string& nome, int preco, int bonusAtaque, int bonusDefesa, int bonusVida)
    : nome(nome), preco(preco), bonusAtaque(bonusAtaque), bonusDefesa(bonusDefesa), bonusVida(bonusVida) {}

// Retorna o nome do item
std::string Item::getNome() const {
    return nome;
}

// Retorna o preço do item
int Item::getPreco() const {
    return preco;
}

// Retorna o bônus de ataque fornecido pelo item
int Item::getBonusAtaque() const {
    return bonusAtaque;
}

// Retorna o bônus de defesa fornecido pelo item
int Item::getBonusDefesa() const {
    return bonusDefesa;
}

// Retorna o bônus de vida fornecido pelo item
int Item::getBonusVida() const {
    return bonusVida;
}
