compile:
	@g++ -std=c++11 -I include/ -o my_program src/task.cpp src/performance.cpp src/memory.cpp src/io.cpp src/main.cpp
run:
	@./my_program
