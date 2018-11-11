
#include <iostream>
#include <fstream>
using namespace std;

#include "hydro.h"

int main()
{
	FlowList masterList;
	int numRecords;
	int quit = 0;
	
	displayHeader();	
	numRecords = readData(masterList);

	while(1)
	{
		
		if(quit == 1)
		{
			break;
		}
	}
	
	
	return 0;
}

int readData(const FlowList& list)
{
	ifstream inData;
	inData.open("flow.txt");
	
}

void displayHeader()
{
	cout <<"Program: Flow Studies - Fall 2018 \nVersion 1.0 \nLab Section B01 \nProduced By: William Ledingham\n\n <<< Press Enter to Continue >>>\n";
}