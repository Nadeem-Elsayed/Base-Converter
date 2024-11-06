convert: convert.c input.c input.h
	gcc -o convert convert.c input.c
ctest: convert.c convert.h input.c input.h
	gcc -o ctest --coverage convert.c input.c
