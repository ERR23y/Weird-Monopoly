#pragma once
#include <string>
#include <vector>
#include <exception>

namespace coup
{
    /**
     * @brief Class of Game which holds -
     *          - A list of players
     *          - Current turn of a player
     *          - Game winner
     *          - General pile of coins (which each player takes)
     *          - Is the game still on?
     *      
     * 
     *      **Might add more since it's only first part and have to implement all functions**
     */
    class Game{
        // Class default is private - Therefore, all the above are private members of the class
        std::vector<std::string> list_of_players;
        std::string current_turn;
        std::string game_winner;
        int pile_of_coins;
        bool running;

        public:
        /**
         * @brief Construct a new Game object
         * 
         */
        Game();

        /**
         * @brief Holds a list of players
         * 
         * @return std::vector<std::string> 
         */
        std::vector<std::string> players();

        /**
         * @brief Turn of who?
         * 
         * @return std::string 
         */
        std::string turn();

        /**
         * @brief Game winner - if game still on throws an exception
         * 
         * @return std::string 
         */
        std::string winner();

        /**
         * @brief Is the game still on?
         * 
         * @return true 
         * @return false 
         */
        bool goingOn() const;

        /**
         * @brief Finishes the game (minimum of 2 players is required else - exception)
         * 
         */
        void endGame();
    };
} 
