#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 *convert.c
 *converts a given number to a specified base
 *Nadeem Elsayed October 29, 2024
 */

usage() {
	fprintf(stderr, "USAGE:
			convert [-b BASE] [-r START FINISH]
			1 < BASE < 37
			START and FINISH are long integers");
}

//checks that the given input is valid, otherwise prints usage
int checkInput (int argc, char *argv[]) {
	printf("valid\n");
}
int convert(int argc, char *argv[]) {
	checkInput(argc, argv);
}
