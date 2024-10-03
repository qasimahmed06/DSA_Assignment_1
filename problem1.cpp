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
            Process* current = head;
            while (current->next!= remove) {
                current = current->next;
            }
            current->next = remove->next;
            if (remove == tail) {
                tail = current;
            }
            delete remove; // Good memory management
        }
    }
    
    // CPU scheduler
    void processing() {
        cout << "\n"; // Pretty printing
        int cycleCount = 1;
        Process* current = head;
        while (head) {
            cout << "Cycle " << cycleCount << ": Running process " << current->processID 
                 << " with remaining time " << current->remainingTime << endl;

            if (current->remainingTime <= timePerCycle) { // If the process will complete in the next cycle
                cout << "Process " << current->processID << " completed.\n\n";
                Process* toDelete = current;
                current = current->next;

                removeProcess(toDelete);
                
                if (!head) { // No more processes 
                    break; // End the processing cycle
                }

            }
            else {
                current->remainingTime -= timePerCycle;
                cout << "Process " << current->processID << " has remaining time "
                     << current->remainingTime << "\n\n";
                current = current->next;
            }

            cycleCount++;
        }
    }
};

int main() {
    ProcessScheduler scheduler(2); // CPU "clock speed"
    scheduler.addProcess("P1", 5);
    scheduler.addProcess("P2", 7);
    scheduler.addProcess("P3", 3);
    scheduler.addProcess("P4", 12);
    scheduler.processing();
}

//TODO Optional Task
//TODO possibly add the P2 going in negative in the readme