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
    
    //* Actual logic starts now
    void processing() {
        int cycleCount = 0;
        Process* current = head;
        while (head) {
            cout << "Cycle " << cycleCount++ << ": Running process " << current->processID << " with remaining time " << current->remainingTime << endl;
            current->remainingTime -= timePerCycle;
            if (current->remainingTime <= 0) {
                cout << "Process " << current->processID << " completed" << endl;
                removeProcess(current);
            }
            current = current->next;
        }
        cout << "Cycle " << cycleCount++ << ": Running process " << current->processID << " with remaining time " << current->remainingTime << endl;
        current->remainingTime -= timePerCycle;
        if (current->remainingTime <= 0) {
            cout << "Process " << current->processID << " completed" << endl;
            removeProcess(current);
        }
    }

};

//* Not satisfied with output yet
//! P2 IS GOING IN NEGATIVE
int main() {
    ProcessScheduler scheduler(3); // 2 units of CPU time per cycle
    scheduler.addProcess("P1", 5);
    scheduler.addProcess("P2", 7);
    scheduler.addProcess("P3", 3);
    scheduler.processing();
}

//TODO Show the state of the system after each cycle.
//TODO Optional Task