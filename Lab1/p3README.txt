Documentation:

This program will create a total of twelve child processes to run. However, the limitations of this program is that each parent cannot have less than two child processes and more than three child processes. In other words, the program you write can only launch a maximum of three child processes directly, and any other “children” will have to be created by the children of this parent process (subject to the restriction of only creating two or three processes each).

How does it work:

The tree diagram: The c represents the first parent process, and the o's represents the child process that are called through the fork() function.

Level 0:					c

Level 1:		o			o			o

Level 2:	o	o	o	o	o	o	o	o	o

The main objective of this part of the lab is that we have to make sure that for level 0 and level 1, I have to make each child node create 3 children, and for level 2, I have to make sure that all nodes do not create children. To do this, I create a int variable count in order to count the levels of the tree diagram. I then create a for loop which allows me to create the 3 nodes, and then forking through each iteration to create child nodes. If fork() != 0, we then use the status variable and waitpid function to wait for the parent. Inside the fork() == 0 childs, we print the parentID(ppid) and the child's ID(pid). We then increment count, and if the count is equal to 1, which means the tree is at level 1, we continue to make children for the next level. However, when the process reaches level 2, we want the level 2 nodes to stop making children, so we break the loop. 

How to test:

To run the program in terminal, I type "gcc p3.c -std=c99 -o ./a.out" to compile the program to the a.out output file, and then run the results by typing ./a.out. The results will be displayed on the screen. It is important to include the -std=c99 because it is required to operate the for loop in the code.
