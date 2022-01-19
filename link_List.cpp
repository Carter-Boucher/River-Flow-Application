/* 
* Completed by: Carter Boucher
* File Name: link_List.cpp
* Completed by: Carter Boucher
* Submission Date: November 25, 2021
* version 1.9
* since 1.0
*/

#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

#include "link_List.h"
#include "main.h"

FlowList::FlowList(){
    head = 0;
    data = 0;
}
void FlowList::set(int year, double flow){
    if(head == 0){
        data = new Node;
        head = data;
        data->item.year = year;
        data->item.flow = flow;
    }
    else{
        data->next = new Node;
        data = data->next;
        data->item.year = year;
        data->item.flow = flow;
    }
    data->next = 0;
}
void FlowList::sort(){
    Node *x = head;
    Node *y = head;
    Node *z = head;
    while(x != 0){
        while(y != 0){
            if(x->item.year > y->item.year){
                z = y;
                y = y->next;
            }
            else{
                z = x;
                x = x->next;
            }
        }
        if(x != 0){
            z->next = x;
            x = x->next;
            z->next->next = 0;
        }
        else{
            z->next = 0;
        }
    }
}
void FlowList::next(){
    data = data->next;
}
void FlowList::insert(int year, double flow){
    Node *x = head;
    Node *y = head;
    Node *z = head;
    while(x != 0){
        if(x->item.year == year){
            x->item.flow = flow;
            return;
        }
        else if(x->item.year > year){
            z = x;
            x = x->next;
        }
        else{
            z = y;
            y = y->next;
        }
    }
    if(x == 0){
        z->next = new Node;
        z->next->item.year = year;
        z->next->item.flow = flow;
        z->next->next = 0;
    }
}
double FlowList::getFlow() const{
    return data->item.flow;
}
void FlowList::reset(){
    Node *x = head;
    Node *y = head;
    while(x != 0){
        y = x;
        x = x->next;
        delete y;
    }
    head = 0;
}
int FlowList::getYear() const{
    return data->item.year;
}
void FlowList::destroy(){
    if(data == head){
        head = head->next;
        delete data;
    }
    else{
        curr = head;
        while(curr->next != data){
            curr = curr->next;
        }
        curr->next = data->next;
        delete data;
    }
}