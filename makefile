#compiler setting
CC = g++
CXXFLAGS = -Wall -g

#targets
main: main.o Character.o Player.o Enemy.o PlayerClassAssassin.o PlayerClassTank.o PlayerClassWarrior.o Menu.o Area.o Nodes.o
	$(CC) $(CXXFLAGS) -o main.exe main.o Character.o Player.o Enemy.o PlayerClassAssassin.o PlayerClassTank.o PlayerClassWarrior.o Menu.o Area.o Nodes.o

main.o: main.cpp Character.h Player.h Enemy.h PlayerClassAssassin.h PlayerClassTank.h PlayerClassWarrior.h Menu.h Area.h Nodes.h
	$(CC) $(CXXFLAGS) -c main.cpp

Character.o: Character.h Character.cpp
	$(CC) $(CXXFLAGS) -c Character.cpp

Player.o: Player.h Player.cpp Character.h Enemy.h
	$(CC) $(CXXFLAGS) -c Player.cpp

Enemy.o: Enemy.h Enemy.cpp Character.h Player.h
	$(CC) $(CXXFLAGS) -c Enemy.cpp

PlayerClassAssassin.o: PlayerClassAssassin.h PlayerClassAssassin.cpp Player.h Character.h Enemy.h
	$(CC) $(CXXFLAGS) -c PlayerClassAssassin.cpp

PlayerClassTank.o: PlayerClassTank.h PlayerClassTank.cpp Player.h Character.h Enemy.h 
	$(CC) $(CXXFLAGS) -c PlayerClassTank.cpp

PlayerClassWarrior.o: PlayerClassWarrior.h PlayerClassWarrior.cpp Player.h Character.h Enemy.h
	$(CC) $(CXXFLAGS) -c PlayerClassWarrior.cpp 

Menu.o: Menu.h Menu.cpp PlayerClassAssassin.h PlayerClassTank.h PlayerClassWarrior.h Enemy.h Player.h Character.h
	$(CC) $(CXXFLAGS) -c Menu.cpp

Area.o: Area.h Area.cpp Player.h Nodes.h Menu.h
	$(CC) $(CXXFLAGS) -c Area.cpp

Nodes.o: Nodes.h Nodes.cpp Enemy.h Player.h Menu.h
	$(CC) $(CXXFLAGS) -c Nodes.cpp

clean:
	del -f *.o