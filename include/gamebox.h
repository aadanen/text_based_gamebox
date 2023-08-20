#ifndef GAMEBOX_H
#define GAMEBOX_H

#include <hangman.h>
#include <tictactoe.h>
#include <vector>
// This keeps track of all the games that can be chosen
// All games a referenced via a Game* in the games std::vector
class Gamebox
{
private:
    std::vector<Game*> games; // All the games that we are allowed to play

    unsigned int selected_game; // which game the gamebox is currently set up to play

    void display_games(); // Show the user a list of all their options
                          
    void pick_game(); // Basically ask the user to pick a number from the list of games, and
                         // Set selected_game to their choice if its a valid one
                         
    // void choice_is_valid // I'm gonna want this one
public:
    void start(); // main gamebox driver function

    void add_game(Game* gptr); // used in main.cpp to add a game to the gamebox which can then be played
};

#endif

