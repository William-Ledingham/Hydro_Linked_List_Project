

#ifndef HYDRO_H
#define HYDRO_H

void displayHeader();
void display();
double average();
double median();
int readData(FlowList& list);
int menu();
void addData(FlowList& materList);
void removeData(FlowList& masterList);
void saveData(FlowList& masterList);
void pressEnter();




#endif