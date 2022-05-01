#include "doctest.h"
#include "Game.hpp"
#include "Ambassador.hpp"
#include "Assassin.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Duke.hpp"



using namespace coup;
/**
 * @brief Mutlpile tests of the game which checks of the functions work properly.
 * 
 */
TEST_CASE(""){
    
    /**
     * @brief Checks for winner(), endGame() methods
     * as well if the players whom are join to the game are actually in the game by printing a list + verify their location in the list
     * 
     */
    SUBCASE("Basic winner/game finish methods + players list"){
        Game game{};
        CHECK_NOTHROW(Ambassador(game,"ohad")); // Add first player
        CHECK(game.turn() == "ohad"); // Each player that join get his turn
        CHECK_THROWS(game.winner()); // Throws an exception if game is still on
        CHECK_THROWS(game.endGame()); // Cannot finish game with less than 2 players
        CHECK_NOTHROW(Assassin(game,"shlomo"));
        CHECK_NOTHROW(game.endGame());
        CHECK_NOTHROW(game.winner());
        CHECK(game.winner() == "ohad");
        // Check if same classes can be add over and over
        CHECK_NOTHROW(Captain(game,"yoram"));
        CHECK_NOTHROW(Captain(game,"horev"));
        CHECK_NOTHROW(Captain(game,"bbm"));
        CHECK_NOTHROW(Duke(game,"elad"));
        CHECK_NOTHROW(Duke(game,"gil levi"));
        CHECK_NOTHROW(Contessa(game,"shlomit"));
        CHECK_EQ(game.players().size(), 8);
        CHECK(game.players().at(8) == "shlomit");
        CHECK(game.players().at(7) == "gil levi");
        CHECK(game.players().at(6) == "elad");
        CHECK(game.players().at(5) != "gil levi");
        CHECK(game.players().at(4) == "horev");
        CHECK(game.players().at(3) == "yoram");
        CHECK(game.players().at(2) == "shlomo");
        CHECK(game.players().at(1) == "ohad");
    }

    /**
     * @brief Verify the role of the player,
     * Various methods can be used even tho it isn't the player's turn
     * Checks for duke blockage ( duke calls for block() ) of double coins withdrawal (foreign aid)
     * Check what happens when Contessa tries to block() the assassin even though he didn't call for a coup
     * Verify that asssassin can call for a coup with a 3 coins
     * Verify that the coup'd player by the assassin actually got coup'd and he's not on the players list
     * Contessa blocks the assassin and see if the coup'd player returns (Duke)
     * .
     * .
     * .
     * etc... (more is written in comment of each line)
     * 
     * 
     */
    SUBCASE("roles verify, multiple income when already used, block() check for every class, coup - Game run"){
        Game b{};
        Assassin hashashin(b, "Altair");
        CHECK_EQ(hashashin.role(), "Assassin");
        CHECK_NE(hashashin.role(), "Contessa");
        hashashin.income();
        CHECK(hashashin.coins() == 1);
        CHECK_THROWS(hashashin.income()); // Already used it turn!
        Duke Charles(b,"Charles");
        Charles.income();
        hashashin.foreign_aid();
        CHECK(hashashin.coins() == 3);
        Charles.block(hashashin); // Prevents altair getting 2 more coins
        CHECK(hashashin.coins() == 1);
        Contessa Emilia(b,"Emilia"); // Checking for assassinate func
        CHECK_THROWS(Emilia.block(hashashin)); // Check if can block altair if he didn't Assassinate 
        Emilia.income();
        hashashin.foreign_aid(); // Should have 3 coins so can assassinate
        Charles.foreign_aid();
        Emilia.foreign_aid();
        CHECK_NOTHROW(hashashin.coup(Charles));
        bool flag = false;
        for (std::string st : b.players()){ // Check if altair assassianted Prince Charles
            if (st == "Charles")
            {
                flag = true;
            } 
        }
        CHECK_EQ(flag, true);
            
        CHECK_NOTHROW(Emilia.block(hashashin)); // Should prevent from assassinate
        flag = false;

        for (std::string st : b.players()){ // Check if Contessa managed to block Altair's assassiante
            if (st == "Charles")
            {
                flag = true;
            } 
        }
        CHECK_EQ(flag, false);
        
        Captain Jack(b,"Jack Sparrow");
        Jack.steal(Emilia); // Jack sparrow steals from Emilia
        CHECK(Emilia.coins() == 1); // Check if Jack stole from Emilia
        CHECK(Jack.coins() == 2); // Check if Jack stole from Emilia
        Ambassador Dani(b,"Danny Danon");
        CHECK_NOTHROW(Dani.block(Jack)); // Prevents Jack sparrow's stealing
        CHECK(Emilia.coins() == 3); // Verify Emilia coins 
        CHECK(Jack.coins() == 0); // Check if Jack stole from Emilia
        CHECK_THROWS(Dani.transfer(Jack,Emilia)); // Already used it turn
        CHECK_THROWS(Jack.income()); // Not jack's turn!
        CHECK_NOTHROW(hashashin.foreign_aid()); // 5 coins
        Charles.tax(); // 6 coins
        CHECK_THROWS(Emilia.block(Charles)); // Cannot block tax() function and either non-assassin chars
        Jack.foreign_aid(); // 2 coins
        CHECK_THROWS(Dani.transfer(Jack,Jack)); // Cannot transfer to same character
        hashashin.foreign_aid(); // 7 coins
        Charles.tax(); // 9 coins (!!)
        CHECK_THROWS(Emilia.block(Jack)); // Jack didn't call for a coup
        CHECK_NOTHROW(Jack.steal(Emilia)); // Jack turns and he wants to steal from emilia
        Dani.transfer(Jack,Charles);
        // Charles has 10 coins therefore should be a coup
        CHECK_NOTHROW(Charles.coup(hashashin)); // Sorry altair :( see you in the next Assassin's creed
    }

    /**
     * @brief Another edge case to check whether can be transfered coins & steal from players with 0 coins
     * 
     */
    SUBCASE("Can steal/transfer 0 points?"){
         Game c{};
         Ambassador Danon(c,"Danny Danon");
         Captain Sparrow(c,"Jack sparrow");
         CHECK_THROWS(Sparrow.steal(Danon)); // Can't steal from someone with 0 points
         Duke dik(c,"The duke");
         CHECK_THROWS(dik.coup(Sparrow)); // Cannot coup with less than 7 points
         CHECK_THROWS(Danon.transfer(Sparrow,dik)); // Cannot transfer coins from a person with 0 coins
    }
















    


}