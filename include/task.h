#ifndef TASK_H
#define TASK_H

#include "config.h"
#include <string>
#include <map>

using namespace std;

/*
class PageNode
{
private:
	int va;
	int pa;
	PageNode* next;
};
*/

class TaskModule {
public:
    TaskModule(int id, const string& va, int size, int pa = -1);
    void task_test();
    static void createInstance(int id, const string& va, int size, int pa = -1);
    void updatePageTable(int id, int va, int pa);

    int getSize() const { return size; }
    int getId() const { return id; }
    int getPhysicalAddress() const { return pa; }


    int id;
    int size;
    string va;
    int pa;
    map<int, int> vaToPaMapping; // Map of Virtual Address to Physical Address
    static map<int, TaskModule*> taskInstances;
};

#endif // TASK_MODULE_H
