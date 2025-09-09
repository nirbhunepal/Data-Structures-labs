#ifndef __COIN_H
#define __COIN_H
#include "gradable.h"

class Coin : public Gradable {
public:
    Coin(std::string donor_name, int donor_year, int mint_year,
         std::string mint_location, std::string coin_material, bool special_coin = false)
        : Gradable{donor_name, donor_year}, m_mint_year{mint_year},
          m_mint_location{mint_location}, m_coin_material{coin_material},
          m_special_coin{special_coin} {}

    void Grade() override;
    void Value() override;

private:
    int m_mint_year{};
    std::string m_mint_location{};
    std::string m_coin_material{};
    bool m_special_coin{};
};

#endif
