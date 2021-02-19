#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#define READFILE "r"

#define C 1000 //column
#define R 100  //row
#define S 100  //string_len

//i is row, j is collomn, k is string pos
static int g_i,g_j,g_k = 0;

char *get_index(int i, int j,char *buff){
	int index= (i*R*S) + (j*R);
	return (buff + index);
}

char *read_csv(char csv_name[]){
	FILE *csv = fopen(csv_name, READFILE ); 

	char *buff = (char*)malloc(C * R * S * sizeof(char));
	char value = ' ';
	while (value != EOF ) {
		value = fgetc(csv);
		if (value == ','){g_j++; g_k=0;}			
		else if ( value == '\n' ) {g_i++; g_j=0;}
		else {
			int index= (g_i*R*S) + (g_j*R) + g_k;
			*(buff + index) = value; 
			g_k++;
		}
	}
	return buff;
}
void headers(char *matrix){
	for (int i = 1;i <= g_i; i++){
		for (int j = 0;j <= g_i; j++){
			*get_index(i-1,j,matrix) = *get_index(i,j,matrix);
		}
	}
}

int main(int argc, char *argv[]){
	char *file = read_csv(argv[argc-1]);
	file = get_index(10,10,file);

	for (int i = 1; i < argc-1; i++ ){
		printf("%s:arg\n",argv[i]);
		if (strcmp("-f",argv[i])==0){
			printf("-f:%s\n",argv[i]);
			//for (int field_j = 0; g_j >= field_j;field_j++){
			//	printf("%s ",get_index(0,field_j,file) );			
			//}	
		}
		else if(strcmp("-r",argv[i])==0){
			printf("%i-r ", g_i);
		} 
		else if(strcmp("-h",argv[i])==0){
			printf("%i :header\n", g_i);
		}
		else if(strcmp("-max",argv[i])==0){
			if (i++ < argc-1 ){
			//do function
			}			
			else {
				exit(EXIT_FAILURE);
			}
		}
		else if(strcmp("-min",argv[i])==0){
			if (i++ < argc-1 ){
			//do function
			}			
			else {
				exit(EXIT_FAILURE);
			}
		}
		else if(strcmp("-mean",argv[i])==0){
			if (i++ < argc-1 ){
			//do function
			}			
			else {
				exit(EXIT_FAILURE);
			}
		}		
		else if(strcmp("-records",argv[i])==0){
			i++;
			if (i++ < argc-1 ){
			//do function
			}			
			else {
				exit(EXIT_FAILURE);
			}
		}
		char *arg = argv[i];
	}  
	return 0;
}

		


