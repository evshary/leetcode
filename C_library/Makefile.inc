all: solution

solution: solution.c ../C_library/library.c
	gcc solution.c ../C_library/library.c -o solution

clean:
	rm -rf solution