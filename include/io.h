#ifndef IO_H
#define IO_H

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cmath>
#include "../include/task.h"

using namespace std;

class IOModule {
public:
    void read_file(string &filename);

private:
    int convertSizeToKB(const string& sizeStr);
};

#endif // IO_MODULE_H
