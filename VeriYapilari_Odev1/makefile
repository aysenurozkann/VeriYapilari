All: compile run

compile:
	g++ -I ./include -o ./lib/Basamak.o -c ./src/Basamak.cpp
	g++ -I ./include -o ./lib/Sayi.o -c ./src/Sayi.cpp
	g++ -I ./include -o ./lib/SayilarListesi.o -c ./src/SayilarListesi.cpp
	g++ -I ./include -o ./lib/Dugum.o -c ./src/Dugum.cpp
	g++ -I ./include -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./bin/main ./lib/Basamak.o ./lib/Sayi.o ./lib/SayilarListesi.o ./lib/Dugum.o ./lib/main.o
	
run:
	cls
	./bin/Main