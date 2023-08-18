#include <gamebox.h>

int main()
{
    Gamebox box = Gamebox();

    // Allocate all the games on the heap and add them to the game box
    // ??? Shouldn't I only allocate the game once the user picks it ???
    Game* h = new Hangman();
    box.add_game(h);

    // User picks and plays a game
    box.start();

    // Don't cause a memory leak
    delete h;
    return 0;
}
