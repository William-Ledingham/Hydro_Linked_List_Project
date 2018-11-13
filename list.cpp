#include <iostream>
#include <fstream>
using namespace std;
#include "list.h"


FlowList::FlowList()
{
	headM = 0;
	n_years = 0;
}/*
FlowList(const FlowList& source)
{
	
}
FlowList& operator= (const FlowList& rhs)
{
	
}
*/
void FlowList::resetNodePtrM()
{
	nodePtrM = headM;
}
Node* FlowList::getHeadM()
{
	return headM;
}


int FlowList::insert(int year, double flow)
{	
	n_years++;
	Node* newNode = new Node;
	newNode->item.year = year;
	newNode->item.flow = flow;

	if(headM == 0 || headM->item.flow > flow)
	{
		newNode->next = headM;
		headM = newNode;
	}
	else
	{
		resetNodePtrM();
		while(nodePtrM != 0)
		{
			if(nodePtrM->item.year == year)
			{
				return 0;
			}
			nodePtrM = nodePtrM->next;
		}
		
		Node* before = headM;
		Node* after = headM->next;
		
		while( after != 0 && flow > after->item.flow )
		{
			after = after->next;
			before = before->next;
		}
		before->next = newNode;
		newNode->next = after;
		
	}
	return 1;
}
int FlowList::remove(int year)
{
	Node* before = headM;
	Node* after = headM->next;
	while(after != 0)
	{
		if(after->item.year == year)
		{
			before->next = after->next;
			delete after;
			return 1;
		}
		after = after->next;
		before = before->next;
	}
	return 0;
}
/*
double FlowList::average()const
{
	Node* nodePtr = headM;
	double sum = 0;
	while(nodePtr != 0)
	{
		sum += nodePtr->item.flow;
		nodePtr = nodePtr->next;
	}
	return sum/((double)n_years);
	
}

double FlowList::median()const
{
	Node* nodePtr = headM;
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

void FlowList::display()const
{
	Node* nodePtr = headM;
	
	cout << "\nYear     Flow (in billions of cubic meters)\n";
	cout << "----     ----------------------------------\n";
	
	while(nodePtr != 0)
	{
		//cout << "\nwhat\n";
		cout << nodePtr->item.year << "     " << nodePtr->item.flow << "\n";
		nodePtr = nodePtr->next;
	}
	cout << "\nThe annual average of the flow is: " << average() << " (million cubic meters)\n";
	cout << "The median flow is: " << median() << " (million cubic meters)";
}*/

void FlowList::saveToText(const char* filename)const
{
	Node* nodePtr = headM;
	ofstream Data;
	Data.open(filename);
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
}

