#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <conio.h>
#include <Windows.h>

#include "SharedMemory.h"
#include "shared_memory.h"

using namespace std;

SharedMemory::SharedMemory()
{



}

SharedMemory::SharedMemory(char *Name, int Size, int q, int N)
{
	this->Size = Size;
	this->q = q;
	this->N = N;

	this->Name = Name;

	mp = shared_memory(this->Name, this->Size); // can also use the passed variables by getting rid of "this->"

//	double *x;       // doing this does not work! Exception handling error occurs.
//	x = (double *)mp;

	// initialize each byte in memory to zero
	for (int i = 0; i < Size; i++){
		mp[i] = 0;
	}
}

void SharedMemory::write_data(double A[], char str[]){

	int *g = (int *)mp; // for storing token q
//	char *l = (char *)mp; // for writing str[]

	// determine length of string
	int str_len = strlen(str);

	*g = q; // store token into first slot of memory

	while (1){
		if (*g == 1){

			mp += sizeof(int); // go to byte #4 of memory block

			double *k = (double *)mp; // for writing double A[]
			// store double A[] into shared memory block
			for (int i = 0; i < 100; i++){
				k[i] = A[i];
			}

			mp += sizeof(A);

			// store string into memory block
			for (int i = 0; i < str_len; i++){
				mp[i] = str[i];
			}
		}
		else Sleep(10);
	}

//	for (int i = 100; i)

}

void SharedMemory::read_data(double A[], char str[]){

	int *g = (int *)mp;
	*g = q;

	while (1){
		if (*g == 2){

			mp += sizeof(int); // go to byte #4 of memory block

			double *read_A = (double *)mp;
			for (int i = 0; i < 100; i++){
				A[i] = read_A[i];
				cout << A[i] << endl;
			}

			mp += sizeof(A);

			char *read_str = (char *)mp;
			int i = 0;
			while(1){
				str[i] = read_str[i];
				if (str[i] == '\0'){ // if null character is found, break out of for loop
					break;
				}
				i++;
			}
		}
		else Sleep(10);
	}
}


SharedMemory::~SharedMemory()
{



}
