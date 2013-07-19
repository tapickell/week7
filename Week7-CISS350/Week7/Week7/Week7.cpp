// Week7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "listQdriver.h"
#include "heapQdriver.h"



int _tmain(int argc, _TCHAR* argv[])
{
	
	heapQdriver heapDrive = heapQdriver();
	heapDrive.RunTests();

	std::cout << std::endl;

	listQdriver listDrive = listQdriver();
	listDrive.RunTests();

	std::cout << "Testing finished" << std::endl;
	system("pause");
	return 0;
}

