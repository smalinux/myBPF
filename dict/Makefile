all:
	gcc -c alloc.c fmacros.h alloc.h
	gcc -c dict.c fmacros.h alloc.h dict.h
	gcc -c sds.c sds.h sdsalloc.h alloc.h
	gcc -c ini.c ini.h
	gcc -o main main.c dict.o alloc.o sds.o ini.o

clean:
	rm *.o main
