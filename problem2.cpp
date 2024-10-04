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
};


//TODO Miller-Rabin primality test
//TODO use long for 32-bit numbers