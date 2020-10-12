#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int linesTotal = 0;
int wordsTotal = 1;
int charsTotal = 1;

void leerArchivo(char *file) 
{ 
	FILE *file1  = fopen(file, "r"); 
	char line[500];
	char letra;
	linesTotal=0;
	wordsTotal=1;
	charsTotal=1;
	if (file1 == NULL) 
	{
	  printf("Error! Could not open file\n"); 
	  exit(1);
	}
	letra = getc(file1);
	while(letra != EOF) {
		printf("%c", letra);
			if (letra == '\n'){
				linesTotal += 1;
			}
			else if (letra == ' '){
				wordsTotal += 1;
			}
			else
				charsTotal++;

			letra = getc(file1);
		}
	fclose(file1);
	printf("\n");
}

void deleteLinea(char *file, int idLinea){
	FILE *file1 = fopen(file, "r");
	
	char line[500];
	char letra;
	linesTotal=0;
	if (file1 == NULL) 
	{
	  exit(1);
	}

	FILE *file2 = fopen("tempFile.txt", "w"); 
	if (file2 == NULL) 
	{
	  exit(1);
	}

	letra = getc(file1);
	while(letra != EOF) {
		// printf("%c", letra);
			if (letra=='\n')
				linesTotal++;
			if (linesTotal != idLinea - 1)
			{
				fprintf(file2, "%c", letra);
			}
			letra = getc(file1);
		}

	fclose(file1);
	fclose(file2);
	remove(file);
	rename("tempFile.txt", file);
	leerArchivo(file);
	printf("Se ha borrado linea %d\n\n", idLinea);
}

void mergeArchivo(char *fileFirst, char *fileSecond){
	FILE *file1 = fopen(fileFirst, "r");
	FILE *file2 = fopen(fileSecond, "r");
	char line[500];
	char letra;
	linesTotal=0;
	if (file1 == NULL) 
	{
	  exit(1);
	}

	FILE *fileTemp = fopen("archivo3.txt", "w"); 
	if (fileTemp == NULL) 
	{
	  exit(1);
	}
	//Primer archivo
	letra = getc(file1);
	while(letra != EOF) {
			if (letra=='\n')
				linesTotal++;
			
			fprintf(fileTemp, "%c", letra);
			letra = getc(file1);
	}
	linesTotal=0;

	//Segundo archivo
	letra = getc(file2);
	while(letra != EOF) {
			if (letra=='\n')
				linesTotal++;
			
			fprintf(fileTemp, "%c", letra);
			letra = getc(file2);
	}

	fclose(file1);
	fclose(file2);
	fclose(fileTemp);
	
	leerArchivo("archivo3.txt");

	printf("Se han combinado los archivos en archivo3.txt\n\n");
	printf("Regresando al archivo principal\n\n");
	leerArchivo(fileFirst);
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