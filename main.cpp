#include <iostream>
#include <vector>
#include <chrono>
#include <iomanip>
#include <list>

#include "LinkedList.h"
using namespace std;



void Vector_Delete(int num_items)
{
    int i = 0;
    vector <int> numbers;
    //Populate std vec w/ 10,000 entries
    for (i = 0; i < num_items; i++){
        numbers.push_back(i);
    }
        
    //Time the delete function
    auto start = chrono::high_resolution_clock::now();

    auto it = numbers.begin();
    while (it != numbers.end()) {
        it = numbers.erase(it);
    }

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program. 
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time in sec.
    time_taken *= 1e-9;

    cout << fixed << time_taken << setprecision(9);
    cout << ",";
}

void LinkedList_Delete(int num_items) {
    int i = 0;
    LinkedList<int> numbers;
    //Populate std vec w/ 10,000 entries
    for (i = 0; i < num_items; i++) {
        numbers.appendNode(i);
    }

    //Time the delete function
    auto start = chrono::high_resolution_clock::now();

    for (i = 0; i < num_items; i++) {
        numbers.deleteNode(i);
    }

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program. 
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time in sec.
    time_taken *= 1e-9;

    cout << fixed << time_taken << setprecision(9);
    cout << ",";
}

void Stl_Delete(int num_items) {
    int i = 0;
    list<int> numbers;
    for (i = 0; i < num_items; i++) {
        numbers.push_back(i);
    }

    //Time the delete function
    auto start = chrono::high_resolution_clock::now();

    auto it = numbers.begin();
    while (it != numbers.end()) {
        it = numbers.erase(it);
    }

    auto end = chrono::high_resolution_clock::now();

    // Calculating total time taken by the program. 
    double time_taken =
        chrono::duration_cast<chrono::nanoseconds>(end - start).count();
    // time in sec.
    time_taken *= 1e-9;

    cout << fixed << time_taken << setprecision(9);
    cout << ",";
}



int main(int, char**) {
    cout << "num_items,vector,linkedList,stlList" << endl;
    for (int i = 1000; i <= 10000; i += 1000) {
        cout << i << ",";
        Vector_Delete(i);
        LinkedList_Delete(i);
        Stl_Delete(i);
        cout << endl;
    }

    return 0;
}
