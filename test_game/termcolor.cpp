//----------------------------------------------------------------------------//
//               █      █                                                     //
//               ████████                                                     //
//             ██        ██                                                   //
//            ███  █  █  ███        termcolor.cpp                             //
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

//Header
#include "termcolor.h"

//Usings
USING_NS_TERMCOLOR;
using namespace std;

// Constants //
constexpr const char *start_escape = "\033[";
constexpr const char *end_escape   = "m";
constexpr const char *reset_str    = "\033[0m";


////////////////////////////////////////////////////////////////////////////////
// Stream Functions                                                           //
////////////////////////////////////////////////////////////////////////////////
// Foreground Colors //
std::ostream& termcolor::grey(std::ostream &os)
{
    os << start_escape << termcolor::GREY << end_escape;
    return os;
}
std::ostream& termcolor::red(std::ostream &os)
{
    os << start_escape << termcolor::RED << end_escape;
    return os;
}
std::ostream& termcolor::green(std::ostream &os)
{
    os << start_escape << termcolor::GREEN << end_escape;
    return os;
}
std::ostream& termcolor::yellow(std::ostream &os)
{
    os << start_escape << termcolor::YELLOW << end_escape;
    return os;
}
std::ostream& termcolor::blue(std::ostream &os)
{
    os << start_escape << termcolor::BLUE << end_escape;
    return os;
}
std::ostream& termcolor::magenta(std::ostream &os)
{
    os << start_escape << termcolor::MAGENTA << end_escape;
    return os;
}
std::ostream& termcolor::cyan(std::ostream &os)
{
    os << start_escape << termcolor::CYAN << end_escape;
    return os;
}
std::ostream& termcolor::white(std::ostream &os)
{
    os << start_escape << termcolor::WHITE << end_escape;
    return os;
}

// Background Colors //
std::ostream& termcolor::on_grey(std::ostream &os)
{
    os << start_escape << termcolor::ON_GREY << end_escape;
    return os;
}
std::ostream& termcolor::on_red(std::ostream &os)
{
    os << start_escape << termcolor::ON_RED << end_escape;
    return os;
}
std::ostream& termcolor::on_green(std::ostream &os)
{
    os << start_escape << termcolor::ON_GREEN << end_escape;
    return os;
}
std::ostream& termcolor::on_yellow(std::ostream &os)
{
    os << start_escape << termcolor::ON_YELLOW << end_escape;
    return os;
}
std::ostream& termcolor::on_blue(std::ostream &os)
{
    os << start_escape << termcolor::ON_BLUE << end_escape;
    return os;
}
std::ostream& termcolor::on_magenta(std::ostream &os)
{
    os << start_escape << termcolor::ON_MAGENTA << end_escape;
    return os;
}
std::ostream& termcolor::on_cyan(std::ostream &os)
{
    os << start_escape << termcolor::ON_CYAN << end_escape;
    return os;
}
std::ostream& termcolor::on_white(std::ostream &os)
{
    os << start_escape << termcolor::ON_WHITE << end_escape;
    return os;
}

// Attributes //
std::ostream& termcolor::blink(std::ostream &os)
{
    os << start_escape << termcolor::BLINK << end_escape;
    return os;
}
std::ostream& termcolor::bold(std::ostream &os)
{
    os << start_escape << termcolor::BOLD << end_escape;
    return os;
}
std::ostream& termcolor::concealed(std::ostream &os)
{
    os << start_escape << termcolor::CONCEALED << end_escape;
    return os;
}
std::ostream& termcolor::dark(std::ostream &os)
{
    os << start_escape << termcolor::DARK << end_escape;
    return os;
}
std::ostream& termcolor::reverse(std::ostream &os)
{
    os << start_escape << termcolor::REVERSE << end_escape;
    return os;
}
std::ostream& termcolor::underline(std::ostream &os)
{
    os << start_escape << termcolor::UNDERLINE << end_escape;
    return os;
}


std::ostream& termcolor::reset(std::ostream &os)
{
    os << reset_str;
    return os;
}



////////////////////////////////////////////////////////////////////////////////
// Colored Function                                                           //
////////////////////////////////////////////////////////////////////////////////
std::string termcolor::colored(const std::string &str,
                               int foreground,
                               int background,
                               const std::vector<int> &attributes)
{
    //COWTODO: Check what is better...
    //COWTODO: 1 - stringstreams - Like we're doing now...
    //COWTODO: 2 - sprintf - We can calculate the array size based in the options.
    //COWTODO: 3 - String concat.

    std::stringstream ss;

    for(auto attribute : attributes)
        if(attribute)
            ss << start_escape << attribute << end_escape;

    if(background) ss << start_escape << background << end_escape;
    if(foreground) ss << start_escape << foreground << end_escape;

    ss << str;

    ss << reset_str;

    return ss.str();
}
