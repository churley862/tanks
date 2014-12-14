
bin/tank: build/main.o build/world.o build/tank.o
	c++ `pkg-config sdl2 --libs` build/main.o build/world.o build/tank.o -o bin/tank

build/main.o: main.cpp world.hpp tank.hpp
	c++ -c --std=c++11 `pkg-config sdl2 --cflags` main.cpp -o build/main.o

build/world.o: world.cpp world.hpp
	c++ -c --std=c++11 `pkg-config sdl2 --cflags` world.cpp -o build/world.o

build/tank.o: tank.cpp tank.hpp world.hpp
	c++ -c --std=c++11 `pkg-config sdl2 --cflags` tank.cpp -o build/tank.o

clean:
	rm bin/tank
	rm build/*.o

