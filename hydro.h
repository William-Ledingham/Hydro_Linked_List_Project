//hydro.h
//W. Ledingham

#ifndef HYDRO_H
#define HYDRO_H

int main(void);
void displayHeader();
void display(FlowList& masterList);
double average(FlowList& masterList);
double median(FlowList& masterList);
int readData(FlowList& list);
int menu();
void addData(FlowList& materList);
void removeData(FlowList& masterList);
void saveData(FlowList& masterList);
void pressEnter(int& pressEnterFix);

#endif