
https://github.com/qasimahmed06/DSA_Assignment_1/

## Problem 1
https://github.com/qasimahmed06/DSA_Assignment_1/blob/final/problem1.cpp

#### Approach
I decided to use a circular linked list with nodes corresponding to processes. The list is traversed in a round-robin fashion to iterate through each process.

A fixed CPU "clock speed" is set, which can be changed by modifying the sole argument of the `ProcessScheduler` constructor. Then, for each process, the "clock speed" is deducted from the total time required from each process in parallel. This simulates a CPU performing multiple processes with pipelining. If the remaining time becomes zero or negative, the node of the process is removed from the list and then deleted from memory.

The program simulates the dynamic arrival of a new process during the scheduling process. Although a new process is added in the third cycle in my code, this can be easily modified by simply changing the `4` in line 82, i.e., `if (cycleCount == 4) {` to one more than the desired number.

#### Assumptions
- All processes have equal priority.
- There will be at least one process in the linked list.
- The processing speed cannot be modified once the actual processing starts.

#### Challenges faced
- During debugging, `P2` was going in negative for an, at the time, unknown reason.
	- This happened because the process was not immediately removed from the list when its remaining time became zero and instead, continued in the next cycle.
	- I fixed this by modifying the check at line 93, i.e., `if (current->remainingTime <= timePerCycle) {` to make sure the process is removed.
- Initially, I had one singular `if` condition to check for a completing process followed by an `elif` condition to check for a continuing process.
	- This was a major flaw as it meant that the output could be completely different.
	- I fixed this by making two separate `if` conditions.
- converting to an elifi ^^^
- //TODO add wasn't parallel and was doing one by one
- // Can't addProcess after calling process function so just simulated one artificially. limitation more than oversight.



#### Output


## Problem 2
https://github.com/qasimahmed06/DSA_Assignment_1/blob/final/problem2.cpp
#### Approach

#### Assumptions

#### Challenges faced

#### Output




//TODO add binary shift error in readme //TODO add unsigned long for 2^32 instead of 2^16
					Type Name	Bytes	Range of Values
					long	4	-2,147,483,648 to 2,147,483,647
					unsigned long	4	0 to 4,294,967,295


//Assumption that no negative numbers

//TODO add that can't tell if prime below [find yourself] but could modif prgram to include more implementation of smaller primes for a more universal prime number checker