#include <stdio.h>
#define READFILE "r"

void read_csv(char csv_name[]){
	FILE *csv = fopen(csv_name, READFILE ); 
	char buff[800][100][100];
	char value = ' ';
	//i is row, j is collomn, k is string pos
	int i,j,k =0 ;
	while (value != EOF ) {
		value = fgetc(csv);
		if (value == ','){j++; k=0;}			
		else if ( value == '\n' ) {i++; j=0;}
		else {buff[i][j][k] = value; k++;}
		printf("i:%i, j:%i, k:%i \n",i,j,k);
	}
	for (int incr=0; incr < i; incr++ ) {
		for (int jincr; jincr < j; jincr++){
		//	printf("%s yo\n",buff[i][j]);
		}
	}
}

int main(int argc, char *argv[]){

	
	for (int i = 0; i < argc-1; i++ ){
		char *arg = argv[i];

	}  
	read_csv(argv[argc-1]);
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

		


