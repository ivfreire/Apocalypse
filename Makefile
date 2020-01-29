GCC					= g++
INPUT				= src/main.cpp src/game.cpp src/entity.cpp src/userinterface.cpp src/player.cpp src/gameplay.cpp src/world.cpp src/zombie.cpp src/bullet.cpp src/weapon.cpp src/collider.cpp
OUTPUT				= apocalypse.o
INCLUDES			= -I""
LIBRARIES			=
DEPENDENCIES		= -lSDL2main -lSDL2 -pthread

all $(INPUT):
	$(GCC) -Wall -std=c++17 -fpermissive $(INPUT) -o $(OUTPUT) $(INCLUDES) $(LIBRARIES) $(DEPENDENCIES)
	./$(OUTPUT)