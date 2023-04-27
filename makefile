CC = g++
CFLAGS = -g -Wall
TARGET = exe

$(TARGET): hw5_Truong_Vu.o zombie_Truong.o conga_Truong.o
	$(CC) $(CFLAGS) -o $(TARGET) hw5_Truong_Vu.o zombie_Truong.o conga_Truong.o

hw5_Truong_Vu.o: hw5_Truong_Vu.cpp
	$(CC) $(CFLAGS) -c hw5_Truong_Vu.cpp

zombie_Truong.o: zombie_Truong.cpp zombie_Truong.h
	$(CC) $(CFLAGS) -c zombie_Truong.cpp

conga_Truong.o: conga_Truong.cpp conga_Truong.h
	$(CC) $(CFLAGS) -c conga_Truong.cpp

clean:
	del *.o
	del *.exe