#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Game.hpp"
#include <iostream>
#include <vector>

std::vector<Game*>* getGames(){
    // Create vector of pointers to games
    std::vector<Game*> *games = new std::vector<Game*>;

    // Open file
    std::ifstream input("./data/video_games.csv");
    if(!input.is_open()) throw std::runtime_error("File can't be opened.");

    std::string line;
    std::string piece;

    if(input.is_open()){
        // Remove the first line
        std::getline(input, line);

        while(std::getline(input, line, '\n')){
            std::stringstream ss(line);
            Game* tmp = new Game();

            // Skip first line
            getline(ss, piece, ',');
            tmp->setName(piece);

            // Skip handheld, players, multiplatform
            getline(ss, piece, ',');
            getline(ss, piece, ',');
            getline(ss, piece, ',');
            getline(ss, piece, ',');

            if(piece.find("True")){
                tmp->setOnline(true);
            } else {
                tmp->setOnline(false);
            }

            // Skip genre, licensed, publisher, sequel, score
            getline(ss, piece, ',');
            getline(ss, piece, ',');
            getline(ss, piece, ',');
            getline(ss, piece, ',');
            getline(ss, piece, ',');
            getline(ss, piece, ',');

            tmp->setSales(std::stod(piece));

            // Skip price
            getline(ss, piece, ',');
            getline(ss, piece, ',');

            tmp->setConsole(piece);

            getline(ss, piece, ',');

            tmp->setRating(piece[0]);

            // Skip re-release
            getline(ss, piece, ',');
            getline(ss, piece, ',');

            tmp->setReleaseYear(std::stoi(piece));
            std::cout << tmp->getName() << std::endl;
            games->push_back(tmp);
        }
    }
    return games;
}

TEST_CASE( "Testing...", "[all]" ) {
    std::vector<Game*> *games = getGames();
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
    for(auto it=games->begin(); it!=games->end(); ++it){
        value += (*it)->getSales();
    }
    REQUIRE( value > 574.3);
    REQUIRE( value < 574.4);
}