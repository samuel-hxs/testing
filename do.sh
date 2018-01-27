#populate
mkdir -p lib
mkdir -p obj
mkdir -p bin/deb
mkdir -p bin/rel


# Debug-<deb, Release->rel
conf=deb
g++ -c src/main.cc -o obj/main.o
g++ obj/main.o -o bin/$conf/proc -lsfml-graphics -lsfml-window -lsfml-system -Llib/ -lBox2D
