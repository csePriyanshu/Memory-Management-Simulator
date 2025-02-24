#include "../include/task.h"
#include "../include/config.h"
#include "../include/performance.h"
#include <iostream>

using namespace std;

map<int, TaskModule*> TaskModule::taskInstances;

TaskModule::TaskModule(int id, const string& va, int size, int pa)
    : id(id), va(va), size(size), pa(pa) {}

void TaskModule::task_test() {
// debug...    cout << "TaskModule Test completed for Task ID: " << id << endl;
	for (const auto& pair : taskInstances)
	{
        	int key = pair.first;
	        TaskModule* task = pair.second;

        	// Assuming TaskModule has a method to print or describe its content
		cout << "Task ID: " << key << endl;
		cout << "Task: " << task->va << endl;
		cout << "Page Table : " << task->vaToPaMapping.size() << endl;
		cout<< "1st task: " << task->vaToPaMapping[key] << endl;
        	if (task)
	 	{
            		cout << "Task ID: " << key << endl;
		    cout << "Virtual Address: " << task->va << endl;
		    cout << "Page Table Size: " << task->vaToPaMapping.size() << endl;
		    if (!task->vaToPaMapping.empty()) {
		        cout << "First entry: VA " << task->vaToPaMapping.begin()->first
                     		<< " -> PA " << task->vaToPaMapping.begin()->second << endl;
                   }
        	}
		else
		{
            		cout << "TaskModule pointer is null" << std::endl;
        	}
    	}
}

void TaskModule::createInstance(int id, const string& va, int size, int pa) {
	cout<<"...Working..."<<endl;
    auto ti = taskInstances.find(id);
    int va_int = stoi(va, nullptr, 16);
    if (ti != taskInstances.end()) {  // checks if the task instance already exists
		//updating already existing instance
		//cout<<"yes\n";
		ti->second->vaToPaMapping[va_int] = pa;
		//return;
	//	cout << "Page Table Map " << ti->second->vaToPaMapping[va_int] << "belongs to va " << va << " in hex " << va_int << " in int TId:" << ti->second->id <<endl;
    } else{ // if ti doesn't exist then create a new instance and also update the instance map
        TaskModule* newTask = new TaskModule(id, va, size, pa);
        taskInstances[id] = newTask;
        
		//cout<<newTask->va <<" Id T\n";
		newTask->vaToPaMapping[va_int] = pa;
		ti = taskInstances.find(id);
    }
    ti = taskInstances.find(id);
    map<int, int> map = ti->second->vaToPaMapping;
    //cout<<map.size()<<" if T"<<endl;
	if (ti != taskInstances.end()) {
		// Use the PerformanceModule instance correctly
		PerformanceModule perMod;  // Pass the correct MemoryManager instance
		perMod.memoryAllocation(ti->second);

		// Output the virtual address for debugging
		//cout << ti->second->va << " VA T \n";
	} else {
		cerr << "Error: Task instance not found after creation.\n";
	}
}

void TaskModule::updatePageTable(int id, int va, int pa) {
	auto ti = taskInstances.find(id);
	if (ti != taskInstances.end()) {
        	ti->second->vaToPaMapping[va] = pa;
	} else {
   		cerr << "TaskModule with ID " << id << " not found." << endl;
	}
}
