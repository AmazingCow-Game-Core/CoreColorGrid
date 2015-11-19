//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███                                                  //
//            █ █        █ █        Coord.h                                   //
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

#ifndef __ColorGridCore_include_Coord_h__
#define __ColorGridCore_include_Coord_h__

//COWTODO: Add doxygen comments.
//COWTODO: Remove Coord::getSurroundingCoords
//COWTODO: Rename the Coord::getOrthogonalCoords to Coord::getOrthogonal

//std
#include <ostream>
#include <vector>
//ColorGridCore.
#include "ColorGridCore_Utils.h"

NS_COLORGRIDCORE_BEGIN

class Coord
{
    // Enums / Constants / Typdefs //
public:
    typedef std::vector<Coord> CoordVec;

    // Friends //
public:
    ///@brief Output a string representation in for of (y, x).
    friend std::ostream& operator <<(std::ostream &os, const Coord &coord);

    ///@brief Check if two coords have the same y and x.
    friend bool operator ==(const Coord &lhs, const Coord &rhs);

    ///@brief Check if two coords have the different y and x.
    friend bool operator !=(const Coord &lhs, const Coord &rhs);

    ///@brief Adds the y and x.
    friend Coord operator +(const Coord &lhs, const Coord &rhs);

    // CTOR/DTOR //
public:
    ///@brief Constructs a Coord.
    ///@param y The Y coordinate - Default is 0.
    ///@param x The X coordinate - Default is 0.
    Coord(int y = 0, int x = 0);


    // Public Methods //
public:
    ///@brief Gets a Coord that is top of this coord.
    ///@param offset How many times it will be on top.
    ///@returns A coord that have the y coordinate "offset" times less
    ///than this coord.
    Coord getUp(int offset = 1) const;

    ///@brief Gets a Coord that is bottom of this coord.
    ///@param offset How many times it will be on bottom.
    ///@returns A coord that have the y coordinate "offset" times more
    ///than this coord.
    Coord getDown(int offset = 1) const;

    ///@brief Gets a Coord that is on left of this coord.
    ///@param offset How many times it will be on left.
    ///@returns A coord that have the x coordinate "offset" times less
    ///than this coord.
    Coord getLeft(int offset = 1) const;

    ///@brief Gets a Coord that is on right of this coord.
    ///@param offset How many times it will be on right.
    ///@returns A coord that have the x coordinate "offset" times more
    ///than this coord.
    Coord getRight(int offset = 1) const;

    ///@brief
    ///@returns
    ///@see
    CoordVec getSurrounding() const;
    CoordVec getOrthogonal() const;

    // iVars //
public:
    int y, x;
};


NS_COLORGRIDCORE_END
#endif // defined(__ColorGridCore_include_Coord_h__) //
