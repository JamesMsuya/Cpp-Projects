all: main

main: CPU.o CPUprogam.o main.o Memory.o Computer.o 
	g++ CPU.o CPUprogam.o Memory.o Computer.o main.o -o exe 

Memory.o: Memory.cpp
	g++ -c Memory.cpp

Computer.o: Computer.cpp
	g++ -c Computer.cpp

CPU.o: CPU.cpp
	g++ -c CPU.cpp


CPUprogam.o: CPUprogam.cpp
	g++ -c CPUprogam.cpp

main.o: main.cpp
	g++ -c main.cpp

run1 :
	./exe cpu2.txt 0	

run2 :
	./exe cpu2.txt 1

run3 :
	./exe cpu2.txt 2

run4 :
	./exe cpu2.txt sasa.txt 0

run5 :
	./exe cpu3.txt 0

clean:
	rm *.o exe
