Documentation:

This program generates a basic shell program like the one seen in the COEN 177 lecture. The program should take in user input and should terminate if the user inputs the word "exit". 


How it works: 

The program uses a character array to take in an input from the user using stdin. To do this, I first create a char array input and make the pointer point to nullptr. After that, I create a length variable and set the value to 0. I will need this when I call the getline function later. 

For the next part, I will be writing the main function. I first create a while loop with parameter set to always true, so that the program will not exit until the user types exit. To get the user input from stdin, I use the function getline, which takes in the line from stream, along with its length. In this case, the File stream is the stdin, which is the keyboard. The interesting part of the getline function is that getline stores the string with a newline character (ie. exit -> exit\n\0 which returns exit \n). To remove the newline so that the input can be correctly compared to the "exit" command, I search to see that if the final character in the string is the character \n, I replace it with \0. That should resolve the newline issue.

After that, I use strcmp to compare the string stored in the array to the string "exit" which we will use to quit the program. If the value returned from strcmp() is 0 (which means the two strings are equal), then the program quits.

The next part uses fork() to create a child process, and executes the child process if it is within the child. Otherwise, it will just wait for the parent.

Finally, I free the contents of the input and set the pointer to null so that there would be no memory leaks.


How to test:

To run the program in terminal, I type "gcc main.c -o ./a.out" to compile the program to the a.out output file, and then run the results by typing ./a.out. The results will be displayed on the screen. To test the program, you can type anything you want and press enter, and the program will continue running. However, the moment the program reads in the word "exit" when I press enter, then the program will immediately quit.
