all:
	g++ -Wall -Wextra -o CNC.cpp test/cnc_test.cpp -lgtest -lpthread -std=c++11
