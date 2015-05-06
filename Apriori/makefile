#
S4SIM_HOME = ../..
CFLAGS = -g

INCLUDE=-I${S4SIM_HOME}/include
PTHREAD = ${S4SIM_HOME}/external/m5threads
CC = gcc
CPP = g++

ARMCC = arm-linux-gnueabihf-g++
ARMFLAGS = -march=armv7-a -marm

all : S4apriori Executable s4lib.o database.o sets.o apriori.o AprioriImplementation.o 

S4apriori : S4apriori.c ${S4SIM_HOME}/src/isp_socket.c
	$(CC) $(CFLAGS) -static -o $@ $^ -lpthread $(INCLUDE)
Executable: s4lib.o AprioriImplementation.o database.o sets.o apriori.o
	arm-linux-gnueabihf-g++ -static s4lib.o database.o sets.o apriori.o AprioriImplementation.o -o AprioriImplementation
s4lib.o: s4.h s4lib.c
	arm-linux-gnueabihf-gcc -static -c s4lib.c
database.o: database.hpp database.cpp
	arm-linux-gnueabihf-g++ -static -c database.cpp
sets.o: sets.hpp sets.cpp
	arm-linux-gnueabihf-g++ -static -c sets.cpp
apriori.o: apriori.hpp apriori.cpp
	arm-linux-gnueabihf-g++ -static -c apriori.cpp
AprioriImplementation.o: AprioriImplementation.hpp	AprioriImplementation.cpp
	arm-linux-gnueabihf-g++ -static -c	AprioriImplementation.cpp
clean:
	rm -rf S4apriori S4apriori.o  AprioriImplementation.o database.o sets.o s4lib.o apriori.o AprioriImplementation 

