#include "../include/io.h"
#include"../include/config.h"
#include <cerrno>   // For errno
#include <cstring>  // For strerror


// Convert size from MB/GB to KB
int IOModule::convertSizeToKB(const string& sizeStr) {
    if (sizeStr.find("MB") != string::npos) {
        return stoi(sizeStr.substr(0, sizeStr.size() - 2)) * 1024;
    } else if (sizeStr.find("GB") != string::npos) {
        return stoi(sizeStr.substr(0, sizeStr.size() - 2)) * 1024 * 1024;
    } else if (sizeStr.find("KB") != string::npos) {
        return stoi(sizeStr.substr(0, sizeStr.size() - 2));
    } else {
        return stoi(sizeStr); // Assume it's already in KB
    }
}

void IOModule::read_file(string &filename) {
    ifstream file(filename);

   if (!file.is_open()) {
	cerr << "Error opening file: " << filename << endl;
	perror("File opening error");  // This will print the error message
        cerr << "Error code: " << errno << " (" << strerror(errno) << ")" << endl;
        return;
    }

    string line;
    while (getline(file, line)) {

        istringstream iss(line);
        string taskId, va, size; // va - Virtual Address

        getline(iss, taskId, ':');
        getline(iss, va, ':');
        getline(iss, size);

        if (taskId.empty() || va.empty() || size.empty()) {
            cerr << "Error parsing trace file line: " << line << endl;
            continue;
        }

        int tId = stoi(taskId.substr(1), nullptr, 10);

	// removing the page offset bits from the va
	int page_bit = log2(PAGE_SIZE);
	int page_hex = page_bit/4;
	string va_hex = va.substr(2, va.size() - (page_hex+2));
        // Convert virtual address from hex to integer
        int va_int = stoi(va_hex, nullptr, 16);

        // Convert size to KB
        int tSize = convertSizeToKB(size);

		//cout<<va_hex<<" VA IO \n";
        // Create a TaskModule instance
        TaskModule::createInstance(tId, va_hex, tSize, -1);
       //task->task_test();
    }
}
