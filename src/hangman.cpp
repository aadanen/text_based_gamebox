#include <hangman.h>
#include <text_manipulator.h>
#include <iostream>
// make stubs for this and then see about getting the files to stitch together just with the command line options
// then try making a makefile
void Hangman::init(std::string keyword)
{
    Hangman::keyword = keyword;
    correct_guesses = TextManipulator::repeat_character('_', keyword.size());
    incorrect_guesses = "";
    game_over = false;
}

void Hangman::play()
{
    std::cout << "Lets Play Hangman!" << std::endl;
    std::cout << "Enter the keyword:" << std::endl;

    std::string keyword;
    std::getline(std::cin, keyword);
    init(keyword);
    
    while (!game_over)
    {
        std::cout << display();
        std::cout << "Make a guess!" << std::endl;
        char g;
        g = std::cin.get();
        std::cin.ignore();
        guess(g);
        game_over = is_game_over();
    }
    std::cout << display();
    if (bros_dead())
    {
        std::cout << "Homie died because you couldn't guess the keyword..." << std::endl;
    }
    else 
    {
        std::cout << "You saved them! Nice! :)" << std::endl;
    }
}

// Takes a char and then compares it to keyword. Sorts into correct or incorrect
void Hangman::guess(char guess)
{
    unsigned int i = 0;
    bool no_matches = true;
    std::string result = "";
    while (i < keyword.size())
    {
        if (guess == keyword[i])
        {
            result += guess;
            no_matches = false;
        }
        else
        {
            result += correct_guesses[i];
        }
        i++;
    }

    if (!no_matches)
    {
        correct_guesses = result;
    }
    
    if (no_matches)
    {
        incorrect_guesses += guess;
    }
    
}

bool Hangman::is_game_over()
{
    return incorrect_guesses.size() > 5 || correct_guesses == keyword;
}

bool Hangman::bros_dead()
{
    if (incorrect_guesses.size() > 5)
    {
        return true;
    }
    return false;
}

std::string Hangman::display()
{
    std::string result = keyword + '\n';
    result += correct_guesses + '\n';
    result += incorrect_guesses + '\n';
    return result;
}
