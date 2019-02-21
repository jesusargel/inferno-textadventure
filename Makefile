all: Inferno

main.o: main.cpp parser.h room.h gamemap.h player.h monster.h weapon.h
	g++ -Wall -g -c main.cpp

parser.o: parser.cpp parser.h
	g++ -Wall -g -c parser.cpp

thing.o: thing.cpp thing.h
	g++ -Wall -g -c thing.cpp

container.o: container.cpp container.h thing.h
	g++ -Wall -g -c container.cpp

lifeform.o: lifeform.h container.h gamemap.h
	g++ -Wall -g -c lifeform.cpp

room.o: room.h container.h
	g++ -Wall -g -c room.cpp

weapon.o: weapon.h thing.h
	g++ -Wall -g -c weapon.cpp

Inferno: main.o parser.o thing.o container.o room.o lifeform.o weapon.o
	g++ -Wall -g -o Inferno main.o parser.o thing.o container.o room.o lifeform.o weapon.o

.PHONY: clean
clean:
	rm -f *.o Inferno

