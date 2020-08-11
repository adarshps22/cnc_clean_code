all:
	g++ -Wall -Wextra -o cnc_test CNC.cpp test/cnc_test.cpp -lgtest -lpthread -std=c++11
