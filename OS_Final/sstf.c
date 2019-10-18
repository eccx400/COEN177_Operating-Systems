#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <assert.h>

void sstf(int headPos, int queue[50], int queueElements)
{
	int min, seekTime = 0;
	int checkDis[50];
	
	int i;
	for( i = 0; i < queueElements; i++)
	{
		checkDis[i] = abs(headPos - queue[i]);
	}

	int x,y;
	for(x = 0; x < queueElements; x++)
	{
		for(y = 0; y < queueElements; y++)
		{
			if(checkDis[x] >  checkDis[y])
			{
				int temp = checkDis[x];
				checkDis[x] = checkDis[y];
				checkDis[y] = temp;
				temp = queue[x];
				queue[x] = queue[y];
				queue[y] = temp; 
			}
		}
	}
	
	int j;
	for(j = 1; j < queueElements - 1; j++)
	{
		seekTime += abs(headPos - queue[j]);
		headPos = queue[j];
	}
	printf("\nTotal Seek Time: %d", seekTime);
}

int main()
{
	int queue[50] = {60, 78, 142, 37, 80, 153, 177};
	int queueElements = 7;
	int headPos = 100;

	sstf(headPos, queue, queueElements);
}	
