

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
	
	int insert(int year, double flow);
	int remove(int year);
	double average()const;
	double median()const;
	void display()const;
	void saveToText(const char* filename)const;
	
	private:
	Node* headM;
	int n_years;
	
	void destroy();
	void copy(const FlowList& source);
};

#endif