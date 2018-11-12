#include <iostream>
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
void FlowList::insert(int year, double flow)
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
}

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
	cout << "The median flow is: " << median() << " (million cubic meters)\n";
}
