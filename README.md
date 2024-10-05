
https://github.com/qasimahmed06/DSA_Assignment_1/

## Problem 1
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

## Problem 2
https://github.com/qasimahmed06/DSA_Assignment_1/blob/final/problem2.cpp
### Approach

### Assumptions

### Challenges faced
- Writing this README was a challenge in and of itself.

### Output




//TODO add binary shift error in readme //TODO add unsigned long for 2^32 instead of 2^16
					Type Name	Bytes	Range of Values
					long	4	-2,147,483,648 to 2,147,483,647
					unsigned long	4	0 to 4,294,967,295


//Assumption that no negative numbers

//TODO add that can't tell if prime below [find yourself] but could modif prgram to include more implementation of smaller primes for a more universal prime number checker
