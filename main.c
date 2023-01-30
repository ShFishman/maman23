#include "permutation.h"
/* Avraham Shimon Fishman 209086446
main gets 3 arguments from user:
1) call to main.
2) name of a file.
3) a string.
prints all permutations of the string that exist in file
prints 'no permutations found' if non of them exist in file
*/
int main(int argc, char *argv[]) {
	int n;
	int count;
		
	char* permutations[MAX][WORD];
	if( argc !=  3){
		printf("EROR: insert 3 argumaents\n");
		return 0;
	}	
	n = strlen(argv[2]);
	count = 0;

	if (validate_file( argv[1] ) == FALSE_VAL)
		return 0; 
	permute(argv[2], 0, n - 1, &permutations[0], &count);
	
	if ( has_a_permutation( argv[1], permutations ) == TRUE_VAL){
		printf("Permutations are:\n");		
		print_permutations( argv[1], permutations );
	}
	else{
		printf("No permutations found.\n");
	}
	return 0;
}




