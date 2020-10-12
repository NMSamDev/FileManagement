#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "amazingFiles.h"

int main(){
	char *archivo1;
	char *archivo2;
	printf("Inserte nombre de archivo: \n");
	// scanf(" %s", archivo1);
	// leerArchivo(archivo1);
	leerArchivo("archivo1.txt");
	char menu_option = '0';

	while(menu_option != '5'){
		printf("1- Number of lines.\n");
		printf("2- Number of words and characters.\n");
		printf("3- Delete a specific line from a file.\n");
		printf("4- Merge two files in a new file.\n");
		printf("5- Exit.\n");
		printf("Please choose an option: \n");

		scanf(" %c", &menu_option);
		getchar();

		switch(menu_option){
			case '1':
				printf("Number of lines: %d\n\n", getLinesTotal());
				break;
			case '2':
				printf("Number of words: %d\n", getWordsTotal());
				printf("Number of characters: %d \n\n", getCharsTotal());
				break;
			case '3':
				//backtrackingMaze(matrix);
				break;
			case '4':
				//backtrackingMaze(matrix);
				break;
			case '5': 
				exit(1);
				break;
			default: printf("Not a valid option.\n");
		}
	}
	
	return 0;
}