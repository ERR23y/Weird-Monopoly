#include "Captain.hpp"

namespace coup{
    /**
     * @brief Captain source file (to be implemented)
     * functions documnatation is found in captain header file 
     * 
     */
    Captain::Captain(Game& _game, const std::string& player_name) : Player(_game,player_name) {}
    void Captain::block(Player& a){}
    void Captain::steal(Player& a){}
}