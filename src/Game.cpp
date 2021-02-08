#include "Game.hpp"

Game::Game(){}

Game::~Game(){}

std::string Game::getName(){ 
    return name;
}

void Game::setName(std::string n){
    this->name = n;
}

bool Game::getOnline(){
    return online;
}

void Game::setOnline(bool o){
    this->online = o;
}

double Game::getSales(){
    return sales;
}

void Game::setSales(double s){
    this->sales = s;
}

std::string Game::getConsole(){
    return this->console;
}

void Game::setConsole(std::string c){
    this->console = c;
}

char Game::getRating(){
    return this->rating;
}

void Game::setRating(char r){
    this->rating = r;
}

int Game::getReleaseYear(){
    return this->year;
}

void Game::setReleaseYear(int y){
    this->year = y;
}