main: main.o ai.o air.o baseobj.o bike.o car.o character.o entity.o land.o npc.o otherplayer.o particle.o player.o train.o vehicle.o water.o
	g++ main.o ai.o air.o baseobj.o bike.o car.o character.o entity.o land.o npc.o otherplayer.o particle.o player.o train.o vehicle.o water.o -o exec

main.o: main.cpp
	g++ -c main.cpp

ai.o: ai.cpp ai.h
	g++ -c ai.cpp

air.o: air.cpp air.h
	g++ -c air.cpp

baseobj.o: baseobj.cpp baseobj.h
	g++ -c baseobj.cpp

bike.o: bike.cpp bike.h
	g++ -c bike.cpp

car.o: car.cpp car.h
	g++ -c car.cpp

character.o: character.cpp character.h
	g++ -c character.cpp

entity.o: entity.cpp entity.h
	g++ -c entity.cpp

land.o: land.cpp land.h
	g++ -c land.cpp

npc.o: npc.cpp npc.h
	g++ -c npc.cpp

otherplayer.o: otherplayer.cpp otherplayer.h
	g++ -c otherplayer.cpp

particle.o: particle.cpp particle.h
	g++ -c particle.cpp

player.o: player.cpp player.h
	g++ -c player.cpp

train.o: train.cpp train.h
	g++ -c train.cpp

vehicle.o: vehicle.cpp vehicle.h
	g++ -c vehicle.cpp

water.o: water.cpp water.h
	g++ -c water.cpp

clean: 
	-rm *.o