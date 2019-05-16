#include <stdio.h>
#include <stdlib.h>

struct lru
{
	int secchance;
	int page;
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
	struct lru *pageTable = (struct lru*) malloc(sizeof(int) *tableSize);
	char *input = NULL;
	size_t inputAllocated = 0;
	ssize_t bytesRead;

	for(int x = 0; x < tableSize; x++)
	{
		pageTable[x].secchance = 0;
	}

	while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1)
	{
		pageRequest = atoi(input); //Returns 0 on error
		if(pageRequest == 0) //Page 0 reserved for kernel
		{
			continue;
		}
		numRequest++;

		// Check to see if -1; if found, page fault
		if(!isInMemory(pageRequest, pageTable, tableSize))
		{
			printf("Page %d cause a page fault\n", pageRequest);
			if(pageTableIndex < tableSize)
			{
				pageTable[pageTableIndex++].page = pageRequest;
				pageTable[pageTableIndex++].secchance = 1;
				numRequest++;
			}
			else
			{	
				for(int j = 0; j < tableSize; j++)
				{
					if(pageTable[j].secchance == 1)
					{
						pageTable[j].secchance = 0;
					}
					else
					{
						pageTable[j].page = pageRequest;
					}	
				}
				//TODO implement a page replacement algorithm
				fprintf(stderr, "Ran out of memory. Implement a page replacement algorithm!\n");
			}		
		} // else probably want to update something in pageTable so that lru and second chance work correctly	
	}
	printf("Hit Rate = %f\n", (numRequest - numMisses) / (double) numRequest);

	free(input);
	free(pageTable);
	return 0;
}
