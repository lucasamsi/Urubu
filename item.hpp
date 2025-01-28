// Arquivo: item.hpp

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

// Classe Item
class Item {
private:
    std::string nome;   // Nome do item
    int preco;          // Preço do item
    int bonusAtaque;    // Bônus de ataque
    int bonusDefesa;    // Bônus de defesa
    int bonusVida;      // Bônus de vida

public:
    // Construtor
    Item(const std::string& nome, int preco, int bonusAtaque, int bonusDefesa, int bonusVida);

    // Métodos getters
    std::string getNome() const;
    int getPreco() const;
    int getBonusAtaque() const;
    int getBonusDefesa() const;
    int getBonusVida() const;
};

#endif