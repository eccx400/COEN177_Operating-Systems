#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Eric Cheng
// COEN 177L
// 
int main(int arc, char *argv[])
{
	//Creates a for loop to make 8 child nodes
	for(int i = 0; i < 8; i++)
	{
		//Creates a child node and prints its parent id and id's
		if(fork() == 0)
		{
			printf("parentid = %d, myId = %d\n", getppid(), getpid());
		}
		else
		{
			int status;
			waitpid(-1, &status, 0);
			break;
		}
	}
}
