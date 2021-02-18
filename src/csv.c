#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define READFILE "r"

#define C 1000 //column
#define R 100  //row
#define S 100  //string_len

//i is row, j is collomn, k is string pos
static int i,j,k = 0;

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
		if (value == ','){j++; k=0;}			
		else if ( value == '\n' ) {i++; j=0;}
		else {
			int index= (i*R*S) + (j*R) + k;
			*(buff + index) = value; 
			k++;
		}

	//	printf("i:%i, j:%i, k:%i \n",i,j,k);
	}
	for (int incr=0; incr < i; incr++ ) {
		for (int jincr; jincr < j; jincr++){
		//	printf("%s yo\n",buff[i][j]);
		}
	}
	return buff;
}

int main(int argc, char *argv[]){
	char *file = read_csv(argv[argc-1]);
	file = get_index(10,10,file);
	for (int i = 0; i < argc-1; i++ ){
		if (strcmp("-f",argv[i])){
				
		}
		else if(strcmp("-r",argv[i])){
			
		} 
		else if(strcmp("-h",argv[i])){
			
		}
		else if(strcmp("-max",argv[i])){
			if (i++ < argc-1 ){
			//do function
			}			
			else {
				exit(EXIT_FAILURE);
			}
		}
		else if(strcmp("-min",argv[i])){
			if (i++ < argc-1 ){
			//do function
			}			
			else {
				exit(EXIT_FAILURE);
			}
		}
		else if(strcmp("-mean",argv[i])){
			if (i++ < argc-1 ){
			//do function
			}			
			else {
				exit(EXIT_FAILURE);
			}
		}		
		else if(strcmp("-records",argv[i])){
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

//	FILE *csv = fopen(argv[argc-1], READFILE ); 
//	char buff[800][100][100];
//	char value = fgetc(csv);
//	//i is row, j is collom, k is string pos
//	int i,j,k =0 ;
//	while (value != EOF ) {
//		value = fgetc(csv);
//		printf("%c\n",value);
//		if (value == ','){i++; k=0;}			
//		else if ( value == '\n' ) {j++; i=0;}
//		else buff[i][j][k] = value;
//		k++;
//	}
	return 0;
}

		


