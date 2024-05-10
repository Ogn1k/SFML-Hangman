#include "Game.h"

int main()
{
    std::setlocale(LC_ALL, "Russian");

    Game::getInstance().run();

    return 0;
}