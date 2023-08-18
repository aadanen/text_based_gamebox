#ifndef GAMEBOX_H
#define GAMEBOX_H

#include <hangman.h>
#include <vector>
// Do I need like an array of possible game choices?
// How tf do I do that?
class Gamebox
{
private:
    // Game[] games = {Hangman(), }
    std::vector<Game*> games;
    unsigned int selected_game;
    void display_games();
    // void pick_game();
public:
    void start();
    void add_game(Game* gptr);
    // void play(Game g) ??
};

#endif

