/* 
* Completed by: Carter Boucher
* File Name: main.h
* Completed by: Carter Boucher
* Submission Date: November 25, 2021
* version 1.9
* since 1.0
*/

#ifndef HYDRO_H
#define HYDRO_H
#include "link_List.h"

void displayHeader();
// Displays the header of the program

int readData(FlowList& data);
// Reads the data of years and flow from input file, inserts them into the list, and returns the number of records on file

int menu();
// Displays the menu and returns the user's choice

void display(int a, FlowList& data);
// Displays the list of years and flow and shows the average flow

int addData(int b, FlowList& data);
// prompts the user for a year and flow, inserts the data into the list, and updates the number of records on file

int removeData(int b, FlowList& data);
// prompts the user for a year, removes the record from the list, and updates the number of records on file

double average(int a, FlowList& data);
// returns the flow average in the given list

void saveData(int a, FlowList& data);
// opens the input file for writing, writes the data from the list to the file, and closes the file

void pressEnter();
// diplays <<<Press Enter to Continue>>> and waits for the user to press enter
#endif