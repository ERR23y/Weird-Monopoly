#include "Player.hpp"

namespace coup{
    /**
     * @brief Documatation found in the "Player.hpp" file
     * 
     */

    Player::Player(Game& _game , const std::string& player_name) : game(_game), name(player_name){
        this->number_of_coins = 0; // Each player starts with a zero coins(?)
        this->title = " ";         // Role of the player
    };

    int Player::coins() const {
        return this->number_of_coins;
    }

    std::string Player::role(){
        return this->title;
    }

    void Player::income(){}

    void Player::foreign_aid(){}

    void Player::coup(Player& b){}
}
