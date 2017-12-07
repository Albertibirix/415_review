#include <iostream>
#include <fstream>
#include <cmath>
#include <cstdio>
#include <conio.h>

#include "SharedMemory.h"
#include "shared_memory.h"

using namespace std;

int main(){

	//char mem_name[] = "Testy";

	SharedMemory memory1("Testy", 100000, 1, 2);
	
	double test[100];
	
	// initialize "test"
	for (int i = 0; i < 100; i++){
		test[i] = i;
	}

	char str[] = "Hello!";

	memory1.write_data(test, str);
//	memory1.read_data(test, str);

	_getch();
	return 0;
}

/*int main(){

	char arr[] = "Gian";

	int size = (int) sizeof(arr);

	cout << size;


	_getch();
	return 0;
}*/