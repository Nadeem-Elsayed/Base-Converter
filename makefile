convert: convert.c
	gcc -o convert convert.c
coverage: convert.c ctest.c convert.h
	gcc -o ctest --coverage ctest.c convert.c
