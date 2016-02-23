//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        CoreColorGrid.h                           //
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

#ifndef __CoreColorGrid_include_GameCore_h__
#define __CoreColorGrid_include_GameCore_h__

//COWTODO: Add doxygen comments.
//COWTODO: Change the type of Player pointers to std::unique_ptr.

//std
#include <string>
#include <memory>
//CoreColorGrid
#include "CoreColorGrid_Utils.h"
#include "Color.h"
#include "Coord.h"
#include "Player.h"

NS_CORECOLORGRID_BEGIN

class GameCore
{
    // Constants / Enums / Typdefs //
public:
    static const int kUnlimitedMoves;
    static const int kRandomSeed;

    struct Options
    {
        //Board
        int boardWidth;
        int boardHeight;
        int colorsCount;

        //Players
        int playersCount      = 1; //Range [1, 3];
        int humanPlayersCount = 1; //Range [1, playersCount];
        int startPlayerIndex  = 0; //Range [0, 3];

        //AI.
        int aiStrength = 5; //Range [0, 10];

        //Other.
        int maxMoves = GameCore::kUnlimitedMoves;
        int seed     = GameCore::kRandomSeed;
    };


    // CTOR/DTOR //
public:
    GameCore(const Options &options);

    // Public Methods //
public:
    //Action
    CoreCoord::Coord::Vec changeColor(int colorIndex);

    //Board
    const Color::Board& getBoard() const;
    const Color& getColorAt(const CoreCoord::Coord &coord) const;

    //Player
    Player* getWinnerPlayer() const;
    Player& getPlayer(int index) const;
    Player& getCurrentPlayer() const;

    int getPlayersCount() const;
    int getHumanPlayersCount() const;

    //AI
    int getAIStrength() const;

    //Helpers
    bool gameIsOver() const;

    int getMaxMoves() const;
    int getSeed() const;

    bool isValidCoord(const CoreCoord::Coord &coord) const;
    CoreCoord::Coord::Vec getAffectedCoords(const CoreCoord::Coord::Vec &coords,
                                            int colorIndex) const;

    std::string ascii() const;


    // Private Methods //
private:
    //Init
    void initRandomGenerator();
    void initBoard();
    void initPlayers();

    //Colors
    Color& getColorAt(const CoreCoord::Coord &coord);

    //Status
    void checkStatus();

    //Player
    void turnCurrentPlayer();
    void createPlayerHelper(int playerIndex,
                            bool isAIPlayer);

    // iVars //
private:
    Options m_options;
    int     m_currentPlayerIndex;

    Color::Board m_board;

    std::vector<std::shared_ptr<Player>> m_players;
    Player *m_pWinnerPlayer;
};

NS_CORECOLORGRID_END
#endif // defined(__CoreColorGrid_include_GameCore_h__) //
