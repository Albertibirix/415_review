#pragma once
class SharedMemory{
private:
	char Name[100];
	char Size;
	char *P;
	int q;
	int N;

public:
	SharedMemory(char *Name, char Size, int q, int N);
	~SharedMemory();
	void write_data(double A[], char str[]);
};
