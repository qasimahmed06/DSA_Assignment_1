#include <iostream>
using namespace std;

struct Node { // Definining a structure to represent a 32-bit section of the number
    long data;
    Node* next;

    Node(long value) { // Constructor for the structure
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

    void append(long value) {
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

    long mod(long modFactor) {
        Node* current = head;
        long result = 0;
        while (current) {
            //! USING BINARY SHIFT CAUSES AN ERROR EVEN THOUGH THE PROGRAM RUNS
            result = (result * 4294967296 + current->data) % modFactor; // Shifting bits by 32 
            current = current->next;
        }
        return result;
    }
};

bool millerRabin(LinkedList &bigNum) {
    long nMod = bigNum.mod(4294967311); // Closest prime to 2^32 for the modulus
    //* Watch vid on this
}


//TODO Miller-Rabin primality test
//TODO use long for 32-bit numbers
//TODO add binary shift error in readme