#include <iostream>
#include <fstream>
#include <string>
#include "../include/io.h"
#include "../include/memory.h"
#include "../include/performance.h"
#include "../include/task.h"
#include "../include/config.h" // Include the config file

using namespace std;

int main() {
    // Initialize the TaskModule and MemoryManager instances
    TaskModule* taskModule = nullptr;  // Placeholder for task module instance
    int totalPages = static_cast<int>(PM_SIZE / PAGE_SIZE);
    cout<< "Total Memory Pages = " << totalPages <<endl;
    MemoryManager memoryManager(totalPages, taskModule);
    PerformanceModule performanceModule(memoryManager);

    // Reading the trace file
    IOModule io;
    string filename = "src/trace2.txt";
    io.read_file(filename);

    // Optionally report performance
    performanceModule.reportPerformance();
    
    
    delete taskModule; // TaskModule needs to be cleaned up

    return 0;
}

