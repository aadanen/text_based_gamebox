#include <iostream>

#include <gamebox.h>

void Gamebox::open()
{
    // Display all the games and let the user choose
    // For now theres only 1 choice so just pick it
    for (int i = 0; i < NUM_GAMES; i++)
    {
        std::cout << games[i].get_title() << std::endl;
    }

}
