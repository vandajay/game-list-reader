#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

std::vector<Game*>* getGames(){ // ! finish getGames() function. This is a function signature.
    std::vector<Game*> *games = new std::<Game*>;
    std::ifstream input("./data/video_games.csv");

    if(!input.is_open()) throw std::runtime_error("File can't be opened.");

    std::string line;
    std::string piece;

    if(!input.is_open()){
        // Remove the first line;
        std::getline(input, line);
        while(std::getline(input, line, '\n')){
            
        }
    }
}

TEST_CASE( "Testing...", "[all]" ) {
    std::vector<Game*> *games = getGames(); // ! finish getGames() function. Made a pointer because- 
    REQUIRE( games->size() == 1114);
    Game* g = games->at(222);
    REQUIRE( g->getName() == "WWE SmackDown vs. Raw 2007" );
    g = games->at(235);
    REQUIRE( g->getName() == "Rockstar Games presents Table Tennis");
    REQUIRE( !g->getOnline());
    g = games->at(254);
    REQUIRE( g->getSales() == 0.23 );
    g = games->at(541);
    REQUIRE( g->getConsole() == "PlayStation 3");
    g = games->at(978);
    REQUIRE( g->getRating() == 'M');
    g = games->at(1113);
    REQUIRE( g->getName() == "Chicken Hunter");
    REQUIRE( g->getReleaseYear() == 2008);
    double value = 0;
    for(auto it=games->begin(); it!=games->end(); ++it){ // Vector of game pointers
        value += (*it)->getSales();
    }
    REQUIRE( value > 574.3);
    REQUIRE( value < 574.4);
}