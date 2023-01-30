#include "permutation.h"

/* Function to swap values at two pointers */
void swap(char *x, char *y) {
char temp;
temp = *x;
*x = *y;
*y = temp;
}
/* makes all permutations of a string and saves them into an array
called 'permutations'*/
void permute(char *a, int l, int r, char  *permutations[MAX][WORD] , int *count) {
	int i;

	if (*count <= 100 ){
		if (l == r) {
		permutations[*count][0] = (char *) malloc((strlen(a) + 1) * sizeof(char));
		strcpy(permutations[*count][0], a);
		(*count)++;
		}

		else {
		for (i = l; i <= r; i++) {
			swap((a + l), (a + i));
			permute(a, l + 1, r, permutations, count);
			swap((a + l), (a + i));
			}
		}
	}
}

/* searches a permutatio in a file */
int find_string_in_file( char *file_name, char **str) {
	FILE *fp;
	char buffer[1024];

	fp = fopen(file_name, "r");
	if (fp == NULL) {
	printf("Error: Unable to open file.\n");
		return 1;
	}

    while (fgets(buffer, sizeof(buffer), fp) != NULL) {
        if (strstr(buffer, *str) != NULL) {
            fclose(fp);
            return 0;
        }
    }

    fclose(fp);
    return 1;
}

/*function gets a file and validates if it's null*/
int validate_file(char* path ){
	FILE *file;
	file = fopen( path , "r");
	if ( file == NULL ) {
		printf( "Failed to open file.\n" );
		return FALSE_VAL;
	}
	fclose(file);
	return TRUE_VAL;
}
/*function checks if at least one permutation exists in the file
returns FALSE_VAL if not TRUE_VAL for yes */
int has_a_permutation(char* filename, char* permutations[MAX][WORD] ){
	int flag = FALSE_VAL;
	int i = 0;
	for ( i = 0 ; permutations [i][0] != NULL ; i++ ) {
		flag = find_string_in_file( filename , permutations[i] );
		if (flag == TRUE_VAL) {
			return TRUE_VAL;
		}
	}
	return flag;
}
/* prints all permutations that exist in the file*/
void print_permutations(char* filename ,char* permutations[MAX][WORD]){
	int i;	
	for ( i = 0 ; permutations[i][0] != NULL ; i++ ) {
		if( find_string_in_file( filename , permutations[i] ) == TRUE_VAL)		
			printf("%s\n" , permutations[i][0]);
	}
}


 


