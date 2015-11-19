#include "./include/ColorGridCore.h"
#include <iostream>
#include <iterator>

USING_NS_COLORGRIDCORE;
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
                  std::ostream_iterator<Coord>(std::cout, ", "));
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
