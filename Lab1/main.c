#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

 // Eric Cheng
 //COEN 177L
 //
 //This code creates a unix shell that takes input from user
 //and doesn't stop executing until they type exit. Do do this
 //the input characters are taken from standard input, and 
 //stored in the input array along with its length using
 //getline. I then use strcmp, a C function, to check whether
 //or not the user input is "exit", and if it is, the function
 //quits.
int main(int argc, char *argv[]) 
{
	//This is the array that will hold the user input
	char *input = NULL;
	size_t length = 0;

	//user has not typed exit (always true)
	while(1)
	{
		//input = get_user_input();
		//Taken from stdin, which is a 
		//basic input from the keyboard
		getline(&input, &length, stdin);

		//removes the newline at the end
		//of the getline since strlen stores
		//the character with a newline character
		//(ie. exit -> exit\n\0 which returns
		//exit\n)
		if(input[strlen(input) - 1] == '\n')
		{
			input[strlen(input) - 1] = '\0';
		}

		//Checks to see if the user input
		//is exit; If it is, the program
		//quits
		if(strcmp(input, "exit") == 0)
		{
			return 0;
		}		

		if(fork() == 0)
		{
			//child code
			execve(input, NULL, 0);
			break;
		}
		else
		{
			//parent code
			int status;
			waitpid(-1, &status, 0);
		}
		free(input);
		input = NULL;
	}
	return 0;
}
