#include <iostream>
#include <fstream>
using namespace std;
#include "list.h"


FlowList::FlowList()
{
	headM = 0;
	n_years = 0;
}
FlowList::~FlowList()
{
	destroy();
}
FlowList::FlowList(const FlowList& source)
{
	copy(source);
}

FlowList& FlowList::operator= (const FlowList& rhs)
{
	if(this != &rhs)
	{
		destroy();
		copy(rhs);
	}
	return *this;
}


void FlowList::destroy()
{
	Node* nodePtr = headM;
	Node* after = headM;
	while(nodePtr != 0)
	{
		nodePtr = nodePtr->next;
		delete after;
		after = nodePtr;
	}
	headM = 0;
}
void FlowList::copy(const FlowList& source)
{

	Node* sourceNodePtr = source.headM;
	
	if(sourceNodePtr == 0)
	{
		headM = 0;
		return;
	}
	
	headM = new Node;
	Node* nodePtr = headM;
	headM->item.year = sourceNodePtr->item.year;
	headM->item.flow = sourceNodePtr->item.flow;
	
	sourceNodePtr = sourceNodePtr->next;
	
	while(sourceNodePtr != 0)
	{
		nodePtr->next = new Node;
		nodePtr = nodePtr->next;
		
		nodePtr->item.year = sourceNodePtr->item.year;
		nodePtr->item.flow = sourceNodePtr->item.flow;
		
		sourceNodePtr = sourceNodePtr->next;
	}
	nodePtr->next = 0;
	
}


Node* FlowList::getHeadM()
{
	return headM;
}

int FlowList::getnyears()const
{
	return n_years;
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
		Node* nodePtr = headM;
		while(nodePtr != 0)
		{
			if(nodePtr->item.year == year)
			{
				return 0;
			}
			nodePtr = nodePtr->next;
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
}

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
*/
