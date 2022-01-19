/* 
* Completed by: Carter Boucher
* File Name: link_List.h
* Completed by: Carter Boucher
* Submission Date: November 25, 2021
* version 1.9
* since 1.0
*/

#ifndef LINK_LIST_H
#define LINK_LIST_H

struct ListItem{
    int year;
    double flow;
};
struct Node{
    ListItem item;
    Node* next;
};
class FlowList{
    public:
    FlowList();
    void set(int year, double flow);
    //sets the year and flow of the item at the current position
    void sort();
    //sorts the list in ascending order
    void next();
    //moves the current position to the next item in the list
    void insert(int year, double flow);
    //inserts a new item at the current position
    double getFlow() const;
    //returns the flow of the item at the current position
    void reset();
    //moves the current position to the first item in the list
    int getYear() const;
    //returns the year of the item at the current position
    void destroy();
    //deletes all the items in the list
    private:
    Node *head, *data, *curr;
};
#endif