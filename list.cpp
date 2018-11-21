//list.cpp
//W. Ledingham

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
	Node* newNode = new Node;
	newNode->item.year = year;
	newNode->item.flow = flow;

	if(headM == 0)
	{
		n_years++;
		newNode->next = headM;
		headM = newNode;
	}
	if(headM->item.flow > flow)
	{		
		if(headM->item.year == year)
		{
			return 0;
		}
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
		n_years++;
	return 1;
}
int FlowList::remove(int year)
{

	Node* before = headM;
	Node* after = headM->next;
	if(headM->item.year == year)
	{
		n_years--;
		delete headM;
		headM = after;
		return 1;
	}
	while(after != 0)
	{
		if(after->item.year == year)
		{
			before->next = after->next;
			delete after;
			n_years--;
			return 1;
		}
		after = after->next;
		before = before->next;
	}
	return 0;
}