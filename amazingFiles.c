#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int linesTotal = 0;
int wordsTotal = 1;
int charsTotal = 1;

void leerArchivo(char *file) 
{ 
	FILE *in_file  = fopen(file, "r"); 
	char line[500];
	char letra;
	linesTotal=0;
	wordsTotal=1;
	charsTotal=1;
	if (in_file == NULL) 
	{
	  printf("Error! Could not open file\n"); 
	  exit(1);
	}
	letra = getc(in_file);
	while(letra != EOF) {
		// printf("%c", letra);
			if (letra == '\n'){
				linesTotal += 1;
			}
			else if (letra == ' '){
				wordsTotal += 1;
			}
			else
				charsTotal++;

			letra = getc(in_file);
		}

	fclose(in_file);
}

void deleteLinea(char *file, int idLinea){
	printf("Se ha borrado linea %d\n\n", idLinea);
}

void mergeArchivo(char *file1, char *file2){
	printf("Se han combinado los archivos en archivo3.txt\n\n");
}

int getLinesTotal(){
	return linesTotal;
}

int getWordsTotal(){
	return wordsTotal;
}

int getCharsTotal(){
	return charsTotal;
}