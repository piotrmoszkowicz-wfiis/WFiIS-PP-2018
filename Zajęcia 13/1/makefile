drzewo.exe: drzewo_main.o drzewoBST.o
	gcc -o drzewo.exe drzewoBST.o drzewo_main.o -Wall
drzewoBST.o: drzewoBST.c drzewoBST.h
	gcc -c drzewoBST.c -Wall
drzewo_main.o: drzewo_main.c drzewoBST.h
	gcc -c drzewo_main.c -Wall