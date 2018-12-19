#include <iostream>
#include <vector>
#include <time.h>
#include <cstdlib>
#include <conio.h>
#include <windows.h>
#include "Card.h"
#include <conio.h>

using namespace std;

int main()
{



        srand(time(NULL));

        Table game;
        game.SetNumberOfPlayers();
        game.setCoins();
        game.initCard();


        while (game.gra)
        {
            system("cls");
            game.updateTable();

            game.showCard2();
            cout<<endl<<"Zetony na stole :";
            game.showCoin(game.coins);

            if(!game.playerline[0].autoplay)
            game.action(&game.playerline[0]);
            else
            game.simpleSiAutoplay(&game.playerline[0]);
        }


    return 0;
}
