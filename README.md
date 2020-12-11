# Process-Scheduling--OperatingSystem
using Two level queue 1.: Fixed priority premmptive Scheduling 2.Round Robin Scheduling


Design a scheduling program to implements a Queue with two levels:
Level 1: Fixed priority premmptive Scheduling
Level 2:Round Robin Scheduling


SCHEDULING PROCESS:
1.Firstly,all the processes are arrived into the ready queue. now the process is selected which has high priority which is (0) and decreases with increase.
2.Selected process is entered into fixed priority premmptive Scheduling process in which the process is executed until a process with higher priority process enters.
3.if a process with higher priority than the current process is entered then the current process is moved to Round Robin Scheduling.
4.After all the process in Fixed priority Scheduling process are completed then the execution of the( level 2 queue )round robin scheduling process starts in which every process executes until the quantum time is completed. Here, quantum time is 2


EXPLANATION OF TECHNIQUE :
Code implemented in C++11 language.
1.The attributes of each Process are stored in Class Process having burstTime , arrivalTime and priority as there members of the Class Process.
 2.Fixed Priority premmtive Scheduling is implemented using min heap where it checks the priority of each process are gives the process with high priority(0) at the top of the queue.
3.Round Robin Scheduling is implemented with the help of queue in which after completion of each process until quantum time the process is push_back() of the the queue until it is completely executed.
4.the display() function is used to display the execution of fixed priority scheduling. the emtpyv3() function is used to display the execution of the round robin scheduling.
5.dynamic arrays vectors(C++ STL) are used to store the processes .

ALGORITHM:
1.All the process are taken as input and stored in the queue.
2.Then they are sorted according to the arrival time.
3.now the process which arrives first is entered the min heap(fixed priority scheduling) and then executes.
4.repeat the steps  until the ready queue is empty:
i.	New process from the ready queue is entered into level 1 queue and compare the priority of the current with it’s priority.
ii.	If the current process has low priority move the process to level 2 queue.
iii.	Now the min heapification takes place in the level 1 queue to gets process with the higher priority at the top.
			[end of step 4 while loop]
5.Execution of the level 2 queue begins after the level 1 queue is empty.
6.repeat the steps until the  queue 2 is empty:
     i . In  level 2 the first process which enters gets executed until quantum time.
    ii. if still it has burst time then it is push back in the queue
    iii.	if its burst time is completed then it is terminated.
		[end of step 6 while loop]

COMPLEXITY:
1.sorting :O(nlogn)
2.priority queue : creation O(nlogn) , min heapify O(logn)
3.Fixed priority premmptive scheduling : O(n)
4.Round Robin Scheduling : O(nm)
Where m is the no of times each process in queue 2 gets divided
Best Case : O(nlgn)
Average Case : O(nlgn)
Worst Case : O(n^2) where m=n as each process gets divided into n times
