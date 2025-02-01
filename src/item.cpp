

#include "item.hpp"


Item::Item(const std::string& nome, int preco, int bonusAtaque, int bonusDefesa, int bonusVida)
    : nome(nome), preco(preco), bonusAtaque(bonusAtaque), bonusDefesa(bonusDefesa), bonusVida(bonusVida) {}


std::string Item::getNome() const {
    return nome;
}


int Item::getPreco() const {
    return preco;
}


int Item::getBonusAtaque() const {
    return bonusAtaque;
}


int Item::getBonusDefesa() const {
    return bonusDefesa;
}


int Item::getBonusVida() const {
    return bonusVida;
}
