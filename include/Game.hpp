#ifndef __GAME_H__
#define __GAME_H__

#include <string>

/** A class for reading game .csv file */

class Game {
    public:
    Game();
    ~Game();

    // int getSize();
    // void setSize(int size);

    std::string getName();
    void setName(std::string n);

    bool getOnline();
    void setOnline(bool o);

    double getSales();
    void setSales(double s);

    std::string getConsole();
    void setConsole(std::string c);

    char getRating();
    void setRating(char r);

    int getReleaseYear();
    void setReleaseYear(int y);


    private:
        // int size;
        std::string name;
        bool online;
        double sales;
        std::string console;
        char rating;
        int year;
};

#endif // __GAME_H__