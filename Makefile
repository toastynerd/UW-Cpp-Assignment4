CC=c++
CFLAGS=-std=c++11 -stdlib=libc++

test: 
	rm -f a.out
	${LITTLE_ENDIAN}
	$(CC) -std=c++11 -stdlib=libc++ CppUnitLite/*.cpp *.cpp
	./a.out

