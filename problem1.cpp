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

class ProcessScheduler {
private:
    Process* head;
    Process* tail;
    int timePerCycle; // Fixed amount of CPU time to each process in each cycle

public:
    ProcessScheduler(int cpu) {
        head = nullptr;
        tail = nullptr;
        timePerCycle = cpu;
    }

    void addProcess(string id, int execTime) {
        Process* newProcess = new Process(id, execTime);

        if (head == nullptr) {
            head = newProcess;
            tail = newProcess;
            tail->next = head; // For a circular linked list
        }
        else {
            tail->next = newProcess;
            newProcess->next = head;
            tail = newProcess;
        }
    }

    void removeProcess(Process* remove) {
        if (remove == head) {
            if (head == tail) {
                delete head;
                head = nullptr;
                tail = nullptr;
            }
            else {
                tail->next = head->next;
                delete head;
                head = tail->next;
            }
        }
        else {
            Process* current = head; //! NOT SURE IF THIS WHOLE BLOCK IS CORRECT
            while (current->next!= remove) {
                current = current->next;
            }
            current->next = remove->next;
            if (remove == tail) {
                tail = current;
            }
            delete remove;
        }

}

//TODO remaining_time will be reduced by that amount.
//TODO remaining_time becomes 0
//TODO process is running and its remaining time.
//TODO Show the state of the system after each cycle.
//TODO Optional Task