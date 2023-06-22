import<iostream>;
import<memory>;
import Player;
import Game;
import Menu;
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Network.hpp>
#include <SFML/System.hpp>


int main()
{
    std::unique_ptr<Game> newgame = std::make_unique<Game>();
    std::unique_ptr<Menu> menu = std::make_unique<Menu>(newgame->GetWindow(), newgame.get());
    while (newgame->IsGameRunning()) {
        if (!menu->MenuEvent()) {
            while (newgame->IsGameRunning()) {
                newgame->UpdateGame();
                newgame->RenderGame();
                if (newgame->IsWin()) {
                    menu->DrawWin();
                    newgame->CreateHighScoreFile();
                    break; 
                }
                if (newgame->IsGameOver()) {
                    menu->DrawLose();
                    newgame->CreateHighScoreFile();
                    break;
                }
            }
        }
        newgame=std::make_unique<Game>();
        menu = nullptr;
        menu= std::make_unique<Menu>(newgame->GetWindow(), newgame.get());
        if (menu->MenuEvent()) {
            break;
        }

    }
     return 0;

   
}
