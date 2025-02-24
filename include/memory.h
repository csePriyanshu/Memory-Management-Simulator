#ifndef MEMORY_H
#define MEMORY_H

#include<bits/stdc++.h>
#include "config.h"
#include"task.h"

class TaskModule;

class MemoryManager {
private:
    int totalPages;
    int* memory; // Array to simulate physical memory
    std::list<int> lruQueue; // LRU queue for page replacement
    TaskModule* taskModule; // Pointer to TaskModule
    static int fifo;

public:
    MemoryManager();
    MemoryManager(int totalPages, TaskModule* taskModule);
    //~MemoryManager();
    int allocatePages(int id, int virtualAddress);
    void deallocatePages(int startAddress, int numPages);
    void swapPages(int startAddress, int numPages);
    void reportStatus();
};

#endif // MEMORY_MANAGER_H
