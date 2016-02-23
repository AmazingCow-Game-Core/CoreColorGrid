//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        main.cpp                                  //
//            █ █        █ █        CoreColorGrid                             //
//             ████████████                                                   //
//           █              █       Copyright (c) 2015, 2016                  //
//          █     █    █     █      AmazingCow - www.AmazingCow.com           //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
//                  This software is licensed as GPLv3                        //
//                 CHECK THE COPYING FILE TO MORE DETAILS                     //
//                                                                            //
//    Permission is granted to anyone to use this software for any purpose,   //
//   including commercial applications, and to alter it and redistribute it   //
//               freely, subject to the following restrictions:               //
//                                                                            //
//     0. You **CANNOT** change the type of the license.                      //
//     1. The origin of this software must not be misrepresented;             //
//        you must not claim that you wrote the original software.            //
//     2. If you use this software in a product, an acknowledgment in the     //
//        product IS HIGHLY APPRECIATED, both in source and binary forms.     //
//        (See opensource.AmazingCow.com/acknowledgment.html for details).    //
//        If you will not acknowledge, just send us a email. We'll be         //
//        *VERY* happy to see our work being used by other people. :)         //
//        The email is: acknowledgment_opensource@AmazingCow.com              //
//     3. Altered source versions must be plainly marked as such,             //
//        and must not be misrepresented as being the original software.      //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

//std
#include <iostream>
#include <iterator>
#include <sstream>
//CoreColorGrid
#include "../include/CoreColorGrid.h"
//Termcolor
#include "termcolor.h"

//Usings
USING_NS_CORECOLORGRID;
using namespace std;


// Helper Functions //
void printBoard(const GameCore &core);
void printCoreInfo(const GameCore &core);
void printPlayerInfo(const Player &player);

// Implementation //
int main()
{
    //Create the GameCore Options.
    GameCore::Options options;
    //Board
    options.boardWidth  = 7;
    options.boardHeight = 7;
    options.colorsCount = 7;
    //Players
    options.playersCount      = 2;
    options.humanPlayersCount = 2;
    options.startPlayerIndex  = 0;
    //AI.
    options.aiStrength = 5;
    //Other.
    options.maxMoves = GameCore::kUnlimitedMoves;
    options.seed     = 2;//GameCore::kRandomSeed;

    //Create the Game Core.
    GameCore core(options);

    //Game Loop.
    while(1)
    {
        //Info.
        cout << "--------------------" << endl;
        printBoard(core);
        cout << "--------------------" << endl;
        printCoreInfo(core);
        cout << "--------------------" << endl;
        printPlayerInfo(core.getCurrentPlayer());
        cout << "--------------------" << endl;

        //Prompt.
        cout << "Color? ";
        int a;
        cin >> a;

        //Make the change.
        const auto &changedCoords = core.changeColor(a);

        //Print info about the move.
        cout << "(" << changedCoords.size() << ") was changed." << endl;
    }
}


// Helper Functions //
void printBoard(const GameCore &core)
{
    auto &board = core.getBoard();
    for(auto &line : board)
    {
        for(auto &color : line)
        {
            int fgr = (color.getOwnerIndex() == Color::kInvalidOwner)
                       ? termcolor::GREY + color.getColorIndex() + 1
                       : termcolor::GREY;

            int bgr = (color.getOwnerIndex() == Color::kInvalidOwner)
                       ? termcolor::ON_GREY
                       : termcolor::ON_GREY + color.getColorIndex();

            auto options = termcolor::options(fgr, bgr);


            stringstream ss;
            ss << color.getColorIndex();

            cout << options(ss.str());
        }
        cout << endl;
    }
}
void printCoreInfo(const GameCore &core)
{
    //Players Info.
    cout << "Winner Player : ";
    Player *winnerPlayer = core.getWinnerPlayer();
    if(winnerPlayer)
         cout << winnerPlayer->getIndex();
    else
        cout << "None";
    cout << endl;

    cout << "Current Player: " << core.getCurrentPlayer().getIndex() << endl;
    cout << "Player Count  : " << core.getPlayersCount() << endl;
    cout << "Humans Count  : " << core.getHumanPlayersCount() << endl;

    //AI Info.
    cout << "AI Strength : " << core.getAIStrength() << endl;

    //Other Info.
    cout << "Game Is Over: " << core.gameIsOver() << endl;
    cout << "Max Moves   : " << core.getMaxMoves() << endl;
    cout << "Seed        : " << core.getSeed() << endl;

}
void printPlayerInfo(const Player &player)
{
    cout << "Player      : " << player.getIndex() << endl;
    cout << "Color Index : " << player.getCurrentColorIndex() << endl;
    cout << "Moves Count : " << player.getMovesCount() << endl;
    cout << "Is AI       : " << player.isAIPlayer() << endl;
    cout << "Owned Coords: " << player.getOwnedCoords().size() << endl;
}

