#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

void fcfs(int headPos, int queue[50], int queueElements)
{
	int seekTime = 0;
	int i;
	for( i = 0; i < queueElements; i++)
	{
		seekTime += abs(headPos - queue[i]);
		headPos = queue[i];
	}
	printf("\n Total Seek Time:%d",seekTime);
}

int main()
{
	int headPos = 100;
	int queueElements = 7;
	int queue[50] = {60, 78, 142, 37, 80, 153, 177};

	fcfs(headPos, queue, queueElements);
}
