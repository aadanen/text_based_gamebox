#include <iostream>
#include <cassert>
#include <gamebox.h>
#include <game.h>

// Puts a given Game* into the games vector
void Gamebox::add_game(Game* gptr)
{
    games.push_back(gptr);
}


// Display each game in the games vector in format $POSITION. $TITLE
void Gamebox::display_games()
{
    for (int i = 0; i < (int) games.size(); i++)
    {
        std::cout << i << ". " << games[i]->get_title() << std::endl;
    }

}


// This ones kinda broken sorry

void Gamebox::pick_game()
{
    std::cout << "Enter a number from the list: " << std::endl;
    int user_input;
    std::cin >> user_input;
    while (!std::cin)
    {
        std::cin.clear();
        std::cin.ignore(100, '\n');
        std::cout << "Invalid input. Try again?" << std::endl;
        std::cin >> user_input;
    }
    selected_game = user_input;
    std::cin.ignore();
    std::cin.clear();
}


// main driver code
void Gamebox::start()
{
    // Display all the games and let the user choose
    std::cout << "Welcome to my text based gamebox :)\n";
    display_games();
    pick_game();
    std::cout << selected_game << std::endl;
    std::cout << "You picked: " << games[selected_game]->get_title() << std::endl;
    games[selected_game]->play();
}
