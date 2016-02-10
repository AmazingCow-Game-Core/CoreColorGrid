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
//CoreColorGrid
#include "CoreColorGrid.h"

USING_NS_CORECOLORGRID;
using namespace std;

int main()
{
//     // int boardWidth, int boardHeight,
//     //          int colorsCount,
//     //          PlayersCount playerCount,
//     //          AIPlayersCount aiPlayersCount,
//     //          int maxMoves,
//     //          int seed = kRandomSeed);
//     GameCore core(5,5,
//                   5,
//                   GameCore::PlayersCount::One,
//                   GameCore::AIPlayersCount::Zero,
//                   10,
//                   8);

    GameCore::Options options;

    //Board
    options.boardWidth  = 7;
    options.boardHeight = 7;
    options.colorsCount = 7;

    //Players.
    options.player1 = GameCore::Options::PlayerType::Human;
    options.player2 = GameCore::Options::PlayerType::None;
    options.player3 = GameCore::Options::PlayerType::None;
    options.player4 = GameCore::Options::PlayerType::None;

    options.startPlayerIndex = 0;

    //AI.
    options.aiStrength = 5;

    //Other.
    options.maxMoves = GameCore::kUnlimitedMoves;
    options.seed     = 3;//GameCore::kRandomSeed;

    GameCore core(options);

    while(1)
    {
        cout << core.ascii() << endl;
        auto &player = core.getCurrentPlayer();
        // cout << player << endl;

        int a;
        if(!player.isAIPlayer())
//            a = 0;
            cin >> a;
        else
            a = static_cast<AIPlayer &>(player).decideColor();

        auto &c = player.getOwnedCoords();
        auto ac = core.getAffectedCoords(c, a);

        cout << "Affected coords for " << a << endl;
        std::copy(ac.begin(),
                  ac.end(),
                  std::ostream_iterator<CoreCoord::Coord>(std::cout, ", "));
        cout << endl;

        // core.changeColor(a);

    }
    //    cout << core.ascii() << endl;
    //    cout << player << endl;
    //
    //    core.changeColor(2);
    //
    //    cout << core.ascii() << endl;
    //    cout << player << endl;

}
