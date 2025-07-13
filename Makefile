all:
	g++ main.cpp src/*.cpp -o main -Isrc/include -Lsrc/lib -lSDL3 -lSDL3_image