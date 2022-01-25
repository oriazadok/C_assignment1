CC = gcc
AR = ar
CFLAGS = -Wall -g

OBJECTS_MAIN = main.o
OBJECTS_BASIC = basicClassification.o
OBJECTS_LOOP = advancedClassificationLoop.o
OBJECTS_REC = advancedClassificationRecursion.o

all: mains maindloop maindrec

#target commands
mains: $(OBJECTS_MAIN) libclassrec.a
	$(CC) $(CFLAGS) -o mains $(OBJECTS_MAIN) libclassrec.a -lm

maindloop: $(OBJECTS_MAIN) libclassloop.so
	$(CC) $(CFLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloop.so -lm

maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(CFLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so -lm


loops: libclassloop.a
recursives: libclassrec.a
loopd: libclassloop.so
recursived: libclassrec.so

#static libs
libclassloop.a: $(OBJECTS_BASIC) $(OBJECTS_LOOP)
	$(AR) -rcs libclassloop.a $(OBJECTS_BASIC) $(OBJECTS_LOOP)

libclassrec.a: $(OBJECTS_BASIC) $(OBJECTS_REC)
	$(AR) -rcs libclassrec.a $(OBJECTS_BASIC) $(OBJECTS_REC)

#shared libs
libclassloop.so: $(OBJECTS_BASIC) $(OBJECTS_LOOP)
	$(CC) -shared -o libclassloop.so $(OBJECTS_BASIC) $(OBJECTS_LOOP)
libclassrec.so: $(OBJECTS_BASIC) $(OBJECTS_REC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_BASIC) $(OBJECTS_REC)


#objects
main.o: main.c NumClass.h
	$(CC) $(CFLAGS) -c main.c

basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(CFLAGS) -c basicClassification.c

advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationLoop.c

advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(CFLAGS) -c advancedClassificationRecursion.c


.PHONY: clean all

clean:
	rm -f *.o *.a *.so  mains maindloop maindrec
