#ifndef HANGMAN_H
#define HANGMAN_H

#include <string>
class Hangman
{
private:
    std::string keyword;
    std::string correct_guesses;
    std::string incorrect_guesses;
    bool game_over;
    // Validate user input for use in init
    // make init a bool for initilized succesfully or not
    void guess(char guess);
    void init(std::string keyword);
    bool is_game_over();
    bool bros_dead();
    std::string display();
public:
    void play();
    std::string get_title();
};

#endif
