Documentation:

This program creates eight child programs with the limitation of me not being allowed to create more that two child processes per parent node.

How it works:

The basic diagram: The c represents the first parent process, and the o's represents the child process that are called through the fork() function.

c-o-o-o-o-o-o-o-o

To create this diagram I can just create a for loop that loops 8 times, and for each time the function uses fork() to create a child function, and then prints the parentID(ppid) and the child's ID(pid). Otherwise, if the fork() != 0, then the process will wait for the parent. When the loop finishes creating the eigth node, the increment to the i value will cause the value of i to be greater than 8, which will cause the loop to exit.  

How to test:

To run the program in terminal, I type "gcc p2.c -std=c99 -o ./a.out" to compile the program to the a.out output file, and then run the results by typing ./a.out. The results will be displayed on the screen. It is important to include the -std=c99 because it is required to operate the for loop in the code. I will also need the -std=c99 for part 3 and 4 of the lab.
