#include <iostream>
#include <fstream>

#include "list.h"
#include "hydro.h"

using namespace std;

void displayHeader()
{
	cout <<"Program: Flow Studies - Fall 2018 \nVersion 1.0 \nLab Section B01 \nProduced By: William Ledingham\n\n <<< Press Enter to Continue >>>\n";
}
int readData(FlowList& list)
{
	int year;
	double flow;
	int nread = 0;
		
	ifstream Data("flow.txt", ios::in);
	if(Data.fail())
	{
		cout << "Error Opening File";
		exit(1);
	}
	
	while(!Data.eof())
	{
		Data >> year >> flow;
		list.insert(year, flow);
		nread++;
	}
	return nread;
}
int menu()
{
	int choice;
	//do{
		cin >> choice;		
	//}while(choice < 0 || choice > 5);
	return choice;
}



int main(void)
{
	FlowList masterList;
	int numRecords;
	int quit = 0;
	
	displayHeader();	
	numRecords = readData(masterList);
	
	//out<< menu();

	while(1)
	{
		
		switch(menu()){
			case 1:

				masterList.display();
			break;
			case 2:
			
			break;
			case 3:
			
			break;
			case 4:
			
			break;
			case 5:
			
			break;

			default:
				quit = 1;	
		}
		if(quit == 1)
		{
			break;
		}
	
	}
	
	return 0;
}


