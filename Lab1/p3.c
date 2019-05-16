#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int arc, char *argv[])
{
	int count = 0;
	for(int i = 0; i < 3; i++)
	{
		//Creates a child node and prints its parent id and id's
		if(fork() == 0)
		{
			printf("parentid = %d, myId = %d\n", getppid(), getpid());
			count++;
			
			//Checks to see whether the tree is on the last level
			if(count == 1)
			{
				i = -1;
			}
			else
			{
				break;
			}
		}
		else
		{
			int status;
			waitpid(-1, &status, 0);
		}
	}
}

