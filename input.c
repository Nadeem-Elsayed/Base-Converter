#include <stdlib.h>
#include <stdio.h>
#include <string.h>

/*
 * input.c
 * checks that the inputs given to convert utility are proper
 * Nadeem Elsayed Nov 4, 2024
 */

//outlines usage of function
int usage() {
        fprintf(stderr, "Usage: convert [-b BASE] [-r START FINISH]\n       1 < BASE < 37\n       START and FINISH are long integers\n");
        return EXIT_FAILURE;
}

//checks that the given input is valid, otherwise prints usage
int checkInput (int argc, char *argv[]) {
	if (argc == 1) {
		return EXIT_SUCCESS;
	} else if (argc == 3) {//if 3 arguments including call
		if (strcmp(argv[1], "-b") == 0 && atol(argv[2]) > 1 && atol(argv[2]) < 37) {//if proper base and base range
			return EXIT_SUCCESS;
		} else {//improper base or base out of range
			usage();
			return EXIT_FAILURE;
		}
	} else if (argc == 4) {
		if (strcmp(argv[1], "-r") == 0) {
			/*if both numbers are zero before conversion failure
                        *i'm doing this because conversion failure returns zero
                        *checking beforehand prevents confusion
                        */
                        if (strcmp(argv[2], "0") == 0 && strcmp(argv[3], "0") == 0) {
                                return EXIT_SUCCESS;
                        }
                        //if first range number is not zero
                        if (strcmp(argv[2], "0") != 0) {
                                int start = atol(argv[2]);
                                if (start == 0) {//conversion failed
                                        usage();
                                        return EXIT_FAILURE;
                                }
                        }
                        //if second range number is not zero
                        if (strcmp(argv[3], "0") != 0) {
                                int end = atol(argv[3]);
                                if (end == 0) {//conversion failed
					usage();
					return EXIT_FAILURE;
                                }
                        }
                        return EXIT_SUCCESS;
		} else {
			usage();
			return EXIT_FAILURE;
		}
	} else if (argc == 6) {//if 6 arguments including call
		//if proper base, and range given
		if (strcmp(argv[1], "-b") == 0 && atol(argv[2]) > 1 && atol(argv[2]) < 37 && strcmp(argv[3], "-r") == 0) {
			/*if both numbers are zero before conversion failure
			*i'm doing this because conversion failure returns zero
			*checking beforehand prevents confusion
			*/
			if (strcmp(argv[4], "0") == 0 && strcmp(argv[5], "0") == 0) {
				return EXIT_SUCCESS;	
			}
			//if first range number is not zero
			if (strcmp(argv[4], "0") != 0) {
				int start = atol(argv[4]);
				if (start == 0) {//conversion failed
					usage();
					return EXIT_FAILURE;
				}
			}
			//if second range number is not zero
			if (strcmp(argv[5], "0") != 0) {
				int end = atol(argv[5]);
				if (end == 0) {//conversion failed
						usage();
						return EXIT_FAILURE;
				}
			}
			return EXIT_SUCCESS;
		} else {
			usage();
			return EXIT_FAILURE;
		}
	} else {
		usage();
		return EXIT_FAILURE;
	}
}
//returns the base of the calculation from given arguments
//if no base given, default is 16
long getBase(int argc, char *argv[]) {
	if (argc == 3) {
	return atol(argv[2]);
	} else {
		return 16;
	}
}
//returns exit success if a range is given in arguments
int isRange(int argc, char *argv[]) {
	if (argc == 6 || argc == 4) {//ex: -b 10 -r 1 2 or -r 1 2
		return EXIT_SUCCESS;
	} else {
		return EXIT_FAILURE;
	}
}
//returns the two numbers that provide the range
void getRange(int argc, char *argv[], long *start, long *end){
	if (argc == 6) {
		*start = atol(argv[4]);
		*end = atol(argv[5]);
	} else {
		*start = atol(argv[2]);
		*end = atol(argv[3]);
	}
}
