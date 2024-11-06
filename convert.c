#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "input.h"

/*
 *convert.c
 *converts a given number to a specified base
 *Nadeem Elsayed October 29, 2024
 */

//function prototypes
int readConvert(long base);
int rangeConvert(long base, long start, long end);

//where magic happens, mainly checks all values are fine using input.c
int main(int argc, char *argv[]) {
	int result = checkInput(argc, argv);
	if (result == EXIT_SUCCESS) {//if input matches format
		long base = getBase(argc, argv);
		if (isRange(argc, argv) == EXIT_SUCCESS) {//if range given
			long start;
			long end;
			getRange(argv, &start, &end);
			result = rangeConvert(base, start, end);
			return EXIT_SUCCESS;
		} else {
			result = readConvert(base);
			if (result == EXIT_FAILURE) {
				return EXIT_FAILURE;
			}
			return EXIT_SUCCESS;
		}
	} else {//if input does not match format
		return EXIT_FAILURE;
	}
}
/*
* takes the base, number, array/pointer, and a current length
* recursion involved
* returned array is still backwards when it comes to appropriate solution
*/
int *findValues(int base, long num, int *p, int* currentLength){
	//---------edge cases------------
	if (num == 0 && *currentLength == 0) {
		currentLength++;
        p[0] = 0;  // Handle 0 case directly
        return p;
    }

    if (num == 0) {//if quotient is zero
        return p;
    }
    long remainder = num % base;
	p[*currentLength] = remainder;
	(*currentLength)++;//increment
    return findValues(base, num / base, p, currentLength);
}
/*
*Takes an array filled with longs and converts them to proper characters
*0-9, A-Z
*also reverses the array so that it matches solution
*/
void convertBase(int base, int *a, int length){
	char ichar;
	if (length == 0) {
		printf("0\n");
		return;
	}
	for (int i = length - 1; i >= 0; i--) {  // start from most significant to least significant
			if (abs(a[i]) < 10) {//characters from 0-9 are together in ASCII
				ichar = '0' + abs(a[i]);
			} else {//characters from A-Z together in ASCII
				ichar = 'A' + abs(a[i]) - 10;//-10 because first 10 are assigned for 0-9
			}
        if (i == length - 1 && a[i]< 0) {
			printf("-%c",ichar);//starting negative sign
		} else {
			printf("%c", ichar);
		}
    }
    printf("\n"); //new line to prevent confusion
}
/*
 *converts a single number to the given base
 *uses recursion
 */
void convert(long base, long num) {
	int *a = calloc(64, sizeof(char));
	int length = 0;
	findValues(base, num, a, &length);//side effect length
	convertBase(base, a, length);

	free(a);//free up memory
}
/*
 *converts all values from standard input
 */
int readConvert(long base){
	int result;
	long num;

	do {//scans for long until error or EOF 
		result = scanf("%ld", &num);
		if (result == 0 || result == EOF) {
			break;
		} else {
			convert(base, num);
		}
	} while (result != 0 && result != EOF);
	
	if (result == 0) {//if some sort of error
		fprintf(stderr, "Error: Non-long-int token encountered.\n");
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}
//converts all numbers in a range to given base
int rangeConvert(long base, long start, long end){
	for (long i = start; i<=end; i++){
		convert(base, i);
	}
	return EXIT_SUCCESS;
}
