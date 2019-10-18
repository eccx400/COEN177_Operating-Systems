#include <stdio.h>
#include <stdlib.h>

struct lru
{
	int page;
	int time; 
};

int parseArguments(int argc, char * argv[])
{
	int tableSize;
	if(argc == 2 && tableSize == atoi(argv[1]))
	{
		// validate negative input
		return tableSize;
	}
	fprintf(stderr, "Wrong arguments. Pass tableSize as an argument\n");
	exit(-1);
}

int isInMemory(int pageRequest, struct lru *pageTable, int tableSize)
{
	int i;
	for(i = 0; i < tableSize; i++)
	{
		if(pageRequest == pageTable[i].page)
		{
			return 1;
		}
	}	
	return 0;
}

int main (int argc, char * argv[])
{
	int tableSize = parseArguments(argc, argv);
	int pageRequest, pageTableIndex = 0, numRequest = 0, numMisses = 0;
	struct lru *pageTable = (struct lru) malloc(sizeof(int) *tableSize);
	char *input = NULL;;
	int time = 0;
	size_t inputAllocated = 0;
	ssize_t bytesRead;

	while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1)
	{
		time++;
		pageRequest = atoi(input); //Returns 0 on error
		if(pageRequest == 0) //Page 0 reserved for kernel
		{
			continue;
		}
		numRequest++;

		// Check to see  aif -1; if found a, page fault
		if(!isInMemory(pageRequest, pageTable, tableSize))
		{
			int min_time = pageTable[0].time;
			int min_Index = 0;
			for(int i = 0; i < tableSize; i++)
			{
				if(pageTable[i].time < min_time)
				{
					min_time = pageTable[i].time;
					min_Index = i;
				}
			}
			pageTable[min_Index].page = pageRequest;
			pageTable[min_time].time = time;

			printf("Page %d cause a page fault\n", pageRequest);
			numMisses++;
			if(pageTableIndex < tableSize)
			{
				pageTable[pageTableIndex++].page = pageRequest;
			}
			else
			{
				//TODO implement a page replacement algorithm
				
		 		fprintf(stderr, "Ran out of memory. Implement a page replacement algorithm!\n");
			}		
		}
		else
		{
			for(int j = 0; j < tableSize; j++)
			{
				if((pageTable[j].page == pageRequest))
				{
					pageTable[j].time = time;
				}
			}
		}
	}	
	printf("Hit Rate = %f\n", (numRequest - numMisses) / (double) numRequest);

	free(input);
	free(pageTable);
	return 0;
}
