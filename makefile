all: compile link

compile:
	g++ -c hi-lo.cpp

link:
	g++ -o hi-lo hi-lo.o

clean:
	rm -f hi-lo *.o
