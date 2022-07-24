Target: main
main: main.cpp gate.cpp gate.h
	g++ -std=c++11 main.cpp gate.cpp -o main
		./main