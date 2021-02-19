#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "csv.h"
#include <limits.h>
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


int fetch_num(char *field, int i , int j ){
	// We take the field string that was inputted and then find the value that was highest
	// Int that will be used to store the highest value 
	int current = *get_index(i,j,field);
	// If there is no numeric data in the indicated field in any of the data records the program exits with error code EXIT_FAILURE.
	if(!isdigit(current)){
		exit(EXIT_FAILURE);
	}
	else{
	//	return atoi(field[i][j]);
		
		return -1;
	}
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
	
	//We are checking each argument and applying it's function on the array file
	// Important: Use the function get_index(i,j,pointer) in order to access the pointer to entry 
	// i(the first param) is the row number, j(the second param) is the column
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
		else if(strcmp("-min",argv[i])==0){
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
		else if(strcmp("-mean",argv[i])==0){
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

		


