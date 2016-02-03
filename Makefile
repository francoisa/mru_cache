TGT = stocks
OBJS = stock.o main.o
CC = g++
DEBUG = -g
CFLAGS = -Wall -std=c++0x -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

$(TGT) : $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o $(TGT)

main.o:  stock.h main.cc
	$(CC) $(CFLAGS) main.cc

stock.o: stock.h stock.cc 
	$(CC) $(CFLAGS) $(TGT).cc

clean:
	rm -f *.o *~ $(TGT)
