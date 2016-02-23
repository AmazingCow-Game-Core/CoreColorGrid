//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        termcolor.h                               //
//            █ █        █ █        termcolor_cpp                             //
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

#ifndef __AmazingCow_TermColor_Cpp_termcolor_h__
#define __AmazingCow_TermColor_Cpp_termcolor_h__

//std
#include <ostream>
#include <sstream>
#include <string>
#include <vector>

// Namespace Stuff //
#define NS_TERMCOLOR_BEGIN namespace termcolor {
#define NS_TERMCOLOR_END   }
#define USING_NS_TERMCOLOR using namespace termcolor

//The core version number.
#define COW_TERMCOLOR_VERSION_MAJOR    "0"
#define COW_TERMCOLOR_VERSION_MINOR    "1"
#define COW_TERMCOLOR_VERSION_REVISION "1"

#define COW_TERMCOLOR_VERSION "0.1.1"

NS_TERMCOLOR_BEGIN

////////////////////////////////////////////////////////////////////////////////
// Constants                                                                  //
////////////////////////////////////////////////////////////////////////////////
constexpr int NONE = 0;

// Foreground Colors //
constexpr int GREY    = 30;
constexpr int RED     = 31;
constexpr int GREEN   = 32;
constexpr int YELLOW  = 33;
constexpr int BLUE    = 34;
constexpr int MAGENTA = 35;
constexpr int CYAN    = 36;
constexpr int WHITE   = 37;

// Background Colors //
constexpr int ON_GREY    = 40;
constexpr int ON_RED     = 41;
constexpr int ON_GREEN   = 42;
constexpr int ON_YELLOW  = 43;
constexpr int ON_BLUE    = 44;
constexpr int ON_MAGENTA = 45;
constexpr int ON_CYAN    = 46;
constexpr int ON_WHITE   = 47;

// Attributes //
constexpr int BLINK     = 5;
constexpr int BOLD      = 1;
constexpr int CONCEALED = 8;
constexpr int DARK      = 2;
constexpr int REVERSE   = 7;
constexpr int UNDERLINE = 4;


////////////////////////////////////////////////////////////////////////////////
// Stream Functions                                                           //
////////////////////////////////////////////////////////////////////////////////
// Foreground Colors //
std::ostream& grey   (std::ostream &os);
std::ostream& red    (std::ostream &os);
std::ostream& green  (std::ostream &os);
std::ostream& yellow (std::ostream &os);
std::ostream& blue   (std::ostream &os);
std::ostream& magenta(std::ostream &os);
std::ostream& cyan   (std::ostream &os);
std::ostream& white  (std::ostream &os);

// Background Colors //
std::ostream& on_grey   (std::ostream &os);
std::ostream& on_red    (std::ostream &os);
std::ostream& on_green  (std::ostream &os);
std::ostream& on_yellow (std::ostream &os);
std::ostream& on_blue   (std::ostream &os);
std::ostream& on_magenta(std::ostream &os);
std::ostream& on_cyan   (std::ostream &os);
std::ostream& on_white  (std::ostream &os);

// Attributes //
std::ostream& blink    (std::ostream &os);
std::ostream& bold     (std::ostream &os);
std::ostream& concealed(std::ostream &os);
std::ostream& dark     (std::ostream &os);
std::ostream& reverse  (std::ostream &os);
std::ostream& underline(std::ostream &os);

std::ostream& reset(std::ostream &os);



////////////////////////////////////////////////////////////////////////////////
// Colored Function                                                           //
////////////////////////////////////////////////////////////////////////////////
std::string colored(const std::string &str,
                    int foreground,
                    int background = termcolor::NONE,
                    const std::vector<int> &attributes = std::vector<int>());



////////////////////////////////////////////////////////////////////////////////
// Functor Class                                                              //
////////////////////////////////////////////////////////////////////////////////
class options
{
public:
    options(int foreground,
            int background = termcolor::NONE,
            const std::vector<int> &attributes = std::vector<int>()) :
        m_foreground(foreground),
        m_background(background),
        m_attributes(attributes)
    {
        //Empty...
    }

    std::string operator ()(const std::string &str)
    {
        return termcolor::colored(str, m_foreground, m_background, m_attributes);
    }

private:
    int              m_foreground;
    int              m_background;
    std::vector<int> m_attributes;
};

NS_TERMCOLOR_END

#endif /* defined(__AmazingCow_TermColor_Cpp_termcolor_h__) */
