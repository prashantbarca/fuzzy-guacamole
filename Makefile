#
# Makefile
# prashant, 2016-02-01 20:29
#



CC= g++
TARGET= simon.o socket.o server device meter
CFLAGS=  -w -Wunreachable-code `libgcrypt-config --cflags --libs` -lpthread -std=c++11 -fopenmp -Wall -Wno-format -g -O3
all : $(TARGET)
simon.o:
	$(CC) -c simon.cpp $(CFLAGS)
socket.o:
	$(CC) -c socket.cpp $(CFLAGS)
server: 
	$(CC) -o server server.cpp socket.o simon.o $(CFLAGS)
device: 
	$(CC) -o device device.cpp socket.o simon.o $(CFLAGS)
meter: 
	$(CC) -o meter meter.cpp socket.o simon.o $(CFLAGS)
clean: 
	rm $(TARGET)


# vim:ft=make
#

