all:
	g++ -Wall -Wextra -o CNC.cpp cnc_test.cpp -lgtest -lpthread -std=c++11