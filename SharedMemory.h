#pragma once

#include "shared_memory.h"

class SharedMemory{
private:
	char *Name; // name of block of shared memory
	int Size; // size (bytes) of shared memory block
	char *mp; // pointer to shared memory block
	int q; // number of the program using a given instance of the object (token...???)
	int N; // total number of programs accessing the shared memory block

public:

	SharedMemory();
	SharedMemory(char *Name, int Size, int q, int N);
	~SharedMemory();
	void write_data(double A[], char str[]);
	void read_data(double A[], char str[]);
};
