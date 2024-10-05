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

    unsigned long exponentiation(unsigned long base, unsigned long exp, unsigned long mod) {
        unsigned long result = 1;
        base = base % mod;
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % mod;
            }
            exp = exp >> 1;
            base = (base * base) % mod;
        }
        return result;
    }
};

bool millerRabin(LinkedList &bigNum) {
    unsigned long mod = bigNum.mod(1000000007); // Large prime number for the modulus

    // Formulae according to the Miller-Rabin algorithm Wikipedia article
    if (mod <= 1 || mod == 4) {
        return false;
    }
    else if (mod <= 3) {
        return true;
    }

    unsigned long d = mod - 1;
    int r = 0;

    while (d % 2 == 0) {
        d /= 2;
        r++;
    }

    for (int i = 0; i < 5; i++) {
        unsigned long a = 2 + rand() % (mod - 4);
        unsigned long x = bigNum.exponentiation(a, d, mod);

        if (x == 1 || x == mod - 1) {
            continue;
        }

        bool prime = false;
        for (int j = 0; j < r - 1; j++) {
            x = (x * x) % mod;
            if (x == mod - 1) {
                prime = true;
                break;
            }
        }
        if (!prime) {
            return false;
        }        
    }
    return true;
}

int main() {
    LinkedList checkForPrime;
    checkForPrime.append(17014118);
    checkForPrime.append(3460469);
    checkForPrime.append(23173);
    checkForPrime.append(1687303715);
    checkForPrime.append(884105727);
    //* 4294967295 is the largest possible number that can be added

    if (millerRabin(checkForPrime)) {
        cout << "The number is prime";
    }
    else {
        cout << "The number is not prime";
    }
}