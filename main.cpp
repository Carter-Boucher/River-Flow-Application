/* 
* Completed by: Carter Boucher
* File Name: main.cpp
* Completed by: Carter Boucher
* Submission Date: November 25, 2021
* version 1.9
* since 1.0
*/

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
using namespace std;

#include "main.h"
#include "link_List.h"

void displayHeader() {
    cout << "Flow Application" << endl;
    cout << "Version: 1.9" << endl;
    cout << "Produced by: Carter Boucher" << endl;
    cout << "<<<Press Enter to Continue>>" << endl;
}
int readData(FlowList &list) {
    ifstream inFile;
    inFile.open("data.txt");
    if (!inFile) {
        cout << "Error opening file" << endl;
        return 1;
    }
    int year;
    double flow;
    int count = 0;
    while (inFile >> year >> flow) {
        list.insert(year, flow);
        count++;
    }
    inFile.close();
    return count;
}
int menu(){
    int choice;
    cout << "Please select on the following operations" << endl;
    cout << "   1.  Display flow list, and the average" << endl;
    cout << "   2.  Add data" << endl;
    cout << "   3.  Save data" << endl;
    cout << "   4.  Remove data" << endl;
    cout << "   5.  Quit" << endl;
    cout << "Enter your selection: ";
    cin >> choice;
    return choice;
}
void display(int count, FlowList &list) {
    cout << "Year       Flow (in billions of cubic meters" << endl;
    cout << "--------------------------------------------" << endl;
    for(int x = 0; x < count; x++) {
        cout << list.getYear() << "            " << list.getFlow() << endl;
    }
    cout << "The average is: " << average(count, list) << " billions cubic meters" << endl;
}
int addData(int count, FlowList &list) {
    int year;
    double flow;
    cout << "Enter the year: ";
    cin >> year;
    cout << "Enter the flow: ";
    cin >> flow;
    list.insert(year, flow);
    count++;
    return count;
}
int removeData(int count, FlowList &list) {
    int year;
    cout << "Enter the year: ";
    cin >> year;
    for(int x = 0; x < count; x++) {
        if(list.getYear() == year) {
            list.destroy();
            cout << "Data removed" << endl;
            return count - 1;
        }
    list.next();
    }
    cout << "Data not found" << endl;
    return count;
}
double average(int count, FlowList &list) {
    int sum = 0;
    for(int x = 0; x < count; x++) {
        sum += list.getFlow();
    }
    return sum / count;
}
void saveData(int count, FlowList &list) {
    ofstream outFile;
    //outFile.open("/filepath/filename.txt");
    outFile.open("/Users/carterboucher/Desktop/School/Fall 2021/ENSF337/Flow_Application/flow.txt");
    if (outFile.fail()) {
        cout << "Error opening file" << endl;
        exit(1);
    }
    for(int x = 0; x < count; x++) {
        outFile << list.getYear() << " " << list.getFlow() << endl;
    }
    outFile.close();
}
void pressEnter() {
    cout << "<<<Press Enter to Continue>>" << endl;
    //cin.ignore();
    cin.get();
}
int main(void) {
    FlowList x;
    int numRecords;
    displayHeader();
    numRecords = readData(x);
    int quit = 0;
    while(1) {
        switch(menu()){
            case 1:
                display(numRecords, x);
                pressEnter();
                break;
            case 2:
                addData(numRecords, x);
                pressEnter();
                break;
            case 3:
                saveData(numRecords, x);
                pressEnter();
                break;
            case 4:
                removeData(numRecords, x);
                pressEnter();
                break;
            case 5:
                cout << "\nProgram end\n";
                quit = 1;
                break;
            default:
                cout << "\nNot a valid input.\n" << endl;
                pressEnter();
        }
    if(quit == 1) {
        break;
    }
    }
    return 0;
}