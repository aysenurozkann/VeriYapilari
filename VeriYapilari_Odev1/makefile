All: compile run

compile:
	g++ -I ./include -o ./lib/Yigit.o -c ./src/Yigit.cpp
	g++ -I ./include -o ./lib/AvlTreeList.o -c ./src/AvlTreeList.cpp
	g++ -I ./include -o ./lib/AvlTree.o -c ./src/AvlTree.cpp
	g++ -I ./include -o ./lib/main.o -c ./src/main.cpp
	g++ -I ./include/ -o ./bin/main ./lib/Yigit.o ./lib/AvlTreeList.o ./lib/AvlTree.o ./lib/main.o
	
run:
	cls
	./bin/Main