#pragma once
#include "Player.hpp"

namespace coup{

    /**
     * @brief Ambassador header file
     * 
     */
    class Ambassador : public Player{
        public:
        /**
         * @brief Construct a new Ambassador object
         * 
         * @param _game 
         * @param player_name 
         */
        Ambassador(Game& _game, const std::string& player_name);

        /**
         * @brief Transfer a coin from a player to another
         * 
         * @param a 
         * @param b 
         */
        void transfer(Player& a, Player& b);

        /**
         * @brief Blocks captain from stealing coins
         * 
         * @param b 
         */
        void block(Player& b);

    };
}