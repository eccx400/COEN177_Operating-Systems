#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int childnum = 0;
int level = 0;

int maken(int n)
{
	for(int i = 0; i < n; i++)
	{	
		childnum++;
		if(fork() == 0)
		{
			//print stuff
			printf("parentid = %d, myId = %d\n", getppid(), getpid());
			return 1;
		}
		else
		{
			int status;
			//waitpid
			waitpid(-1, &status, 0);
		}
	}
	return 0;
}


int main(int arc, char *argv[])
{
	if(maken(3))
	{
		level++;
		if(maken(3))
		{
			level++;
			if(childnum == 2)
			{
				maken(3);
			}

			else if(childnum == 6)
			{
				maken(2);
			}	
		}	
	}
	return 1;
}

/**
	int count = 0;
	int z = 0;
	int y = 0;
	for(int i = 0; i < 3; i++)
	{
		//Creates a child node and prints its parent id and id's
		if(fork() == 0)
		{
			printf("parentid = %d, myId = %d\n", getppid(), getpid());
			count++;

			//Checks to see whether the tree is on the last level
			if((count == 2) && (i == 0))
			{
				z = 1;
			}
			else
			{
				z = 0;
			}
			if((count == 2) && (i == 1))
			{
				y = 1;
			}
			else
			{
				y = 0;
			}

			if((count == 2) && (z == 1))
			{
				i = -1;
			}
			else if((count == 2) && (y == 1))
			{
				i = 0;
			}
			else if((count == 2) && ((z == 0)||(y == 0)))
			{
				i = 3;
			}	
			else if(count < 2)
			{
				i = 0;
			}
		}
		else
		{
			int status;
			waitpid(-1, &status, 0);
		}
	}
}
*/
