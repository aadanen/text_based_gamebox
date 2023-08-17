#ifndef GAME_H
#define GAME_H

#include <string>
class Game
{
    public:
        void tester();
        virtual void play()=0;
        virtual std::string get_title()=0;
        virtual ~Game();
};

#endif
