//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.h                                //
//             ████████████         ColorGrid Core                            //
//           █              █       Copyright (c) 2015 AmazingCow             //
//          █     █    █     █      www.AmazingCow.com                        //
//          █     █    █     █                                                //
//           █              █       N2OMatt - n2omatt@amazingcow.com          //
//             ████████████         www.amazingcow.com/n2omatt                //
//                                                                            //
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
//        The email is: acknowledgmentopensource@AmazingCow.com               //
//     3. Altered source versions must be plainly marked as such,             //
//        and must notbe misrepresented as being the original software.       //
//     4. This notice may not be removed or altered from any source           //
//        distribution.                                                       //
//     5. Most important, you must have fun. ;)                               //
//                                                                            //
//      Visit opensource.amazingcow.com for more open-source projects.        //
//                                                                            //
//                                  Enjoy :)                                  //
//----------------------------------------------------------------------------//

#ifndef __ColorGridCore_include_GameCore_h__
#define __ColorGridCore_include_GameCore_h__

//COWTODO: Add doxygen comments.
//COWTODO: Change the type of Player pointers to std::unique_ptr.

//std
#include <string>
#include <memory>
//ColorGridCore.
#include "ColorGridCore_Utils.h"
#include "Status.h"
#include "Color.h"
#include "Coord.h"
#include "Player.h"

NS_COLORGRIDCORE_BEGIN

class GameCore
{
    // Constants / Enums / Typdefs //
public:
    static const int kUnlimitedMoves;
    static const int kRandomSeed;

    struct Options
    {
        enum class PlayerType { Human, AI, None };

        //Board
        int boardWidth;
        int boardHeight;
        int colorsCount;

        //Players.
        PlayerType player1 = PlayerType::Human;
        PlayerType player2 = PlayerType::None;
        PlayerType player3 = PlayerType::None;
        PlayerType player4 = PlayerType::None;

        int startPlayerIndex = 0; //Range [0, 3];

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
    Coord::CoordVec changeColor(int colorIndex);

    const Color::Board& getBoard() const;
    const Color& getColorAt(const Coord &coord) const;

    Player& getCurrentPlayer();

    int getSeed() const;

    bool isValidCoord(const Coord &coord) const;
    std::string ascii() const;

    Coord::CoordVec getAffectedCoords(const Coord::CoordVec &coords,
                                      int colorIndex) const;

    // Private Methods //
private:
    //Init.
    void initRandomGenerator();
    void initBoard();
    void initPlayers();

    //Helpers.
    Color& getColorAt(const Coord &coord);

    void turnCurrentPlayer();
    void checkStatus();

    void createPlayerHelper(int playerIndex,
                            Options::PlayerType playerType);

    // iVars //
private:
    Options m_options;
    int     m_currentPlayerIndex;

    Color::Board m_board;
    std::vector<std::shared_ptr<Player>> m_players;
};

NS_COLORGRIDCORE_END
#endif // defined(__ColorGridCore_include_GameCore_h__) //
