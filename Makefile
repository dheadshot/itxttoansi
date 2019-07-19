itxttoansi: main.o ansifuncs.o
	gcc -o itxttoansi main.o ansifuncs.o
	chmod +x itxttoansi

main.o: main.c ansifuncs.h
	gcc ${CFLAGS} -c main.c

ansifuncs.o: ansifuncs.c ansifuncs.h
	gcc ${CFLAGS} -c ansifuncs.c

