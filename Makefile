program4.out: program4_driver.o adventurer.o utils.o
	g++ -g -std=c++17 program4_driver.o adventurer.o utils.o -o program4.out

utils.o: utils.cpp adventurer.h
	g++ -g -std=c++17 -c utils.cpp

adventurer.o: adventurer.cpp adventurer.h
	g++ -g -std=c++17 -c adventurer.cpp

program4.o: program4_driver.cpp adventurer.h
	g++ -g -std=c++17 -c program4_driver.cpp

run:
	./program4.out

valrun:
	valgrind ./program4.out

clean:
	rm *.o
