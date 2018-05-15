#include <stdio.h>
#include <stdlib.h>
int main (int argc, char ** argv){
	FILE * pFile;
	long size;

	if (argc<2)
	    exit(1);

	pFile = fopen (argv[1],"rb");

	if (pFile==NULL)
		perror ("Error opening file");
	else {
		fseek (pFile, 0, SEEK_END);
		size=ftell (pFile);
		fclose (pFile);
		printf ("Size of %s: %ld bytes.\n",argv[1],size);
	}
	
	
	}
