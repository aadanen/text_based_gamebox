#ifndef GAMEBOX_H
#define GAMEBOX_H

#include <hangman.h>
// Do I need like an array of possible game choices?
// How tf do I do that?
class Gamebox
{
private:
    // Game[] games = {Hangman(), }
    Hangman h = Hangman();
    const static int NUM_GAMES = 1;
    Hangman games[NUM_GAMES] = {h};
public:
    void open();
    // void play(Game g) ??
};

#endif