#pragma once
#include "Game.hpp"
namespace coup
{
    /**
     * @brief Basic class of "Player" object which holds the default operations the rest of the players can do
     * Each "role" inherit Player
     * 
     * * Might add more variables (if needed)
     * 
     */
    class Player{
        protected:           // Can be inherited 
        int number_of_coins; // Amount of coins each player holds
        std::string title;   // Role of a player
        std::string name;    // Name of the player
        Game game;           // Game

        public:

        /**
         * @brief Construct a new Player object
         * 
         * @param _game 
         * @param player_name 
         */
        Player(Game& _game , const std::string& player_name); 

        /**
         * @brief Amount of coins the player has
         * 
         * @return int 
         */
        int coins() const;

        /**
         * @brief Role of the player
         * 
         * @return std::string 
         */
        std::string role();

        /**
         * @brief Grants the player a single coin
         * 
         */
        void income();

        /**
         * @brief Grants the player 2 coins (Can be blocked)
         * 
         */
        void foreign_aid();

        /**
         * @brief End another player's live! 
         * Assassin's require 3 coins and the rest 7.
         * If a player holds 10 coins the coup() starts automatically
         * 
         * virtual so it can be implemented differently in assassin.cpp
         * @param b 
         */
        virtual void coup(Player& b);

    };
} 
