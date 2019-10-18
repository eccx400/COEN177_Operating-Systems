#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <algorithm>

using namespace std;

void pop (int temp, int * pageTable, int tableSize)
{
	for(int i = temp; i < tableSize; i++)
	{
		swap(pageTable[i], pageTable[i+1]);
	}
}

int parseArguments(int argc, char * argv[])
{
	int tableSize;
	if(argc == 2 && (tableSize = atoi(argv[1])))
	{
		// validate negative input
		return tableSize;
	}
	cerr << "Wrong arguments. Pass tableSize as an argument" << endl;
	exit(-1);
}

int isInMemory(int pageRequest, int *pageTable, int tableSize)
{
	int i;
	for(i = 0; i < tableSize; i++)
	{
		if(pageRequest == pageTable[i])
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
	int *pageTable = new int [tableSize];
	char *input = NULL;
	size_t inputAllocated = 0;
	ssize_t bytesRead;
	int index;

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
			if(pageTableIndex < tableSize)
			{
				pageTable[pageTableIndex++] = pageRequest;
				cout << "Page number " << pageRequest << " caused a page fault." << endl;
				numMisses++;
			}
			else
			{
				pop(index, pageTable, tableSize);
				if(index == pageTableIndex)
				{
					index = 0;
				}	
				pageTable[index++ % tableSize] = pageRequest;
				numMisses++;
				cout << "Page number " << pageRequest << "cause a page fault." << endl;
			//fprintf(stderr, "Ran out of memory. Implement a page replacement algorithm!\n");
			}		
		} // else probably want to update something in pageTable so that lru and second chance work correctly	
	}
	//printf("Hit Rate = %f\n", (numRequest - numMisses) / (double) numRequest);

	cout << "Number of page faults: " << numMisses << endl;
	delete input;
	delete pageTable;
	return 0;
}
