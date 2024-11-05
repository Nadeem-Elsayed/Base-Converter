convert: convert.c input.c input.h
	gcc -o convert convert.c input.c
ctest: ctest.c convert.c convert.h input.c input.h
	gcc -o ctest --coverage ctest.c convert.c input.c
