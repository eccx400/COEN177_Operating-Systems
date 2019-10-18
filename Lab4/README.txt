In this lab, we have to simulate page replacement algorithms and to assess the
capabilities and performances of each of the algorithms. We will simulate the
algorithms and record the amount of page faults that are existent. Then we will
use the page faults to try to calculate the hit rates and analyze them. 

FIFO Algorithm (First in First Out):

To implement the FIFO algorithm, I kept a list of the index for the first element
of the pageTableIndex, and checked to see if the page is already in the pageTable.
If it is, then we have to replace it. We put the pageRequest into the the pageTable
at that index, and then increment the amount of pageFaults.

LRU Algorithm:

For LRU, we have to keep track of the time for use of the least recently used pages,
thus it is easier to use a struct to keep track of the pages and the amount of time
used. By creating a struct we can then have the pageTable containing pages and the
space for the amount of time that they are used. The time itself is incremented in
the main, where we increment for each getline call in the while loop. We then have
a variable min_Time and minIndex to associate with the first page of the pageTable.
We then loop through to compare it to the used times for the other pages in the
pageTable. If there are pages that are less used, then we replace them with the 
first page.

Second Chance Algorithm:

For the second chance algorithm, I implemented it by adding a second chance variable
to the struct. This was the same struct from LRU, however, we have to keep track
of the pages that have not been accessed yet. That is why the values of the 
second chance variable is defaulted at zero. We then traverse through the page table,
and each time a memory frame is referenced, we set the second chance variable to one
to allow to get a second chance. If the inserted page is new, we set the second chance
value to 0. We then loop through the pageTable to see the values of the secchance so
we can see if we need to replace the pages. If the value of the secchance is 1, then
we set it to zero and continue, else we replace the page with pageRequest.
