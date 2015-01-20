OBJS = Fraction.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

project2: $(OBJS)
	    $(CC) $(LFLAGS) $(OBJS) -o project2

Fraction.o : Fraction.cpp Fraction.h
	    $(CC) $(CFLAGS) Fraction.cpp

main.o : 
	    $(CC) $(CFLAGS) main.cpp

clean:
	rm *.o 
