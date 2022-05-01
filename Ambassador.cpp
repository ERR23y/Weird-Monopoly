#include "Ambassador.hpp"

namespace coup{

    /**
     * @brief Aambassador source file (to be implemented)
     * functions documnatation is found in Ambassador header file 
     * 
     */
    
    Ambassador::Ambassador(Game& _game, const std::string& player_name) : Player(_game,player_name) {}

    void Ambassador::transfer(Player& a, Player& b){}

    void Ambassador::block(Player& b){}
}