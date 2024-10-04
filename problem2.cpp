#include <iostream>
using namespace std;

struct Node { // Definining a structure to represent a 32-bit section of the number
    unsigned long data;
    Node* next;

    Node(unsigned long value) { // Constructor for the structure
        data = value;
        next = nullptr;
    }
};

class LinkedList {
private:
    Node* head;
    Node* tail;
    int nodeCount;

public:
    LinkedList() { // Constructor for the linked list
        head = nullptr;
        tail = nullptr;
        nodeCount = 0;
    }

    void append(unsigned long value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            tail = newNode;
        }
        nodeCount++;
    }

    unsigned long mod(unsigned long modFactor) {
        Node* current = head;
        unsigned long result = 0;
        while (current) {
            //! USING BINARY SHIFT CAUSES AN ERROR EVEN THOUGH THE PROGRAM RUNS
            result = (result * 4294967296 + current->data) % modFactor; // Shifting bits by 32 
            current = current->next;
        }
        return result;
    }
};

bool millerRabin(LinkedList &bigNum) {
    unsigned long nMod = bigNum.mod(1000000007); // Large prime number for the modulus
    //* Watch vid on this
    return true;
}

int main() {
    LinkedList checkForPrime;
    checkForPrime.append(12345);
    checkForPrime.append(12345);
    checkForPrime.append(12345);

    bool isPrime = millerRabin(checkForPrime);

}

//TODO Miller-Rabin primality test
//TODO use unsigned long for 32-bit numbers
//TODO add binary shift error in readme