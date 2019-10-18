Documentation for Lab 2:

Objective: The objective of this lab is to familiarize ourselves with modifying and testing the operating system kernel,
and generally familiarize ourselves with the kernel environment using minix. In this lab, we will be adding a print 
statement to the copyright program of the MINIX startup banner. After that, we will modify the process scheduling algorithm
in the kernel so that we can skew the priority scheduling.

Part 1:

Thought Process:

Since the objective for the first part of the lab is pretty straight forward, we can just find the minix source code that prints
the copyright statement and then add a print statement so that when we run the minix bootup program, the statement will show.

How I changed it:

To do this we first have to get access to the minix bootup file. We first type setup minix and vmware& to open up the minix
IDE. We can access this window again in the future by typing get-minix-image in terminal. After we open up the minix virtual
display, the bootup process begins. When the login screen appears, we enter 'root' as our username. We then cd .. out and into
the main directory, where we can access the kernel with the command cd usr/src/kernel. After that we use the ftp command 
(ftp ftp.engr.scu.edu) to generate the files for the main.c and the proc.c. Inside the ftp interface, we login with our SCU
login, and then use the put command (put main.c & put proc.c)to transfer the files to our Documents which we can access in
the terminal.

Inside the terminal, I located the file and opened it with vim. The copyright statement should be located under the announce
section of main.c. I then added a print statement "I HAVE MODIFIED IT" at the end. Thus, the objectives of Part 1 is completed.

How I tested it:

To test the code, we go back to the minix interface that we used, and use the get main.c command under ftp to transfer the file.
Then we can exit ftp which takes us back to the kernel file. We then cd .. back into the source file (src) and run the command
'make world', which will rebuild and install the operating system. When the process is done, we run the command "reboot" to
restart the minix boot up process. The print statement we added to the copyright statement should be visible. Thus, part 1 of
the lab is complete.

Part 2:

Thought Process:

The objective of part 2 of the lab is to modify the proc.c file that we transferred in part 1 of the lab so that the minix bootup
process will be slower. We do this by changing the process scheduling algorithm such that there is a selection of a lower
priority job.

How I changed it: We use vmware& to access the minix interface if we haven't already, and then go through the same process as in 
Part 1 so we are in the kernel file. Inside the kernel, we call the ftp command mentioned above so that we can transfer over
the proc.c file that we have to modify into the terminal. We use vim to open up the proc.c file so that we can make modifications.

Looking through the proc.c file, we come across a specific segment of the code called "pick_proc". The main function of pick_proc
is to select the next process to run. The default is set so that the process with the highest priority will run next, and we want
to modify it so that the processes with lower priority will run. Since the q variable is the one that will iterate through the
queues it is the one that we want to change so that a process with lower priority will be selected. Within the for loop where the
q iterates through the number of scheduled queues (NR_SCHED_QUEUE), we make an if statement with the conditions q > 3 and
rand() % 10 > 8. The q > 3 makes such that the processes with the highest priorities aren't changed, and the rand() function makes
it so that there is only a 1 in 10 chance that the q value is modified. This works because rand() % 10 gives a pseudorandom value
between 0 and 9, and by making it > 8 leaves only 9 as the available input for the function to be true. Inside the condition 
statement, we set q to the value of rand % (NR_SCHED_QUEUE - q). This statement rand function so that it modulous the difference
up to the value of NR_SCHED_QUEUE. 

How I tested it: 

To test the code, we use the same process that we have used to test Part 1 of the Lab. We go back to the minix interface that
we used, and use the get proc.c command under ftp to transfer the file. Then we can exit ftp which takes us back to the kernel
file. We then cd .. back into the source file (src) and run the command 'make world', which will rebuild and install the operating
system. When the process is done, we run the command "reboot" to restart the minix boot up process. If we see that the reboot
process is significantly slower (my bootup process took ~23 seconds), then the objective is achieved, and part 2 of the lab is complete.
