#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
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


int fetch_num(char* field, int i , int j ){
	// We take the field string that was inputted and then find the value that was highest
	// Int that will be used to store the highest value 
	int current = field[i][j] ;
	// If there is no numeric data in the indicated field in any of the data records the program exits with error code EXIT_FAILURE.
	if(!isdigit(current)){
		exit(EXIT_FAILURE);
	}
	else{
		return atoi(field[i][j]);
	}
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
			int highest = INT_MIN ;
			if (i++ < argc-1 ){
			//do function
			for(int j = 0 ; j != EOF ; j++){
				if(fetch_num(file,i,j) > highest){
					highest = fetch_num(file,i,j);
				}
			}
			}
			return highest;
		}
		else if(strcmp("-min",argv[i])){
			int lowest = INT_MAX ;
			if (i++ < argc-1 ){
			//do function
			for(int j = 0 ; j != EOF ; j++){
				if(fetch_num(file,i,j) <  lowest){
					lowest = fetch_num(file,i,j);
				}
			}
			}
			return lowest;
		}
		else if(strcmp("-mean",argv[i])){
			int sum = 0 ;
			int nums = 1 ;
			if (i++ < argc-1 ){
			//do function
			for(int j = 0 ; j != EOF ; j++){
				sum += fetch_num(file,i,j);
				nums ++ ;
				}
			}
			return sum / nums;
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

		


