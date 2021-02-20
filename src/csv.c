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

static char *file;

static int header_size;

char *get_index(int i, int j){
	int index= (i*R*S) + (j*R);
	return (file + index);
}

	// We take the field string that was inputted and then find the value that was highest
	// Int that will be used to store the highest value 
	int fetch_num(int i , int j ){
	// We take the field string that was inputted and then find the value that was highest
	// Int that will be used to store the highest value 
	char* current = get_index(i,j) ;
	// If there is no numeric data in the indicated field in any of the data records the program exits with error code EXIT_FAILURE.
	if(!isdigit(*current)){
		exit(EXIT_FAILURE);
	}
	else{
	//	return atoi(field[i][j]);
		
		return atoi(current);
	}
}



char *read_csv(char csv_name[]){
	FILE *csv = fopen(csv_name, READFILE ); 

	char *buff = (char*)malloc(C * R * S * sizeof(char));
	char value = ' ';
	while (value != EOF ) {
		value = fgetc(csv);
		if (value == ','){
			int index= (g_i*R*S) + (g_j*R) + g_k + 1;
			//*(buff + index) = '\0';
			g_j++; g_k=0; 
		}			
		else if ( value=='\"' ) {
			char new_value = ' '; 
			while ('\"' != new_value){
				new_value = fgetc(csv);
				int index = (g_i*R*S) + (g_j*R) + g_k;
				*(buff + index) = new_value; 
				g_k++;
			}
		}
		else if ( value == '\n' ) {
			if (g_i == 0) header_size = g_j;
			g_i++; g_j=0;
		}
		else {
			int index= (g_i*R*S) + (g_j*R) + g_k;
			*(buff + index) = value; 
			g_k++;
		}
	}
	return buff;
}
void headers(){
	for (int i = 1;i <= g_i; i++){
		for (int j = 0;j <= header_size; j++){
			*get_index(i-1,j) = *get_index(i,j);
		}
	}
	g_i--;
}

void print_file(){
	for (int i = 0; i < g_i;i++){

		for (int j = 0;j < header_size;j++){

			printf("%s\n",get_index(i,j));	
		}
	}
}
void print_record(int i){
	printf("%s",get_index(i,0));
	for (int j = 1; j < header_size; j++){
		printf(",%s",get_index(i,j));
	}
}
void get_reconds(char *field,char *value){
	for (int j =0; j < header_size;j++){
		//scans the first row for field
		char *header = get_index(0,j);
		if (strcmp(header,field)==0 ){
	//		printf("header:%s,field:%s,value:%s\n",header,field,value);
			printf("%s\n",get_index(1,j));
			for (int i = 1; i<g_i; i++){
//				printf("%s:%i\n",get_index(i,j),i);
				if (strcmp(get_index(i,j),value) == 0){
					print_record(i);	
				}	
			}
		}
	} 
}

int main(int argc, char *argv[]){
	file = read_csv(argv[argc-1]);
//	printf("%s\n",get_index(0,0));
	//We are checking each argument and applying it's function on the array file
	// Important: Use the function get_index(i,j) in order to access the pointer to entry 
	// i(the first param) is the row number, j(the second param) is the column
	for (int i = 1; i < argc-1; i++ ){
		if (strcmp("-f",argv[i])==0){
			printf("%i\n",header_size);
		}
		else if(strcmp("-r",argv[i])==0){
			printf("%i\n", g_i);
		} 
		else if(strcmp("-h",argv[i])==0){
			headers();
		}
		else if(strcmp("-max",argv[i])==0){
			int highest = INT_MIN ;
			if (i++ < argc-1 ){
			//do function
				for(int j = 0 ; j != EOF; j++){
					if(fetch_num(i,j) > highest){
						highest = fetch_num(i,j);
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
					if(fetch_num(i,j) <  lowest){
						lowest = fetch_num(i,j);
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
					sum += fetch_num(i,j);
					nums++ ;
					}
				}
			return sum / nums;
		}		
		else if(strcmp("-records",argv[i])==0){
			int field_index = ++i;
			int record_index = ++i;
			if (field_index < argc-1 && record_index < argc-1 ){
				char *field = argv[field_index];
				char *record = argv[record_index];
				get_reconds(field,record);
			}			
			else {
				printf("yo\n");	
				exit(EXIT_FAILURE);
			}
		}
	}  
	//print_file();
	return 0;
}

		


