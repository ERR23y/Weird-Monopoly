#pragma once
#include "Player.hpp"

namespace coup{
    /**
     * @brief Assassin header file
     * 
     */
    class Assassin : public Player{
        public:
        /**
         * @brief Construct a new Assassin object
         * 
         * @param _game 
         * @param player_name 
         */
        Assassin(Game& _game, const std::string& player_name);

        /**
         * @brief Can coup another player with 3 coins
         * 
         * @param b 
         */
        void coup(Player& b) override;

    };
}