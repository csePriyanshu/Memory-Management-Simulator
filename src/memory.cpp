#include "../include/memory.h"
#include "../include/task.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

MemoryManager::MemoryManager(int totalPages, TaskModule* taskModule)
    : totalPages(totalPages), taskModule(taskModule) {
    
    memory = new int[totalPages];
    cout<<"Our virtual RAM starting address (in hex): "<<memory<<endl;
    for (int i = 0; i < totalPages; ++i) {
        memory[i] = -1; // -1 indicates free page
    }
}
MemoryManager::MemoryManager(){}

/*
MemoryManager::~MemoryManager() {
    delete[] memory;
}
*/

int MemoryManager::fifo = 0;


int MemoryManager::allocatePages(int id, int virtualAddress) {
	/*for(int i=0; i<totalPages; i++){
		cout << memory[i] << ", ";
	}*/
	cout<<endl;
	for (int i=0; i<totalPages; i++)
	{
        	if(memory[i] == -1) // free memory space is available
		{
			//cout<<"yes"<<endl;
			memory[i] = id;
			taskModule->updatePageTable(id, virtualAddress, i);
			return i;
		}
    	}
	//cout<<"total page "<<totalPages <<endl;
	fifo = (fifo+1)%totalPages;
	//cout<<"fifo : "<<fifo;
	deallocatePages(fifo, 1);
	return -1;
}
void MemoryManager::deallocatePages(int startAddress, int numPages) {
    if (startAddress >= 0 && startAddress < totalPages) {
        memory[startAddress] = -1;
        cout << "MemoryManager: Deallocated " << numPages << " pages from address " << startAddress << "\n";
    } else {
        //cout << "MemoryManager: Invalid deallocation attempt at address " << startAddress << "\n";
    }
}
 
/*
void MemoryManager::deallocatePages(int startAddress, int numPages) {
     memory[startAddress] = -1; //TODO: write the code to update the page table
    cout << "MemoryManager: Deallocated " << numPages << " pages from address " << startAddress << "\n";
}
*/
void MemoryManager::swapPages(int startAddress, int numPages) {
    // Placeholder for page swapping logic (e.g., LRU replacement)
    cout << "MemoryManager: Swapped " << numPages << " pages starting from address " << startAddress << "\n";
}

void MemoryManager::reportStatus() {
    // Report memory status or statistics
}
