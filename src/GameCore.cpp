//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        GameCore.cpp                              //
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

//Header
#include "../include/GameCore.h"
//std
#include <sstream>
#include <algorithm>
//ColorGridCore
#include "../include/AIPlayer.h"

//Usings.
USING_NS_COLORGRIDCORE;
using namespace std;

// Constants //
const int GameCore::kUnlimitedMoves = -1;
const int GameCore::kRandomSeed     = -1;

// CTOR/DTOR //
GameCore::GameCore(const Options &options):
    m_options(options),
    m_currentPlayerIndex(options.startPlayerIndex)
    //m_board   - Initialized in GameCore::initBoard.
    //m_players - Initialized in GameCore::initPlayers.
{
    initRandomGenerator();
    initBoard();
    initPlayers();
}

// Public Methods //
Coord::CoordVec GameCore::changeColor(int colorIndex)
{
    //COWTODO: Refactor this method - It has too much in common with GameCore::getAffectedCoords.
    Coord::CoordVec changedCoords;

    auto &player = getCurrentPlayer();

    //Already in this color, don't do anything else.
    if(player.getCurrentColorIndex() == colorIndex)
        return changedCoords;

    //Add the Player's current coords.
    changedCoords = player.getOwnedCoords();

    for(int i = 0; i < changedCoords.size(); ++i)
    {
        auto ownedCoord = changedCoords[i];

        for(auto &orthogonalCoord : ownedCoord.getOrthogonal())
        {
            //Coord if out of Board bounds.
            if(!isValidCoord(orthogonalCoord))
                continue;


            //Coord is already processed.
            auto it = std::find(begin(changedCoords),
                                end  (changedCoords),
                                orthogonalCoord);

            if(it != end(changedCoords))
                continue;

            const auto &color = getColorAt(orthogonalCoord);

            //Coord's color isn't the same of target color.
            if(color.getColorIndex() != colorIndex)
                continue;

            //Color is already owned by other player.
            if(color.getOwnerIndex() != Color::kInvalidOwner &&
               color.getOwnerIndex() != player.getIndex())
                continue;

            //Update the changed coords.
            changedCoords.push_back(orthogonalCoord);
        }
    }

    //Add the changed coords to player.
    for(auto &coord : changedCoords)
        player.addOwnedCoord(coord);

    //Make sure that all player's colors is the same.
    for(auto &coord : player.getOwnedCoords())
    {
        auto &color = getColorAt(coord);
        color.changeColorIndex(colorIndex, player.getIndex());
    }

    //Update Player's state
    player.setCurrentColorIndex(colorIndex);
    player.incrementMovesCount();

    //Update the game state.
    checkStatus();
    turnCurrentPlayer();

    return changedCoords;
}

const Color::Board& GameCore::getBoard() const
{
    return m_board;
}
const Color& GameCore::getColorAt(const Coord & coord) const
{
    return m_board[coord.y][coord.x];
}

Player& GameCore::getCurrentPlayer()
{
    return *m_players[m_currentPlayerIndex];
}


int GameCore::getSeed() const
{
    return m_options.seed;
}


bool GameCore::isValidCoord(const Coord &coord) const
{
    return (coord.y >= 0 && coord.y < static_cast<int>(m_board.size()))
        && (coord.x >= 0 && coord.x < static_cast<int>(m_board[coord.y].size()));
}
std::string GameCore::ascii() const
{
    std::stringstream ss;
    for(const auto &line : m_board)
    {
        for(const auto &color : line)
        {
            auto index = color.getColorIndex();
            ss << index;
        }
        ss << std::endl;
    }

    return ss.str();
}

Coord::CoordVec GameCore::getAffectedCoords(const Coord::CoordVec &coords,
                                            int colorIndex) const
{
    //COWTODO: Refactor this method - It has too much in common with GameCore::changeColor.

    //Add the Player's current coords.
    Coord::CoordVec changedCoords = coords;

    for(int i = 0; i < changedCoords.size(); ++i)
    {
        auto ownedCoord = changedCoords[i];

        for(auto &orthogonalCoord : ownedCoord.getOrthogonal())
        {
            //Coord if out of Board bounds.
            if(!isValidCoord(orthogonalCoord))
                continue;

            //Coord is already processed.
            auto it = std::find(begin(changedCoords),
                                end  (changedCoords),
                                orthogonalCoord);

            if(it != end(changedCoords))
                continue;

            const auto &color = getColorAt(orthogonalCoord);

            //Coord's color isn't the same of target color.
            if(color.getColorIndex() != colorIndex)
                continue;

            //Color is already owned by other player.
            if(color.getOwnerIndex() != Color::kInvalidOwner)
                continue;

            //Update the changed coords.
            changedCoords.push_back(orthogonalCoord);
        }
    }

    return changedCoords;
}

// Private Methods //
//Init.
void GameCore::initRandomGenerator()
{
    if(m_options.seed == GameCore::kRandomSeed)
        m_options.seed = static_cast<int>(time(nullptr));

    srand(m_options.seed);
}
void GameCore::initBoard()
{
    m_board.reserve(m_options.boardHeight);

    //Initialize all Board colors.
    for(int i = 0; i < m_options.boardHeight; ++i)
    {
        m_board.push_back(std::vector<Color>());
        m_board[i].reserve(m_options.boardWidth);

        for(int j = 0; j < m_options.boardWidth; ++j)
        {
            //Randomize a color.
            int colorIndex = rand() % m_options.colorsCount;
            m_board[i].push_back(Color(colorIndex));
        }
    }
}
void GameCore::initPlayers()
{
    if(m_options.player1 == Options::PlayerType::None)
        m_options.player1 = Options::PlayerType::AI;

    createPlayerHelper(0, m_options.player1);
    createPlayerHelper(1, m_options.player2);
    createPlayerHelper(2, m_options.player3);
    createPlayerHelper(3, m_options.player4);
}


//Helpers.
Color& GameCore::getColorAt(const Coord &coord)
{
    return m_board[coord.y][coord.x];
}

void GameCore::turnCurrentPlayer()
{
    m_currentPlayerIndex = (m_currentPlayerIndex + 1) % m_players.size();
}
void GameCore::checkStatus()
{

}

void GameCore::createPlayerHelper(int playerIndex,
                                  Options::PlayerType playerType)
{

    //Not need create the player.
    if(playerType == Options::PlayerType::None)
        return;

    auto sidesVec = std::vector<Coord> {
            //Player1 - Left Top Side
            Coord(0, 0),
            //Player2 - Right Bottom Side.
            Coord(m_options.boardHeight - 1, m_options.boardWidth  - 1),
            //Player3 - Right Top Side.
            Coord(0, m_options.boardWidth -1),
            //Player4 - Left Bottm Side.
            Coord(m_options.boardHeight -1, 0)
        };

    //Create the player based in it's type.
    std::shared_ptr<Player> player;
    if(playerType == Options::PlayerType::Human)
        player.reset(new Player(playerIndex));
    else
        player.reset(new AIPlayer(playerIndex, m_options.aiStrength));


    auto &color = getColorAt(sidesVec[playerIndex]);

    //Set the color to player.
    color.changeColorIndex(color.getColorIndex(), playerIndex);

    //Set the Player start color.
    player->setCurrentColorIndex(color.getColorIndex());

    //Add the Color to player.
    player->addOwnedCoord(sidesVec[playerIndex]);

    //Add player.
    m_players.push_back(player);
}
