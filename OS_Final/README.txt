In this project, I will be looking at the disk scheduling algorithms, specifically First Come First Serve (FCFS), Shortest Seek Time First(SSTF), and the Elevator Algorithm (SCAN). Finding the Seek Time is important because the seek time determines the inefficiencies of the algorithm, and the algorithm with the lower seek time usually it is more efficient for disk scheduling and serving new requests. So my question is: comparing FCFS, SSTF, and SCAN algorithms, which algorithm is most efficient by looking at their seek time? 

The first Algorithm was the The First Come First Serve (FCFS) algorithm. This algorithm uses the First Come First Serve variation that we have encountered in the page replacement algorithms in which we find the page faults, and the incoming processes will be placed at the back of the queue. To code this algorithm, I had to make sure that the jobs are serviced in only a single direction. The algorithm is simple to implement, however. To implement the FCFS algorithm, I summed the seekTime with all the values of the difference between the head Position (headPos) and the next item in the queue. I must use absolute values because the distance must always be positive, no matter which direction the headPos is going. This is the sum of the distances the head has to move in the track. For each movement, we then move the headPos to the index on the queue we had just visited. We can then print the total seek time.

The second Algorithm we had to analyze was the the Shortest Seek Time First (SSTF) Algorithm. The Shortest Seek Time First algorithm checks to see which job is closest to the head Position (with the minimal seek time) and then finds the distance between them. To do this, we must first calculate the seek times in the job queues to find the job with the shortest seek time so we know which job to execute next. For the coding aspect, I first had to create a array checkDis to order the distances between the job by finding the absolute value of the distance between the headPos and the job in the queue, which we complete using a for loop which iterates through the whole queue containing the jobs, and then store it in checkDis. We then loop through queue and checkDis and then compare the values at the same index to find the shortest seek time, and then we can replace the values for both of them by using a temp variable. Finally, after all the seek times have been calculated, we can then loop through and complete our algorithm.

The final Algorithm we will analyze is the Elevator algorithm, also known as the SCAN algorithm. The SCAN algorithm starts from the head position and moves in one direction, reading each job and finding the seek distance until it reaches the end of the disk, and then it moves back in the other direction and reads the remaining job. We use the variable i in the for loop to move in one direction, while we use the variable j to make sure that it reaches the end of the disk on one side. We read the seek time by finding the difference between the head position and the queue and sum it. We then move in the other direction and do the same, and after we finish summing all the jobs, we can then find and print the seek time.

To test the algorithms, we create a main function for the three algorithms and then run the functions accordingly. The algorithms should print out the seek Times that we can use to compare. We can then use the gcc function to compile the algorithms, and then run it to get the seek Time values.

The results are listed below for the queue containing {60, 78, 142, 37, 80, 153, 177} where the head position starts at 100 and the cylinder goes until 200.

FCFS:
Total Seek Time: 367

SSTF:
Total Seek Time: 290

SCAN:
Total Seek Time: 308

From the Total Seek Times, we can see that in this case, the SCAN elevator algorithm took the most time, followed by First Come First Serve, and finally Shortest Seek Time First with the lowest seek time, which means that in this case, it is the most efficient function for reading through the disks.
