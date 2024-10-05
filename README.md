https://github.com/qasimahmed06/DSA_Assignment_1/

## Problem 1: Simple Process Scheduling Algorithm
https://github.com/qasimahmed06/DSA_Assignment_1/blob/final/problem1.cpp

### Approach
I decided to use a circular linked list with nodes corresponding to processes. The list is traversed in a round-robin fashion to iterate through each process.

A fixed CPU "clock speed" is set, which can be changed by modifying the sole argument of the `ProcessScheduler` constructor. Then, for each process, the "clock speed" is deducted from the total time required from each process in parallel. This simulates a CPU performing multiple processes with pipelining. If the remaining time becomes zero or negative, the node of the process is removed from the list and then deleted from memory.

The program simulates the dynamic arrival of a new process during the scheduling process. Although a new process is added in the third cycle in my code, this can be easily modified by simply changing the `4` in line 82, i.e., `if (cycleCount == 4) {` to one more than the desired number.

### Assumptions
- All processes have equal priority.
- There will be at least one process in the linked list.
- The processing speed cannot be modified once the actual processing starts.

### Challenges faced
- During debugging, `P2` was going in negative for an, at the time, unknown reason.
	- This happened because the process was not immediately removed from the list when its remaining time became zero and instead, continued in the next cycle.
	- I fixed this by modifying the check at line 93, i.e., `if (current->remainingTime <= timePerCycle) {` to make sure the process is removed.
- Initially, I had one singular `if` condition to check for a completing process followed by an `else if` condition to check for a continuing process.
	- This was a major flaw as it meant that one block would be skipped entirely so the output could be completely different.
	- I fixed this by making two separate `if` conditions.
- The processing was not parallel at first and was doing each process one by one.
- It is not possible to add a new process with `addProcess()` after calling the `processing()` function so I simulated a new process artificially within the `processing()` function.
	- This is more a limitation than an oversight.

### Output
```
ProcessScheduler scheduler(2); // CPU "clock speed"
scheduler.addProcess("P1", 5);
scheduler.addProcess("P2", 7);
scheduler.addProcess("P3", 3);
scheduler.addProcess("P4", 12);
scheduler.processing();
```

![image](https://github.com/user-attachments/assets/64dcd3db-d5e1-4e4e-a38b-7ff00845834d)

```
ProcessScheduler scheduler(4); // CPU "clock speed"
scheduler.addProcess("P1", 11);
scheduler.addProcess("P2", 6);
scheduler.addProcess("P3", 22);
scheduler.processing();
```

![image](https://github.com/user-attachments/assets/b33b1ee8-1616-40b3-9ecb-0973a5d5fac1)

## Problem 2: Very Large Prime Number Calculation
https://github.com/qasimahmed06/DSA_Assignment_1/blob/final/problem2.cpp

### Approach
I decided to use a linked list to store our very large number, with each node holding 32 bits of the number. The primality test I used is the [Miller-Rabin primality test]([url](https://en.wikipedia.org/wiki/Miller%E2%80%93Rabin_primality_test)).

The modulus to be used in this test is supposed to be a large prime number, so I chose 1,000,000,007 as it is a commonly used number in computational problems like this one. To simulate the addition of each node's data to that of the next node, I multiplied the result of the modulus by 4,294,967,296 which is 2^32. This is because it simulates a bit shift of 32 bits.

I made two functions for modular exponentiation and calculated the values of `d`, `r`, and `a` according to the given formulae. Finally, I made a main function to enter a very large number to check if it is prime or not using the `append()` function.

### Assumptions
- There can be no negative numbers in any node of the linked list.

### Challenges faced
- No node of the linked list can hold a value greater than 4,294,967,295.
- I had to use `unsigned long` instead of `long`.
	- This is because a `long` holds negative values as well.
	- As we assumed there will be no negative values in our list, we used an `unsigned long`.
 	- This gives us double the positive values that can be used.
- Writing this README was a challenge in and of itself.
- `1ULL` for binary shift was giving an error.
	- This was due to type limitations.
 	- I fixed this by multiplying with 2^32
- My program does not have a way to tell if a number less than 1,000,000,007 is prime.
	- The program could be modified by including implementation of this for a more universal prime number checker.

### Output
