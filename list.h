

#ifndef LIST_H
#define LIST_H

struct ListItem {
	int year;
	double flow;
};

struct Node {
	ListItem item;
	Node* next;
};

class FlowList {
	public:
	FlowList();
	FlowList(const FlowList& source);
	FlowList& operator= (const FlowList& rhs);
	
	void insert(int year, double flow);
	
	private:
	Node* headM;
	void destroy();
	void copy(const FlowList& source);
};

#endif