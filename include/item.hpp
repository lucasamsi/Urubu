

#ifndef ITEM_HPP
#define ITEM_HPP

#include <string>

class Item {
private:
    std::string nome;   
    int preco;          
    int bonusAtaque;    
    int bonusDefesa;    
    int bonusVida;      

public:
    
    Item(const std::string& nome, int preco, int bonusAtaque, int bonusDefesa, int bonusVida);

    
    std::string getNome() const;
    int getPreco() const;
    int getBonusAtaque() const;
    int getBonusDefesa() const;
    int getBonusVida() const;
};

#endif