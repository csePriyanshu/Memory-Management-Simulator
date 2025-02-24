#include "../include/task.h"
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
                cout << "Task: " << task << endl;
                if (task)
                {
                        // Replace with an appropriate method if TaskModule has a description or print method
                        // Example method to show task details
                }
                else
                {
                        cout << "TaskModule pointer is null" << std::endl;
                }
        }
}

TaskModule* TaskModule::createInstance(int id, const string& va, int size, int pa) {
    auto ti = taskInstances.find(id);
    if (ti != taskInstances.end()) {  // checks if the task instance already exists
        return ti->second;  // if ti exists, return the second element of our map i.e. pointer to TaskModule  [map<int, TaskModule*>]
    } else { // if ti doesn't exist then create a new instance and also update the instance map
        TaskModule* newTask = new TaskModule(id, va, size, pa);  //TODO: tweak it a little bit
        taskInstances[id] = newTask;
        return newTask;
    }
}

void TaskModule::updatePageTable(int virtualAddress, int physicalAddress) {
    //TODO: Update page table logic here
}
