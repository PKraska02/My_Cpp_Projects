import<iostream>;
import Player;
import Game;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>


int main()
{
    Game newgame;
    //Game loop
    while (newgame.IsGameRunning())
    {

        newgame.UpdateGame();
        newgame.RenderGame();

    }

    return 0;
}