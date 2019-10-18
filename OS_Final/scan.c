#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void scan(int headPos, int queue[50], int queueElements)
{
	int seekTime = 0;

	int i, j;
	for(i = 0; i < queueElements; i++)
	{
		if(headPos < queue[i])
		{
			for(j = i - 1; j >= 0; j--)
			{
				seekTime += abs(headPos - queue[j]);
				headPos = queue[j];
			}
			seekTime += abs(headPos - 0);
			headPos = 0;			

			for(j = 1; j < queueElements; j++)
			{
				seekTime += abs(headPos - queue[j]);
				headPos = queue[j];
			}
			break;
		}
	}
	printf("\n Total Seek Time: %d", seekTime);
}

int main()
{
	int queue[50] = {60, 78, 142, 37, 80, 153, 177};
	int queueElements = 7;
	int headPos = 100;
	
	int i, j, temp;
	for(i = 0; i < queueElements; i++)
	{
		for(j = 0; j < queueElements; j++)
		{
			if(queue[i] > queue[j])
			{
				temp = queue[i];
				queue[i] = queue[j];
				queue[j] = temp;
			}
		}
	}
	scan(headPos, queue, queueElements);	
}
