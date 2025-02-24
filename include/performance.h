#ifndef PERFORMANCE_H
#define PERFORMANCE_H

#include "config.h"
#include "../include/task.h"
#include "../include/memory.h"

class PerformanceModule {
public:
    static size_t totalMemoryUsed;
    static size_t pageHit;
    static size_t pageMiss;
    MemoryManager& memoryManager;

public:
    PerformanceModule();
    PerformanceModule(MemoryManager& mm);
    void memoryAllocation(TaskModule* task);
    void reportPerformance();
    void recordPageHit();
    void recordPageMiss();
};

#endif // PERFORMANCE_MODULE_H
