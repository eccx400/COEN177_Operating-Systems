#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <algorithm>

using namespace std;

int parseArguments(int argc , char * argv[])
{
	int tableSize;
	if( argc == 2 && (tableSize = atoi(argv[1])))
	{
		return tableSize;
	}
	cerr << "Wrong Arguments. Pass tableSize as argument" << endl;
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

int main(int argc, char * argv[]) 
{	
        int tableSize = parseArguments(argc, argv);
        int pageRequest, pageTableIndex = 0, numRequests = 0, numMisses = 0;
        int *pageTable = new int[tableSize];
        char *input = NULL;
	size_t inputAllocated = 0;
	ssize_t bytesRead;
	int index = 0;
	int dum = 0;
        
	while((bytesRead = getline(&input, &inputAllocated, stdin)) != -1)
	{
                pageRequest = atoi(input);
		if(pageRequest == 0)
		{
			continue;
		}
		numRequests++;
                if(!isInMemory(pageRequest, pageTable, tableSize))
		{
                        if(pageTableIndex < tableSize) 
			{
                                pageTable[pageTableIndex++] = pageRequest;       
                        	cout << "Page number " <<  pageRequest <<  " caused a page fault." << endl;
				numMisses++;	
			}
                        else 
			{
				if(index == pageTableIndex)
				{
					index = 0;
				}
				pageTable[index++] = pageRequest;
				numMisses++;
				if (pageRequest == 0)
				{
					dum++;
				}
				cout << "Page number " << pageRequest << " cause a page fault." << endl;
                                //fprintf(stderr, "Ran out of memory! Implement a page replacement alg.\n");
                        }
                }
		if (dum == 1)
		{
			break;
		}
        }

        delete input;
        delete pageTable;

	cout << "Number of page requests = " << numRequests << endl;
	cout << "Number of page faults = " << numMisses << endl;
	//cout << "Hit Rate = " << (numRequests - numMisses)/(double) numRequests << endl;
        return 0;
}

