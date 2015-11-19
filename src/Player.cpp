//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        Player.cpp                                //
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
#include "../include/Player.h"
//std
#include <algorithm>
#include <vector>

//Usings.
USING_NS_COLORGRIDCORE;
using namespace std;


// Friends //
NS_COLORGRIDCORE_BEGIN
std::ostream& operator <<(std::ostream &os, const Player &player)
{
    os << "Player  : " << player.getIndex()              << std::endl;
    os << "  AI    : " << player.isAIPlayer()            << std::endl;
    os << "  Color : " << player.getCurrentColorIndex()  << std::endl;
    os << "  Coords: " << player.getOwnedCoords().size() << std::endl;

    return os;
}
NS_COLORGRIDCORE_END


// CTOR/DTOR //
Player::Player(int index) :
    m_index            (index),
    m_currentColorIndex(-1),
    m_movesCount       (0)
{
    //Empty...
}


// Public Methods //
int Player::getIndex() const
{
    return m_index;
}
int Player::getCurrentColorIndex() const
{
    return m_currentColorIndex;
}
int Player::getMovesCount() const
{
    return m_movesCount;
}

bool Player::isAIPlayer() const
{
    return false;
}

const Coord::CoordVec& Player::getOwnedCoords() const
{
    return m_ownedCoords;
}

// Private Methods //
//These methods are intended to be used only by GameCore class.
void Player::setCurrentColorIndex(int colorIndex)
{
    m_currentColorIndex = colorIndex;
}
void Player::addOwnedCoord(const Coord &coord)
{
    auto it = std::find(begin(m_ownedCoords),
                        end  (m_ownedCoords),
                        coord);

    if(it == end(m_ownedCoords))
        m_ownedCoords.push_back(coord);
}
void Player::incrementMovesCount()
{
    ++m_movesCount;
}
