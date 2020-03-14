OBJS = Pong.cpp PaddleEntity.cpp InputHandler.cpp
CC = g++
HEADERS = -IBall.hpp -IPaddleEntity.hpp -IInputHandler.hpp -ILogger.hpp -IIInputHandler.hpp
INCLUDE_PATHS = -IC:\MinGW\include\SDL2
LIBRARY_PATHS = -LC:\MinGW\lib
COMPILER_FLAGS = -g -w -Wall
LINKER_FLAGS = -lmingw32 -lSDL2main -lSDL2
OBJ_NAME = Pong.exe
STD_VERSION = --std=c++14

all : $(OBJS)
	$(CC) $(OBJS) $(HEADERS) $(INCLUDE_PATHS) $(LIBRARY_PATHS) $(STD_VERSION) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

#the tab here is very important
#g++ Pong.cpp -IC:\MinGW\include\SDL2 -LC:\MinGW\lib -g -w -Wl -subsystem windows -lmingw32 -lSDL2main -lSDL2 -o Pong.exe