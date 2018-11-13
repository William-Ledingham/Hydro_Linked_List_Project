#include <iostream>
#include <fstream>

#include "list.h"
#include "hydro.h"

using namespace std;

#define FILENAME "flow.txt"

int main(void)
{
	FlowList masterList;

	int quit = 0;
	
	displayHeader();	
	readData(masterList);

	while(1)
	{
		pressEnter();
		
		switch(menu()){
			case 1:
				display(masterList);
			break;
			case 2:
				addData(masterList);
			break;
			case 3:
				saveData(masterList);
			break;
			case 4:
				removeData(masterList);
			break;
			case 5:
				quit = 1;
			break;

			default:
				quit = 1;	
		}
		if(quit == 1)
		{
			break;
		}
	
	}
	cout << "Program terminated successfully";
	return 0;
}


void displayHeader()
{
	cout <<"Program: Flow Studies - Fall 2018 \nVersion 1.0 \nLab Section B01 \nProduced By: William Ledingham\n";
}

void display(FlowList& masterList)
{
	const Node* nodePtr = masterList.getHeadM();
	
	cout << "\nYear     Flow (in billions of cubic meters)\n";
	cout << "----     ----------------------------------\n";
	
	while(nodePtr != 0)
	{
		//cout << "\nwhat\n";
		cout << nodePtr->item.year << "     " << nodePtr->item.flow << "\n";
		nodePtr = nodePtr->next;
	}
	cout << "\nThe annual average of the flow is: " << average(masterList) << " (million cubic meters)\n";
	cout << "The median flow is: " << median(masterList) << " (million cubic meters)";
}
double average(FlowList& masterList)
{
	const Node* nodePtr = masterList.getHeadM();
	int n_years = masterList.getnyears();
	double sum = 0;
	while(nodePtr != 0)
	{
		sum += nodePtr->item.flow;
		nodePtr = nodePtr->next;
	}
	return sum/((double)n_years);
	
}

double median(FlowList& masterList)
{
	const Node* nodePtr = masterList.getHeadM();
	int n_years = masterList.getnyears();
	int evenOrOdd = n_years%2;
	int index = n_years/2;
	
	for(int i = 1; i <= index; i++)
	{
		nodePtr = nodePtr->next;
	}
		
	if(evenOrOdd == 0)
	{
		return (nodePtr->item.flow + nodePtr->next->item.flow) /2;
	}
	else
	{
		return nodePtr->item.flow;
	}
}

int readData(FlowList& list)
{
	int year;
	double flow;
	int nread = 0;
		
	ifstream Data(FILENAME, ios::in);
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
	Data.close();
	return nread;
}
int menu()
{

	cout << "Please select one of the following operations\n	1. Display flow list, average, and median \n	2. Add data \n	3. Save data into the file \n	4. Remove data \n	5. Quit \nEnter your choice (1, 2, 3, 4, or 5): ";
	int choice;
	//do{
		cin >> choice;		
	//}while(choice < 1 || choice > 5);
	return choice;
}

void addData(FlowList& masterList)
{
	int year;
	double flow;
	cout << "\nPlease enter a year: ";
	cin >> year;
	if(cin.fail())
	{
		cout << "Error";
	}
	cout << "Please enter the flow: ";
	cin >> flow;
	if(cin.fail())
	{
		cout << "Error";
	}
	if(masterList.insert(year, flow))
	{
		cout << "\nNew record inserted successfully\n";
	}
	else
	{
		cout << "\nError: duplicate data.\n";
	}
}

void removeData(FlowList& masterList)
{
	int year;
	cout << "Please enter the year that you want to remove: ";
	cin >> year;
	if(cin.fail())
	{
		cout << "Error";
	}
	if(masterList.remove(year))
	{
		cout << "\nRecord was removed successfully\n";
	}
	else{
		cout << "\nError: No such data.\n";
	}
}

void saveData(FlowList& masterList)
{
	const Node* nodePtr = masterList.getHeadM();
	
	ofstream Data;
	Data.open(FILENAME);
	if(Data.fail())
	{
		cout << "Error Opening File";
		exit(1);
	}
	while(nodePtr != 0)
	{
		Data << nodePtr->item.year << "     " << nodePtr->item.flow << "\n";
		nodePtr = nodePtr->next;
	}
	Data.close();
	cout << "\nData successfully saved to file\n";

}

void pressEnter()
{
	cout << "\n<<< Press Enter to Continue >>>\n";
	char ch = 'x';
	//cin.clear();
	//cin.ignore(10);
	//while(ch != '\n')
	//{
			cin.get();
	//}
}

