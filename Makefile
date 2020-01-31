GCC					= g++
INPUT				= src/main.cpp src/game.cpp src/controller.cpp src/gameplay.cpp src/world.cpp src/entity.cpp src/player.cpp src/userinterface.cpp src/zombie.cpp src/weapon.cpp src/bullet.cpp src/collider.cpp
OUTPUT				= apocalypse.o
INCLUDES			= -I""
LIBRARIES			=
DEPENDENCIES		= -lSDL2main -lSDL2 -pthread

all $(INPUT):
	$(GCC) -Wall -std=c++17 -fpermissive $(INPUT) -o $(OUTPUT) $(INCLUDES) $(LIBRARIES) $(DEPENDENCIES)
	./$(OUTPUT)