#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define TRUE_VAL 0
#define FALSE_VAL 1
#define MAX 1000
#define WORD 10
void swap(char* x, char* y);
void permute(char *a, int l, int r, char *permutations[MAX][WORD], int *count);
int find_string_in_file( char *file_name, char **str) ;
int validate_file(char* path );
int has_a_permutation(char* filename, char* permutations[MAX][WORD]);
void print_permutations(char* filename ,char* permutations[MAX][WORD]);
