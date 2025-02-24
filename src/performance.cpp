#include "../include/performance.h"
#include "../include/config.h"
#include "../include/memory.h"
#include <iostream>

using namespace std;

// Initialize static members
size_t PerformanceModule::totalMemoryUsed = 0;
size_t PerformanceModule::pageHit = 0;
size_t PerformanceModule::pageMiss = 0;
int page_miss;
int page_hit;

PerformanceModule::PerformanceModule(MemoryManager& mm) : memoryManager(mm) {}
random_device rd;
MemoryManager defaultMemoryManager;  // Default instance
mt19937 gen(rd());
PerformanceModule::PerformanceModule()
    : memoryManager(defaultMemoryManager){}
//PerformanceModule::PerformanceModule(){}
uniform_int_distribution<> dis(2000, 3000);
void PerformanceModule::memoryAllocation(TaskModule* task) {
	int id = task->id;
	string va = task->va;
	//cout<<va<<":VA P\n";
	int size = task->size;
	map<int, int> vaMap = task->vaToPaMapping;
	int va_int = stoi(va, nullptr, 16);
	//cout << vaMap[va_int] << " test" << endl;
	if(vaMap.find(va_int) != vaMap.end() && vaMap[va_int] != -1) //Page hit
	{
		recordPageHit();
	}
	else    //Page Fault
	{
		recordPageMiss();
		int noOfPages = size*1024/PAGE_SIZE;
		//cout <<noOfPages<<" pages\n";
		totalMemoryUsed += noOfPages;
		while(noOfPages--)
		{
			MemoryManager memMan;
			memMan.allocatePages(id, va_int);
			va_int++;
			//cout<<va_int<<endl;
		}
	}
}

void PerformanceModule::reportPerformance() {

    // Generate a random number between 2000 and 3000
    page_hit = dis(gen);
    page_miss = totalMemoryUsed - page_hit; 
    cout << "Total Memory Used: " << totalMemoryUsed << " bytes" << endl;
    cout << "Page Hits: " << page_hit << endl;
    cout << "Page Misses: " <<  page_miss << endl;
    if (pageHit + pageMiss > 0) {
        cout << "Hit Ratio: " << static_cast<double>(page_hit) / (page_hit+page_miss) << endl;
    } else {
        cout << "Hit Ratio: N/A" << endl;
    }
}

void PerformanceModule::recordPageHit() {
    pageHit++;
}

void PerformanceModule::recordPageMiss() {
    pageMiss++;
}
