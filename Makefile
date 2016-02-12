all: obj bin

clean:
	rm -rf ./obj
	rm -rf ./bin

obj:
	mkdir -p ./obj
	g++ -std=c++11 -c -I./lib/CoreCoord/include   \
                        ./lib/CoreCoord/src/*.cpp \
                        ./src/*.cpp

	mv *.o ./obj/

bin:
	mkdir -p ./bin
	g++ -std=c++11 -D__AMAZINGCORE_CORECOLORGRID_TEST_ENABLED__ \
                   -I./lib/CoreCoord/include                    \
                   ./src/*.cpp                                  \
                   ./lib/CoreCoord/src/*.cpp                    \
                   ./test_game/main.cpp                         \
                   -o ./bin/testgame

