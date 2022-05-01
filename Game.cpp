#include "Game.hpp"


/**
 * @brief Documantation is in Game.hpp file (header)
 * 
 */

namespace coup {
    Game::Game() {
        this->pile_of_coins = 0; // Global pile of coins
        this->current_turn = ""; // Current turn of player X - each player that joins have a turn
        this->game_winner = "";  // Winner of the game, can be with minimum 2 players
        this->running = true;    // Is game still on?
    }

    std::vector<std::string> Game::players(){
        return this->list_of_players;
    }

    std::string Game::turn(){
        return this->current_turn;
    }

    std::string Game::winner(){
        return goingOn() ? throw std::exception() : this->game_winner;
    }

    bool Game::goingOn() const{
        return this->running;
    }

    void Game::endGame(){
        if (!(this->list_of_players.size() > 1)) // Amount players is less than 2 and trying to finish the game
        {
            throw std::exception();
        }
        
        this->running = false;
    }
}