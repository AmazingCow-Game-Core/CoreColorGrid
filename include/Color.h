//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        Color.h                                   //
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


#ifndef __CoreColorGrid_include_Color_h__
#define __CoreColorGrid_include_Color_h__

//COWTODO: Add doxygen comments.

//std
#include <vector>
//CoreColorGrid
#include "CoreColorGrid_Utils.h"
//CoreCoord
#include "CoreCoord.h"

NS_CORECOLORGRID_BEGIN

class Color
{
    // Constants/Enums/Typdefs //
public:
    typedef std::vector<std::vector<Color>> Board;
    static const int kInvalidOwner;

    // CTOR/DTOR //
public:
    Color(int index, int owner = kInvalidOwner);

    // Public Methods //
public:
    void changeColorIndex(int index, int ownerIndex);
    int getColorIndex() const;
    int getOwnerIndex() const;

    // iVars //
private:
    int m_colorIndex;
    int m_ownerIndex;
};

NS_CORECOLORGRID_END
#endif // defined(__CoreColorGrid_include_Color_h__) //
