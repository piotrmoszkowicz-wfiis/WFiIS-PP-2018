all:
	gcc -Wall drzewo_main.c -L. -ltree_static -o drzewo.exe
libtree_static.a: drzewoBST.o
	ar rcs libtree_static.a drzewoBST.o
drzewoBST.o: drzewoBST.h
	gcc -c drzewoBST.c -Wall