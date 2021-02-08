#ifndef __GAME_H__
#define __GAME_H__

#include <string>

/** 
 * Game Class
 * 
 * A class for reading .csv file with list of games of games.
 * 
 * Columns (comma delimiter):
 * Title, handheld, max players, multiplatform, online, genre,
 * licensed, publisher, sequel, review, sales, price, console,
 * rating, re-release, release year
 * 
 * Rows:
 * Individual games
*/

class Game {
    public:
    Game();
    ~Game();

    // Get & Set functions
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
        std::string name;
        bool online;
        double sales;
        std::string console;
        char rating;
        int year;
};

#endif // __GAME_H__