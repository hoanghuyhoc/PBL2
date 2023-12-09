#compiler setting
CC = g++
CXXFLAGS = -Wall -g

#targets
main: main.o Character.o Player.o Enemy.o PlayerClassAssassin.o PlayerClassTank.o PlayerClassWarrior.o Menu.o
	$(CC) $(CXXFLAGS) -o main.exe main.o Character.o Player.o Enemy.o PlayerClassAssassin.o PlayerClassTank.o PlayerClassWarrior.o Menu.o

main.o: main.cpp Character.h Player.h Enemy.h PlayerClassAssassin.h PlayerClassTank.h PlayerClassWarrior.h Menu.h
	$(CC) $(CXXFLAGS) -c main.cpp

Character.o: Character.h Character.cpp
	$(CC) $(CXXFLAGS) -c Character.cpp

Player.o: Player.h Player.cpp Character.h Character.cpp Enemy.h Enemy.cpp
	$(CC) $(CXXFLAGS) -c Player.cpp Character.cpp Enemy.cpp

Enemy.o: Enemy.h Enemy.cpp Character.h Character.cpp Player.h Player.cpp
	$(CC) $(CXXFLAGS) -c Enemy.cpp Character.cpp Player.cpp

PlayerClassAssassin.o: PlayerClassAssassin.h PlayerClassAssassin.cpp Player.h Player.cpp Character.h Character.cpp Enemy.h Enemy.cpp
	$(CC) $(CXXFLAGS) -c PlayerClassAssassin.cpp Player.cpp Character.cpp Enemy.cpp

PlayerClassTank.o: PlayerClassTank.h PlayerClassTank.cpp Player.h Player.cpp Character.h Character.cpp Enemy.h Enemy.cpp
	$(CC) $(CXXFLAGS) -c PlayerClassTank.cpp Player.cpp Character.cpp Enemy.cpp

PlayerClassWarrior.o: PlayerClassWarrior.h PlayerClassWarrior.cpp Player.h Player.cpp Character.h Character.cpp Enemy.h
	$(CC) $(CXXFLAGS) -c PlayerClassWarrior.cpp Player.cpp Character.cpp Enemy.cpp

Menu.o: Menu.h Menu.cpp PlayerClassAssassin.h PlayerClassAssassin.cpp PlayerClassTank.h PlayerClassTank.cpp PlayerClassWarrior.h PlayerClassWarrior.cpp Enemy.h Enemy.cpp Player.h Player.cpp Character.h Character.cpp
	$(CC) $(CXXFLAGS) -c Menu.cpp PlayerClassAssassin.cpp PlayerClassTank.cpp PlayerClassWarrior.cpp Player.cpp Enemy.cpp Character.cpp

clean:
	del -f *.o