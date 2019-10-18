Documentation:

This program will create seventeen child processes to run. Same with part 3 of the lab, the limitations are that there cannot be any single process which creates children to create less than two child processes, or more than three. In other words, the program you write can only launch a maximum of three child processes directly, and any other “children” will have to be created by the children of this parent process (subject to the restriction of only creating two or three processes each).

How it works:

The tree diagram: The c represents the first parent process, and the o's represents the child process that are called through the fork() function. The numbers represents the childnum variable that we will use to keep track of the child nodes.

Level 0:					c

Level 1:		(1)			(2)			(3)

Level 2:	(2)	(3)	(4)	(3)	(4)	(5)	(4)	(5)	(6)

Level 3:  o  o	o						    o  o

To create this program, it would be easier if I create a separate function that does the process of creating nodes. This is important because I won't always be adding 3 child nodes, as the 17 child objective dictates that one node in level 2 will only have 2 children. I first create two variables childnum and level; childnum will be used to keep track of the various nodes the tree and designate them a number, and level will be used to see what level of the tree the nodes are at. I then create the function maken(int n) which takes in one parameter n that determines the amount of nodes needed to me created. inside the maken function, I create a for loop that takes in parameter n as the number of times that the function will loop. Inside the for loop we will increment childnum, so that for each 3 child nodes that are created, the values inside them will be incremented by one. This is important because in the end we can find the nodes that we need to add the last 5 child nodes in the bottom level. After incrementing the childnum, we then use the fork() == 0 to create child nodes, and then print the parentID(ppid) and the child's ID(pid). If fork() != 0, then the function will wait for the parent. This completes the maken function that we will use in the main.

Inside the main, we can call maken(3) to create the first three nodes of level 1, and then increment the level. Inside the if statment, we then call maken(3) again to create all the nodes in the second level, which we follow up by incrementing level again. Now the value of level is at 2, and there are 12 nodes in total filling up all the possible spaces in the tree diagram. Finally, we must check to see the values of childnum; if the value of childnum is 2 or 6, then the nodes will be added to them. This is due to the fact that the childnum value of 2 and 6 are unique in level 2, and it makes it easier to find the two nodes needed to add the nodes in level 3. If the value of child num is 2, then we call maken(3) to create the three final child nodes in level 3, and if the childnum is 6, then we create the two final child nodes in level 3. We then return 1 and the main function is completed.

How to test:

To run the program in terminal, I type "gcc p4.c -std=c99 -o ./a.out" to compile the program to the a.out output file, and then run the results by typing ./a.out. The results will be displayed on the screen. It is important to include the -std=c99 because it is required to operate the for loop in the code.
