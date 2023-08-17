#include <gamebox.h>

int main()
{
    Gamebox box = Gamebox();
    Game* h = new Hangman();
    box.add_game(h);
    box.start();
    delete h;
    return 0;
}
