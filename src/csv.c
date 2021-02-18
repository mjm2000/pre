#include <stdio.h>
#include <stdlib.h>
#define READFILE "r"
#define C 1000 
#define R 100
#define S 100
char *get_index(int i, int j,char *buff){
	int index= (i*R*S) + (j*R);
	return (buff + index);
}


int fetch_max(char* field){
	// We take the field string that was inputted and then find the value that was highest
	
	// Int that will be used to store the highest value 
	int highest = 0 ;
	// If there is no numeric data in the indicated field in any of the data records the program exits with error code EXIT_FAILURE.
	if(!has_numeric_data(field)){
		return 0;
	}

	return highest;

}



char *read_csv(char csv_name[]){
	FILE *csv = fopen(csv_name, READFILE ); 
//	char buff[800][100][100];

	printf("yo\n");
	char *buff = (char*)malloc(C * R * S * sizeof(char));
	char value = ' ';
	//i is row, j is collomn, k is string pos
	int i,j,k =0 ;
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

	
	for (int i = 0; i < argc-1; i++ ){
		char *arg = argv[i];

	}  
	char *file = read_csv(argv[argc-1]);
	file = get_index(10,10,file);
	printf("string:%s\n", file);

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

		


