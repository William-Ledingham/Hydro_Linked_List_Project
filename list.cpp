
#include "list.h"

FlowList()
{
	headM = 0;
}
FlowList(const FlowList& source)
{
	
}
FlowList& operator= (const FlowList& rhs)
{
	
}

void insert(int year, double flow)
{
	Node* newNode = new Node;
	newNode->item.year = year;
	newNode->item.flow = flow;
	
	if(headM == 0 || headM->item.flow > flow)
	{
		headM = newNode;
	}
	else
	{
		Node* before = headM;
		Node* after = headM->next;
		
		while( flow > after->item.flow && after != 0)
		{
			after = after->next;
			before = before->next;
		}
		before->next = newNode;
		newNode->next = after;
		
	}
}
