all:
	g++ -Wall -Wextra -o cnc_test src/Cnc_monitor.cpp test/cnc_test.cpp -I/interface -I/include -I/include/monitor-indicators -lgtest -lpthread -std=c++11
