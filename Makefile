GCC					= g++
INPUT				= src/main.cpp src/game.cpp src/controller.cpp src/gameplay.cpp src/world.cpp src/entity.cpp src/player.cpp src/userinterface.cpp src/zombie.cpp src/weapon.cpp src/bullet.cpp src/collider.cpp src/camera.cpp src/gui.cpp src/screen.cpp src/graph.cpp src/text.cpp src/map.cpp src/tileset.cpp src/panel.cpp tinyxml2/tinyxml2.cpp
OUTPUT				= apocalypse.o
INCLUDES			= -I"./tinyxml2"
LIBRARIES			=
DEPENDENCIES		= -lSDL2main -lSDL2 -lSDL2_ttf -lSDL2_image -pthread

all $(INPUT):
	$(GCC) -Wall -std=c++17 -fpermissive $(INPUT) -o $(OUTPUT) $(INCLUDES) $(LIBRARIES) $(DEPENDENCIES)
	./$(OUTPUT)