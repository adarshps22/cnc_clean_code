all:
	g++ -Wall -Wextra -I ./interface -I ./include -I ./include/monitor-indicators -o cnc_test src/Cnc_monitor.cpp test/cnc_test.cpp -lgtest -lpthread -std=c++11
