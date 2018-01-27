#populate
mkdir -p lib
mkdir -p obj
mkdir -p bin/deb
mkdir -p bin/rel


# Debug-<deb, Release->rel
conf=deb
g++ -c src/main.cc -Iinc/ -o obj/main.o -std=c++11
g++ -c src/coin.cc -Iinc/ -o obj/coin.o -std=c++11

g++ obj/main.o obj/coin.o -o bin/$conf/proc -lsfml-graphics -lsfml-window -lsfml-system -Llib/ -lBox2D -std=c++11
