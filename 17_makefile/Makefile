calc: suma.o calculadora.o
	g++ suma.o calculadora.o -o calc

suma -o: suma.cpp suma.h
	g++ -c suma.cpp

calculadora.o: calculadora.cpp suma.h
	g++ -c calculadora.cpp
