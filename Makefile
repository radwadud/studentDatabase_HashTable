all: rbw0049

rbw0049: main.o hashTest.o
		g++ main.o hashTest.o -o rbw0049
		
main.o: main.cpp
		g++ -c main.cpp

hashTest.o: hashTest.cpp
		g++ -c hashTest.cpp

clean:
		rm -rf *o rbw0049
