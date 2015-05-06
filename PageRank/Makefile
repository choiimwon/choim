#
S4SIM_HOME = ../..
CFLAGS = -g

INCLUDE=-I../../include
PTHREAD = ../../external/m5threads
CC = gcc
CPP = g++

ARMC = arm-linux-gnueabihf-gcc
ARMCC = arm-linux-gnueabihf-g++
ARMFLAGS = -march=armv7-a -marm

all : SpageRank Executable s4lib.o main_isp.o PageRank_par.o PageRank.o STpageRank main_par_isp.o Executable2

STpageRank: SpageRank.c ${S4SIM_HOME}/src/isp_socket.c
	$(CC) $(CFLAGS) -static -o $@ $^ -lpthread $(INCLUDE)
SpageRank: SpageRank.c ${S4SIM_HOME}/src/isp_socket.c
	$(CC) $(CFLAGS) -static -o $@ $^ -lpthread $(INCLUDE)
Executable: s4lib.o main_isp.o PageRank.o 
	$(ARMCC) ${ARMFLAGS} -static s4lib.o PageRank.o main_isp.o -o main_isp $(INCLUDE)
Executable2: s4lib.o PageRank_par.o main_par_isp.o ${PTHREAD}/pthread.c
	$(ARMCC) ${ARMFLAGS} -static s4lib.o main_par_isp.o PageRank_par.o -o main_par_isp -lpthread $(INCLUDE)
s4lib.o: s4.h s4lib.c
	$(ARMC) ${ARMFLAGS} -static -c s4lib.c
PageRank.o: PageRank.h PageRank.cpp
	$(ARMCC) ${ARMFLAGS} -static -c PageRank.cpp
main_par_isp.o: main.hpp main_par_isp.cpp ${PTHREAD}/pthread.c 
	$(ARMCC) ${ARMFLAGS} -static -c main_par_isp.cpp -lpthread $(INCLUDE) 
main_isp.o: main.hpp main_isp.cpp 
	$(ARMCC) ${ARMFLAGS} -static -c main_isp.cpp 
PageRank_par.o: PageRank_par.h PageRank_par.cpp
	$(ARMCC) ${ARMFLAGS} -static -c PageRank_par.cpp
clean:
	rm -rf  SpageRank STpageRank main_par_isp main_par_isp.o PageRank_par.o s4lib.o	main_isp.o PageRank.o main_isp

