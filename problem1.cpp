#include <iostream>
using namespace std;

struct Process { // Definining a structure to represent a process
    string processID;
    int executionTime;
    int remainingTime;
    Process* next;

    Process(string id, int execTime) { // Contstructor for the structure
        processID = id;
        executionTime = execTime;
        remainingTime = execTime;
        next = nullptr;
    }
};


// TODO a fixed amount of CPU time to each process in each cycle. 
// TODO remaining_time will be reduced by that amount.
// TODO remaining_time becomes 0
// TODO process is running and its remaining time.
// TODO Show the state of the system after each cycle.
// TODO Optional Task