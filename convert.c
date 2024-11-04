#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *convert.c
 *converts a given number to a specified base
 *Nadeem Elsayed October 29, 2024
 */

int usage() {
	fprintf(stderr, "USAGE:\nconvert [-b BASE] [-r START FINISH]\n1 < BASE < 37\nSTART and FINISH are long integers");
	return EXIT_SUCCESS;
}

//checks that the given input is valid, otherwise prints usage
int checkInput (int argc, char *argv[]) {
	printf("valid\n");
}
int convert(int argc, char *argv[]) {
	checkInput(argc, argv);
}
